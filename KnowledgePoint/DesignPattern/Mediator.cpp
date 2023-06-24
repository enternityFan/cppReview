/*
@Project ：cppReview 
@File ：Mediator.c
@Author ：HuntingGame
@Date ：2023-06-18 19:11 
C'est la vie!!! enjoy ur day :D
*/


#include <iostream>
using namespace std;
//中介者模式


class Person;

class Mediator
{
public:
    virtual void sendMessage(string message,Person * colleague) = 0;
};

class Person
{
protected:
    Mediator* m_mediator;
public:
    Person(Mediator* mediator):m_mediator(mediator){}
    virtual void sendMessage(string message) = 0;
    virtual void getMessage(string message) = 0;
};

//租客
class Tenant: public Person
{
public:
    Tenant(Mediator* mediator): Person(mediator){}

    // 发出消息
    virtual void sendMessage(string message){
        m_mediator->sendMessage(message,this);
    }
    virtual void getMessage(string message){
        cout <<"the Tenant get message: " << message << endl;
    }

};

// 房东
class Landlord: public Person
{
public:
    // 构造函数
    Landlord(Mediator* mediator): Person(mediator){}
    // 发出消息
    virtual void sendMessage(string message){
        m_mediator->sendMessage(message,this);
    }
    // 获取消息
    virtual void getMessage(string message){
        cout <<"the landlord get message: " << message << endl;
    }




};

// 具体中介者----房地产中介
class RealEstateMediator : public Mediator
{
private:
    Person* m_tenant;
    Person* m_landlord;
public:
    void setTenant(Person* tenant){
        m_tenant = tenant;
    }
    void setLandlord(Person* landlord){
        m_landlord = landlord;
    }
    // 发出消息
    virtual void sendMessage(string message,Person* colleague){
        if(colleague == m_tenant){
            m_landlord->getMessage(message);
        } else{
            m_tenant->getMessage(message);
        }
    }
};







int main() {
    RealEstateMediator* mediator = new RealEstateMediator();
    Person* tenant = new Tenant(mediator);
    Person* landlord = new Landlord(mediator);

    mediator->setTenant(tenant);
    mediator->setLandlord(landlord);

    tenant->sendMessage("how much about rent?");
    landlord->sendMessage("3000 yuan.");

    return 0;
}
