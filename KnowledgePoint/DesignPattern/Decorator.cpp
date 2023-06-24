/*
@Project ：cppReview 
@File ：Decorator.c
@Author ：HuntingGame
@Date ：2023-06-15 8:13 
C'est la vie!!! enjoy ur day :D
 装饰模式
*/


#include<iostream>
using namespace std;
//TODO 这个代码应该是有很大的问题的。
class Component{
public:
    virtual void Operation(){cout<<"我是最基础的操作，我创建了一个箱子";};
    virtual ~Component(){};

};


class ConcreteComponent: public Component{
public:
    ConcreteComponent(){
        cout <<"我只是Component的一个实现！" << endl;
    }

};

class Decorator:public Component{
public:
    void Operation() override{
        if (this->pComponent != nullptr){
            this->pComponent->Operation();

        }

    };
public:
    void SetComponent(Component *component){
        this->pComponent = component;
    }
private:
    Component* pComponent;
};


class ConcreteComponentA:public Decorator{
public:
    void Operation(){
        Decorator::Operation();

        cout <<addedState << endl;

    }
private:
    string addedState="我是ConcreteComponentA,我为正方体添加了边界框！";
};


class ConcreteComponentB:public Decorator{
public:
    void Operation(){
        Decorator::Operation();
        cout <<AddedBehavior << endl;
    }
private:
    string AddedBehavior="我是ConcreteComponentB,我为正方体添加了颜色！";
};


int main() {
    ConcreteComponent* c = new ConcreteComponent();
    ConcreteComponentA* d1 = new ConcreteComponentA();
    ConcreteComponentB* d2 = new ConcreteComponentB();
    d1->SetComponent(c);
    d2->SetComponent(d1);
    d2->Operation();
    system("pause");
    return 0;
}
