/*
@Project ：cppReview 
@File ：Visitor.c
@Author ：HuntingGame
@Date ：2023-06-18 19:36 
C'est la vie!!! enjoy ur day :D
*/


#include<iostream>
#include <vector>

#include <algorithm>
using namespace std;



class Visitor;

// 抽象元素类-地点(被访问)
class Place
{
public:
    // 构造函数
    Place(string name) : m_name(name) {}

    // 接受访问
    virtual void accept(Visitor* visitor) = 0;

    // 获取名字
    string getName() {
        return m_name;
    }

private:
    string m_name;
};

// 具体元素类-学校
class School : public Place
{
public:
    // 构造函数
    School(string name) : Place(name) {}

    // 接受访问
    virtual void accept(Visitor* visitor);

};

// 具体元素类-企业
class Enterprise : public Place
{
public:
    // 构造函数
    Enterprise(string name) : Place(name) {}

    // 接受访问
    virtual void accept(Visitor* visitor);

};
// 抽象访问者
class Visitor
{
public:
    // 访问学校
    virtual void visitSchool(School* school) = 0;

    // 访问企业
    virtual void visitEnterprise(Enterprise* enterprise) = 0;

};

// 具体访问者-市长
class Mayor : public Visitor
{
public:
    // 访问学校
    virtual void visitSchool(School* school) {
        cout << "Mayor visit: " << school->getName() << endl;
        cout << " ,and say:good!!!!" << endl;
    }

    // 访问企业
    virtual void visitEnterprise(Enterprise* enterprise) {
        cout << "Mayor visit: " << enterprise->getName() << endl;
        cout << " ,and say:great!" << endl;
    }

};

// 访问行为类
class Visiting
{
public:
    // 添加被访问地点
    void add(Place* place) {
        places.push_back(place);
    }

    // 删除被访问地点
    void remove(Place* place) {
        places.erase(std::remove(places.begin(), places.end(), place), places.end());
    }

    // 进行访问
    void accept(Visitor* visitor) {
        for (auto place : places) {
            place->accept(visitor);
        }
    }

private:
    std::vector<Place*> places;
};


// 接受访问
void School::accept(Visitor* visitor) {
    visitor->visitSchool(this);
}

// 接受访问
void Enterprise::accept(Visitor* visitor) {
    visitor->visitEnterprise(this);
}





int main() {

    Visiting *visiting = new Visiting();
    Place *school = new School("csu");
    Place *enterprise = new Enterprise("huawei");
    Visitor *mayor = new Mayor();

    // 添加被访问对象
    cout << "first day,";
    visiting->add(school);
    visiting->add(enterprise);
    // 安排市长进行访问
    visiting->accept(mayor);
    // 次日行程，删除某个被访问对象后再次访问
    cout << "the second day,";
    visiting->remove(school);
    visiting->accept(mayor);

    // 删除
    delete visiting;
    delete school;
    delete enterprise;
    delete mayor;
    visiting = nullptr;
    school = nullptr;
    enterprise = nullptr;
    mayor = nullptr;


    return 0;
}
