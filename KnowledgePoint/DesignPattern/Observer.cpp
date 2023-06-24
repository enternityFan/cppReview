/*
@Project ：cppReview 
@File ：Observer.c
@Author ：HuntingGame
@Date ：2023-06-18 10:13 
C'est la vie!!! enjoy ur day :D
*/


#include<iostream>
#include <list>

using namespace std;

class IObserver{
public:
    virtual ~IObserver(){};
    virtual void Update(const string &messageFromSubject) = 0;
};


class ISubject{
public:
    virtual ~ISubject(){};
    virtual void Attach(IObserver *observer) = 0;
    virtual void Detach(IObserver *observer) = 0;
    virtual void Notify() = 0;
};

class Subject:public ISubject{
public:
    list<IObserver *> _listObserver;
    string _message;
public:
    virtual ~Subject(){
        cout<<"Goodbye,i was the subject." << endl;
    }
    void Attach(IObserver* observer)override{
        _listObserver.push_back(observer);
    }
    void Detach(IObserver* observer) override{
        _listObserver.remove(observer);
    }
    void Notify() override{
        auto begin = _listObserver.begin();
        HowManyObserver();
        while(begin !=_listObserver.end()){
            (*begin)->Update(_message);
            ++begin;
        }
    }
    void CreateMessage(string message = "Empty"){
        this->_message = message;
        this->Notify();
    }

    void HowManyObserver()
    {
        cout << "There are " << _listObserver.size() << " observers in the list\n";
    }

    /*
    通常的来说，订阅逻辑知识主题真正能做的事情的一小部分。
    主题通常拥有一些重要的业务逻辑，每当重要的事情即将发生（或者发生之后）时触发通知方法。
    */
    void SomeBusinessLogic()
    {
        this->_message = "change message message";
        Notify();
        cout << "I'm about to do some thing important.\n";
    }





};

class Observer:public IObserver{
private:
    string _messageFromSubject;
    Subject &_subject;
    static int _staticNumber;
    int _number;
public:
    Observer(Subject & subject):_subject(subject){
        this->_subject.Attach(this);
        cout << "Hi,I'm the Observer \"" << ++Observer::_staticNumber << "\".\n";
        this->_number = Observer::_staticNumber;
    }
    ~Observer(){
        cout << "Goodbye,I was the Observer \"" << this->_number << "\".\n";
    }
    void Update(const string &messageFromSubject) override{
        this->_messageFromSubject = messageFromSubject;
        PrintInfo();
    }
    void RemoveMeFromTheList(){
        this->_subject.Detach(this);
        cout << "Observer \"" << this->_number << "\" removed from the list.\n";
    }
    void PrintInfo()
    {
        cout << "Observer \"" << this->_number << "\": a new message is aviilable -->" << this->_messageFromSubject << "\n";
    }

};
int Observer::_staticNumber = 0;
void ClientCode(){
    Subject * subject = new Subject();
    Observer *observer1 = new Observer(*subject);
    Observer *observer2 = new Observer(*subject);
    Observer *observer3 = new Observer(*subject);
    Observer *observer4;
    Observer *observer5;

    subject->CreateMessage("hello world! :D");
    observer3->RemoveMeFromTheList();

    subject->CreateMessage("The weather is hot today! :p");
    observer4 = new Observer(*subject);

    observer2->RemoveMeFromTheList();
    observer5 = new Observer(*subject);
    observer4->RemoveMeFromTheList();
    observer1->RemoveMeFromTheList();

    delete observer5;
    delete observer4;
    delete observer3;
    delete observer2;
    delete observer1;
    delete subject;

}


int main() {
    ClientCode();
    system("pause");
    return 0;
}
