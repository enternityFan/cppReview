/*
@Project ��cppReview 
@File ��Adapter.c
@Author ��HuntingGame
@Date ��2023-06-18 15:23 
C'est la vie!!! enjoy ur day :D
*/


#include<iostream>
using namespace std;

class Target{
public:
    virtual void Request(){
        cout <<"normal request" << endl;
    }

};

class Adaptee{
public:
    void SpecificRequest(){
        cout <<"specific request" << endl;
    }
};

class Adapter : public Target{
private:
    Adaptee* adaptee = new Adaptee();
public:
    void Request() override{
        adaptee->SpecificRequest(); //ͨ�����ַ�ʽ�Ϳ��԰ѱ����ϵ���Request�������ʵ�ʵ���SpecificRequest��
    }

};


int main() {
    Target* target = new Adapter();
    target->Request();
    return 0;
}
