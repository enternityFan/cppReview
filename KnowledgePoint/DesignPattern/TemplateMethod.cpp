/*
@Project ：cppReview 
@File ：TemplateMethod.c
@Author ：HuntingGame
@Date ：2023-06-18 9:37 
C'est la vie!!! enjoy ur day :D
*/

// 模板方法模式
#include<iostream>
using namespace std;

class AbstractClass{
public:
    virtual ~AbstractClass(){};
    virtual void primitiveOperation1()=0;
    virtual void primitiveOperation2()=0;
     void TemplateMethod(){
         primitiveOperation1();
         primitiveOperation2();
         cout <<endl;

    }
};

class ConcreteClassA:public AbstractClass{
public:
    virtual void primitiveOperation1(){
        cout <<"ConcreteClassA's op1"<<endl;
    }
    virtual void primitiveOperation2(){
        cout <<"ConcreteClassA's op2"<<endl;
    }
};
class ConcreteClassB:public AbstractClass{
public:
    virtual void primitiveOperation1(){
        cout <<"ConcreteClassB's op1"<<endl;
    }
    virtual void primitiveOperation2(){
        cout <<"ConcreteClassB's op2"<<endl;
    }
};
int main() {
    AbstractClass *a;
    a = new ConcreteClassA();

    a->TemplateMethod();
    a = new ConcreteClassB();
    a->TemplateMethod();
    system("pause");
    return 0;
}
