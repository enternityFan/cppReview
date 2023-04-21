#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <chrono>
#include <queue>
#include <mutex>
#include <condition_variable>

using namespace std;

// 定义任务结构体，包含文件名和复制的目标路径
struct Task
{
    string file_path;
    string dest_path;
    int start_pos;
    int end_pos;
};

// 定义线程池类
class ThreadPool
{
public:
    // 构造函数，初始化线程池
    ThreadPool(int n) : stop(false)
    {
        for (int i = 0; i < n; ++i)
        {
            // 创建 n 个线程，并将线程函数指针指向 worker
            workers.emplace_back([this] {
                while (true)
                {
                    // 从任务队列中取出任务并执行
                    unique_lock<mutex> lock(this->queue_mutex);
                    this->condition.wait(lock,
                                         [this] { return this->stop || !this->tasks.empty(); });
                    if (this->stop && this->tasks.empty())
                    {
                        return;
                    }
                    auto task = move(this->tasks.front());
                    this->tasks.pop();
                    lock.unlock();
                    // 执行任务
                    copy_file(task.file_path, task.dest_path, task.start_pos, task.end_pos);
                }
            });
        }
    }

    // 析构函数，停止线程池并等待所有线程结束
    ~ThreadPool()
    {
        {
            unique_lock<mutex> lock(queue_mutex);
            stop = true;
        }
        condition.notify_all();
        for (thread &worker : workers)
        {
            worker.join();
        }
    }

    // 添加任务到队列中
    void enqueue(Task task)
    {
        unique_lock<mutex> lock(queue_mutex);
        tasks.push(move(task));
        lock.unlock();
        condition.notify_one();
    }

private:
    // 线程池中的线程数量
    vector<thread> workers;
    // 任务队列
    queue<Task> tasks;
    // 互斥锁和条件变量
    mutex queue_mutex;
    condition_variable condition;
    // 线程池是否停止的标志
    bool stop;

    // 文件复制操作
    void copy_file(string src_path, string dest_path, int start_pos, int end_pos)
    {
        ifstream src_file(src_path, ios::binary);
        ofstream dest_file(dest_path, ios::binary | ios::app);
        if (!src_file || !dest_file)
        {
            cerr << "Error opening file" << endl;
            return;
        }

        // 设置读取位置和缓冲区大小
        int buffer_size = 1024 * 1024;  // 1MB
        char buffer[buffer_size];
        src_file.seekg(start_pos);

        // 读取并写入数据
        int bytes_read = 0;
        while (start_pos < end_pos && (bytes_read = src_file.readsome(buffer, buffer_size)))
        {
            dest_file.write(buffer, bytes_read);
            start_pos += bytes_read;
        }

        // 关闭文件
        src_file.close();
        dest_file.close();
    }
};

int main()
{
    // 源文件路径和目标文件路径
    string src_path = "./testCopy.zip";
    string dest_path = "./testCopy2.zip";

    // 打开源文件并获取文件大小
    ifstream src_file(src_path, ios::binary | ios::ate);
    if (!src_file)
    {
        cerr << "Error opening file" << endl;
        return 1;
    }
    int file_size = src_file.tellg();
    src_file.close();

    // 计算每个线程处理的数据范围
    int num_threads = 4;
    int chunk_size = file_size / num_threads;
    int last_chunk_size = file_size - chunk_size * (num_threads - 1);

    // 创建线程池并添加任务到队列中
    ThreadPool pool(num_threads);
    auto start_time = chrono::high_resolution_clock::now();
    for (int i = 0; i < num_threads; ++i)
    {
        int start_pos = i * chunk_size;
        int end_pos =