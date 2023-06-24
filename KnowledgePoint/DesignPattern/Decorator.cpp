/*
@Project ��cppReview 
@File ��Decorator.c
@Author ��HuntingGame
@Date ��2023-06-15 8:13 
C'est la vie!!! enjoy ur day :D
 װ��ģʽ
*/


#include<iostream>
using namespace std;
//TODO �������Ӧ�����кܴ������ġ�
class Component{
public:
    virtual void Operation(){cout<<"����������Ĳ������Ҵ�����һ������";};
    virtual ~Component(){};

};


class ConcreteComponent: public Component{
public:
    ConcreteComponent(){
        cout <<"��ֻ��Component��һ��ʵ�֣�" << endl;
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
    string addedState="����ConcreteComponentA,��Ϊ����������˱߽��";
};


class ConcreteComponentB:public Decorator{
public:
    void Operation(){
        Decorator::Operation();
        cout <<AddedBehavior << endl;
    }
private:
    string AddedBehavior="����ConcreteComponentB,��Ϊ�������������ɫ��";
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
