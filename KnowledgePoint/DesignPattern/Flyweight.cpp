/*
@Project ：cppReview 
@File ：Flyweight.c
@Author ：HuntingGame
@Date ：2023-06-18 19:24 
C'est la vie!!! enjoy ur day :D
*/


#include<iostream>
#include <unordered_map>

using namespace std;

class Flyweight{
public:
    virtual void operation() = 0;

};

// 具体享元
class ConcreteFlyweight: public Flyweight
{
private:
    string m_name;
public:
    ConcreteFlyweight(string name):m_name(name){}

    virtual void operation(){
        cout <<"get: " << m_name << endl;
    }
};

// 享元工厂
class FlyweightFactory
{
private:
    unordered_map<string,Flyweight*> flyweights;
public:
    ~FlyweightFactory(){
        for(auto it : flyweights){
            cout <<"destory " << it.first << " " << endl;
            delete it.second;
            it.second = nullptr;
        }
        flyweights.clear();
    }

    Flyweight* getFlyweight(string name){
        // 若没有，则创建
        if(flyweights.find(name) == flyweights.end()){
            cout <<"create " << name << " " << endl;
            flyweights[name] = new ConcreteFlyweight(name);
        }else{
            cout <<"already have " << name << " " << endl;
        }
        return flyweights[name];
    }
};






int main() {
    FlyweightFactory *factory = new FlyweightFactory();
    Flyweight* f1 = factory->getFlyweight("1");
    Flyweight* f2 = factory->getFlyweight("2");
    Flyweight* f3 = factory->getFlyweight("3");
    Flyweight* f4 = factory->getFlyweight("4");
    Flyweight* f5 = factory->getFlyweight("5");
    Flyweight* f6 = factory->getFlyweight("6");
    Flyweight* f7 = factory->getFlyweight("7");
    Flyweight* f8 = factory->getFlyweight("8");
    Flyweight* f9 = factory->getFlyweight("7");
    f3->operation();
    delete factory;
    factory = nullptr;

    return 0;
}
