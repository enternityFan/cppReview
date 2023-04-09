/*
@Project ��cppReview 
@File ��copy_withThreads.c
@Author ��HuntingGame
@Date ��2023-04-03 21:38 
C'est la vie!!! enjoy ur day :D
*/

/*
 * ���ö��߳�ʵ���ļ��ĸ��Ʋ�����
 * ���������������ܶ��ģ�
 * v0.1:���ö��߳�ʵ�ֶ��ļ��Ĳ�����ע����Ҫ�������������ƴ�ӡ˳��
 * v0.2:���ù̶������Ķ��߳�ʵ���ļ��Ŀ����Ĳ���
 * v0.3:�����̳߳���ʵ���ļ��Ŀ����Ĳ���
 */
#include<iostream>
#include <string>
#include <vector>
#include <thread>
#include <fstream>
#include "time.h"
#define WRITE_FILE 0
using namespace std;


struct tfnArg{

    long spos; // ��ʼλ��
    long epos; // ����λ��

};

class MyCopy
{

public:
    MyCopy();
    ~MyCopy()=default;
    void setOriginal_path(string path);
    void setTarget_path(string path);
    void testcp1(); // ��ԭʼ�ĸ��Ʋ���
    void testcp2(); // �����̼߳��ٰ��
    void testcp3(int thread_num); // ���̼߳��ٰ��
    //void testcp4(); // �̳߳ذ汾��
    bool isHaveOutput();
    void getSize();
    void* tfn(void* arg); // �������̵߳��õ�
    void createTarget();

private:
    string original_path = "./testCopy.zip";
    string target_path = "./testCopy2.zip";
    long mSize = 0;

};

void MyCopy::setOriginal_path(string path) {
    original_path = path;
}

void MyCopy::setTarget_path(string path) {
    target_path = path;
}
bool MyCopy::isHaveOutput() {
    // �����������ļ�����ɾ��
    std::ifstream file(target_path);
    if (file) {
        // �ļ����ڣ�ɾ����
        file.close();
        int ret = std::remove(target_path.c_str());
        cout <<"ret = " << ret << endl;
        if ( ret == 0) {
            std::cout << "File deleted successfully.\n";
        } else {
            std::cout << "Error deleting file.\n";
            return false;
        }
    }
    return true;

}

void MyCopy::getSize() {
    std::ifstream file(original_path, std::ios::binary | std::ios::ate);
    std::streamsize size = file.tellg();
    file.close();

    std::cout << "File size: " << size << " bytes\n";
    mSize = size;
    return;

}
MyCopy::MyCopy() {

    getSize();
    cout <<"Init myCopy success!" << endl;
}

void MyCopy::createTarget() {
    // ����Ŀ���ļ�
    std::ofstream dest(target_path, std::ios::binary);
    dest.seekp(mSize - 1);
    dest.put('\0');
    dest.close();

}



void *MyCopy::tfn(void *arg) {
    tfnArg *msg = (tfnArg *)arg;
    long startPos = msg->spos;
    long endPos = msg->epos;
    cout <<"startPos: " << startPos << endl;
    cout <<"endPos: " << endPos << endl;

    std::ifstream source(original_path, std::ios::binary);
    std::ofstream dest(target_path, std::ios::binary | std::ios::in | std::ios::out);

    source.seekg(startPos);
    dest.seekp(startPos);

    const std::size_t bufferSize = 4096;
    std::vector<char> buffer(bufferSize);

    while (source && source.tellg() < endPos) {
        source.read(buffer.data(), bufferSize);
        dest.write(buffer.data(), source.gcount());
    }

    source.close();
    dest.close();
}

