#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <chrono>
#include <queue>
#include <mutex>
#include <condition_variable>

using namespace std;

// ��������ṹ�壬�����ļ����͸��Ƶ�Ŀ��·��
struct Task
{
    string file_path;
    string dest_path;
    int start_pos;
    int end_pos;
};

// �����̳߳���
class ThreadPool
{
public:
    // ���캯������ʼ���̳߳�
    ThreadPool(int n) : stop(false)
    {
        for (int i = 0; i < n; ++i)
        {
            // ���� n ���̣߳������̺߳���ָ��ָ�� worker
            workers.emplace_back([this] {
                while (true)
                {
                    // �����������ȡ������ִ��
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
                    // ִ������
                    copy_file(task.file_path, task.dest_path, task.start_pos, task.end_pos);
                }
            });
        }
    }

    // ����������ֹͣ�̳߳ز��ȴ������߳̽���
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

    // ������񵽶�����
    void enqueue(Task task)
    {
        unique_lock<mutex> lock(queue_mutex);
        tasks.push(move(task));
        lock.unlock();
        condition.notify_one();
    }

private:
    // �̳߳��е��߳�����
    vector<thread> workers;
    // �������
    queue<Task> tasks;
    // ����������������
    mutex queue_mutex;
    condition_variable condition;
    // �̳߳��Ƿ�ֹͣ�ı�־
    bool stop;

    // �ļ����Ʋ���
    void copy_file(string src_path, string dest_path, int start_pos, int end_pos)
    {
        ifstream src_file(src_path, ios::binary);
        ofstream dest_file(dest_path, ios::binary | ios::app);
        if (!src_file || !dest_file)
        {
            cerr << "Error opening file" << endl;
            return;
        }

        // ���ö�ȡλ�úͻ�������С
        int buffer_size = 1024 * 1024;  // 1MB
        char buffer[buffer_size];
        src_file.seekg(start_pos);

        // ��ȡ��д������
        int bytes_read = 0;
        while (start_pos < end_pos && (bytes_read = src_file.readsome(buffer, buffer_size)))
        {
            dest_file.write(buffer, bytes_read);
            start_pos += bytes_read;
        }

        // �ر��ļ�
        src_file.close();
        dest_file.close();
    }
};

int main()
{
    // Դ�ļ�·����Ŀ���ļ�·��
    string src_path = "./testCopy.zip";
    string dest_path = "./testCopy2.zip";

    // ��Դ�ļ�����ȡ�ļ���С
    ifstream src_file(src_path, ios::binary | ios::ate);
    if (!src_file)
    {
        cerr << "Error opening file" << endl;
        return 1;
    }
    int file_size = src_file.tellg();
    src_file.close();

    // ����ÿ���̴߳�������ݷ�Χ
    int num_threads = 4;
    int chunk_size = file_size / num_threads;
    int last_chunk_size = file_size - chunk_size * (num_threads - 1);

    // �����̳߳ز�������񵽶�����
    ThreadPool pool(num_threads);
    auto start_time = chrono::high_resolution_clock::now();
    for (int i = 0; i < num_threads; ++i)
    {
        int start_pos = i * chunk_size;
        int end_pos =