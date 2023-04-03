/*
@Project £ºcppReview 
@File £ºPerson.c
@Author £ºHuntingGame
@Date £º2023-03-21 9:01 
C'est la vie!!! enjoy ur day :D
*/

#include "iostream"
#include <string>

using namespace std;
class Person{
private:
    string m_strName;
    string m_strAddress;

public:
    Person()=default;
    Person(const string &n,const string &a):m_strName(n),m_strAddress(a){}
    Person(std::istream &is){read(is , *this);};
    friend istream& read(istream&,Person &person);
    string getName() const{return m_strName;};
    string getAddress() const{return m_strAddress;};
};
class X;
class Y{
public:
    X* x;
};
class X{
public:

    Y y;
};








istream &read(istream& is,Person &person){
    is >> person.m_strName >> person.m_strAddress;
    return is;
}
ostream &print(ostream& os,const Person & person){
    os << "name= "<< person.getName() <<" address= "<< person.getAddress();
    return os;
}