void MyCopy::testcp1() {
    if(isHaveOutput()==false)cout <<"delete output error!\n" << endl;
    cout <<"Here is the first test, using the most primitive method to realize the copy operation~!" << endl;
    cout <<"Copying....." << endl;
    // ��ȡ��ʼʱ��
    auto start = std::chrono::high_resolution_clock::now();

    std::ifstream source(original_path, std::ios::binary);
    std::ofstream dest(target_path, std::ios::binary );


    dest << source.rdbuf();

    source.close();
    dest.close();

    std::cout << "File copied successfully.\n";

    // ��ȡ����ʱ��
    auto finish = std::chrono::high_resolution_clock::now();
    // ���㲢���ִ��ʱ��
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";
}

void MyCopy::testcp2() {
    if(isHaveOutput()==false)cout <<"delete output error!\n" << endl;
    cout <<"Here is the first test, Replication using two threads~!" << endl;
    cout <<"Copying....." << endl;
    createTarget();
    // ��ȡ��ʼʱ��
    auto start = std::chrono::high_resolution_clock::now();


// ����ÿ���̸߳��Ƶ��ļ�����
    tfnArg argInfo[2];
    std::size_t partSize = mSize / 2;
    argInfo[0].spos = 0;
    argInfo[0].epos = argInfo[0].spos + partSize;
    argInfo[1].spos = argInfo[0].epos;
    argInfo[1].epos = mSize;

    // ���������̸߳����ļ�
    std::thread t1(&MyCopy::tfn, this,(void * )&argInfo[0]);
    std::thread t2(&MyCopy::tfn, this,(void * )&argInfo[1]);

    t1.join();
    t2.join();


    std::cout << "File copied successfully.\n";
    // ��ȡ����ʱ��
    auto finish = std::chrono::high_resolution_clock::now();
    // ���㲢���ִ��ʱ��
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";
}

void MyCopy::testcp3(int thread_num) {
    if(isHaveOutput()==false)cout <<"delete output error!\n" << endl;
    cout <<"Here is the first test, Copy using multithreading~!" << endl;
    cout <<"Copying....." << endl;
    createTarget();
    // ��ȡ��ʼʱ��
    auto start = std::chrono::high_resolution_clock::now();

    vector<thread> threads(thread_num);
    // ����ÿ���̸߳��Ƶ��ļ�����
    std::size_t partSize = mSize / thread_num;
    tfnArg argInfos[thread_num];
    for(int i=0;i<thread_num;++i){
        if (i==0)
            argInfos[i].spos=0;
        else
            argInfos[i].spos=argInfos[i-1].epos;
        if(i==thread_num-1)
            argInfos[i].epos=mSize;
        else
            argInfos[i].epos=argInfos[i].spos+partSize;
        threads[i] = thread(&MyCopy::tfn,this,(void *)&argInfos[i]);
        cout <<"thread " << i << "is working...." << endl;
    }


    for(auto &entry:threads)
        entry.join();
    std::cout << "File copied successfully.\n";
    // ��ȡ����ʱ��
    auto finish = std::chrono::high_resolution_clock::now();
    // ���㲢���ִ��ʱ��
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";
}



int main() {
    if (WRITE_FILE) {
        ofstream ofs;
        ofs.open("test.txt", ios::out);
        int times = 100;
        for (int i = 0; i < times; ++i) {
            cout << to_string(i) << "/" << to_string(times) << endl;
            ofs << to_string(i) << endl;
        }
        ofs.close();
        cout << "write success!";
    }
    else{
//        ifstream ifs("test.txt");
//        unsigned long file_size = 0;
//        int f = ifs.tellg();
//        ifs.seekg(0,ios::end);
//        int l = ifs.tellg();
//        ifs.seekg(0,ios::end);
//        file_size = l - f;
//        cout <<"file size:" << file_size << endl;
        MyCopy mcp;
        cout <<"=============test1==================\n"<<endl;
        mcp.testcp1();
        cout <<"=============test2==================\n"<<endl;
        mcp.testcp2();
        cout <<"=============test3==================\n"<<endl;
        mcp.testcp3(8);
    }



    //system("pause");
    return 0;
}
