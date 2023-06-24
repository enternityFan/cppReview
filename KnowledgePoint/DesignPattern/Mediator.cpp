/*
@Project ��cppReview 
@File ��Mediator.c
@Author ��HuntingGame
@Date ��2023-06-18 19:11 
C'est la vie!!! enjoy ur day :D
*/


#include <iostream>
using namespace std;
//�н���ģʽ


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

//���
class Tenant: public Person
{
public:
    Tenant(Mediator* mediator): Person(mediator){}

    // ������Ϣ
    virtual void sendMessage(string message){
        m_mediator->sendMessage(message,this);
    }
    virtual void getMessage(string message){
        cout <<"the Tenant get message: " << message << endl;
    }

};

// ����
class Landlord: public Person
{
public:
    // ���캯��
    Landlord(Mediator* mediator): Person(mediator){}
    // ������Ϣ
    virtual void sendMessage(string message){
        m_mediator->sendMessage(message,this);
    }
    // ��ȡ��Ϣ
    virtual void getMessage(string message){
        cout <<"the landlord get message: " << message << endl;
    }




};

// �����н���----���ز��н�
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
    // ������Ϣ
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
