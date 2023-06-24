/*
@Project ：cppReview 
@File ：Proxy.c
@Author ：HuntingGame
@Date ：2023-06-15 8:46 
C'est la vie!!! enjoy ur day :D
*/


#include<iostream>
using namespace std;

class Subject{
public:
    virtual void Request() = 0;
    virtual ~Subject(){};
};

class RealSubject:public Subject{
public:
    void Request() override{
        cout <<"真实的请求!" << endl;
    }
};

class Proxy:public Subject{
public:
    RealSubject *realSubject;
    void Request() override{
        if (realSubject == nullptr){
            realSubject = new RealSubject();
        }
        realSubject->Request();
    }
};

int main() {
    Proxy *proxy = new Proxy();
    proxy->Request();
    system("pause");
    return 0;
}
