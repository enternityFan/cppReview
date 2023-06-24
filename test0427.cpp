/*
@Project ：cppReview 
@File ：test0427.c
@Author ：HuntingGame
@Date ：2023-04-27 16:27 
C'est la vie!!! enjoy ur day :D

 // 动物园管理类，
 2个api: add   food

 lion tiger anamal->全都变成私有的。

 不暴露anaminal;

*/


#include<iostream>
#include <vector>

using namespace std;

class ZoomManager;

class Animal
{
public:
    Animal(){};
    virtual ~Animal(){};
    friend void ZoomManager::AddAnimal(Animal*  animal);
private:
    virtual void getFood()=0;
    virtual string getName()=0;
};



class Lion :public Animal
{
public:
    Lion()=default;
    ~Lion()=default;
private:
    void getFood() override{
        cout <<"i am lion,i m eated" << endl;
    }
    string getName() override{
        return "Lion";
    }
};

class Tiger :public Animal
{
public:
    Tiger()=default;
    ~Tiger()=default;
private:
    void getFood() override{
        cout <<"i am tiger,i m eated" << endl;
    }
    string getName() override{
        return "Tiger";
    }
};



class ZoomManager
{
public:
    ZoomManager()= default;
    ~ZoomManager()= default;
    void AddAnimal(Animal*  animal);
    void FoodAnimal(const string & name);

private:
    vector<Animal*> animals;

};

void ZoomManager::AddAnimal(Animal* animal) {
    animals.push_back(animal);
    cout <<animal->getName() <<" is adding?" << endl;
}

void ZoomManager::FoodAnimal(const string &name) {
    for(auto iter:animals){
        if (iter->getName() == name){
            iter->getFood();
        }
    }
}






int main() {
    ZoomManager *zm = new ZoomManager();
    {
        Lion *l1 = new Lion();
        Tiger *t1 = new Tiger();
        zm->AddAnimal(l1);
        zm->AddAnimal(t1);

    }
    zm->FoodAnimal("Lion");
    zm->FoodAnimal("Tiger");

    delete zm;
    zm = nullptr;

    return 0;
}
