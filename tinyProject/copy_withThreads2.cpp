#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <chrono>

using namespace std;

// 定义线程函数
void copy_file(const string& src_path, const string& dest_path, int start_pos, int end_pos)
{
    // 打开源文件和目标文件
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

    // 创建线程并执行复制操作
    vector<thread> threads;
    auto start_time = chrono::high_resolution_clock::now();
    for (int i = 0; i < num_threads; ++i)
    {
        int start_pos = i * chunk_size;
        int end_pos = (i == num_threads - 1) ? file_size : (i + 1) * chunk_size;
        if (i == num_threads - 1)
        {
            end_pos = file_size;
        }
        threads.emplace_back(copy_file, src_path, dest_path, start_pos, end_pos);
    }

    // 等待所有线程执行完成
    for (auto& thread : threads)
    {
        thread.join();
    }

    // 输出执行时间
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;

    return 0;
}
