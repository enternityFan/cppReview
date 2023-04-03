/*
@Project ��cppReview 
@File ��Singleton.c
@Author ��HuntingGame
@Date ��2023-04-03 14:53 
C'est la vie!!! enjoy ur day :D
*/


#include<iostream>
#include <bits/shared_ptr.h>
#include <mutex>

using namespace std;

class Singleton1
{
    // ����ģʽ���̰߳�ȫ�İ汾
public:
    ~Singleton1(){
        cout <<"��������ִ��" << endl;

    }
    Singleton1(Singleton1&)=delete;
    Singleton1& operator=(const Singleton1&)=delete;

    // ����ʵ����
    static shared_ptr<Singleton1> getInstance(){

        if (m_pInstance == nullptr){
            lock_guard<mutex> lk(m_mutex);
            if(m_pInstance == nullptr){
                m_pInstance = shared_ptr<Singleton1>(new Singleton1);
            }
        }
        return m_pInstance;
    }
private:
    Singleton1(){
        cout <<"���캯����������" << endl;
    }
    static shared_ptr<Singleton1> m_pInstance;
    static  mutex m_mutex;
};

// �����ʼ����̬����
shared_ptr<Singleton1> Singleton1::m_pInstance= nullptr;
mutex Singleton1::m_mutex;


class Singleton2
{
    // ����ģʽ����ʹ������ָ�룬����򵥣����þֲ���̬����ʵ��
public:
    ~Singleton2(){
        cout <<"destructor called!" << endl;

    }
    Singleton2(const Singleton2 &) = delete;
    Singleton2& operator=(const Singleton2&)=delete;
    static Singleton2& getInstance(){
        static Singleton2 m_pInstance;
        return m_pInstance;
    }

private:
    Singleton2(){
        cout << "constructor called!" << endl;
    }
};



int main() {
    shared_ptr<Singleton1> p1 = Singleton1::getInstance();
    shared_ptr<Singleton1> p2 = Singleton1::getInstance();
    Singleton2& p3 = Singleton2::getInstance();
    Singleton2& p4 = Singleton2::getInstance();


    system("pause");
    return 0;
}
