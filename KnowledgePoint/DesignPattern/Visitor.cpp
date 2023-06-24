/*
@Project ��cppReview 
@File ��Visitor.c
@Author ��HuntingGame
@Date ��2023-06-18 19:36 
C'est la vie!!! enjoy ur day :D
*/


#include<iostream>
#include <vector>

#include <algorithm>
using namespace std;



class Visitor;

// ����Ԫ����-�ص�(������)
class Place
{
public:
    // ���캯��
    Place(string name) : m_name(name) {}

    // ���ܷ���
    virtual void accept(Visitor* visitor) = 0;

    // ��ȡ����
    string getName() {
        return m_name;
    }

private:
    string m_name;
};

// ����Ԫ����-ѧУ
class School : public Place
{
public:
    // ���캯��
    School(string name) : Place(name) {}

    // ���ܷ���
    virtual void accept(Visitor* visitor);

};

// ����Ԫ����-��ҵ
class Enterprise : public Place
{
public:
    // ���캯��
    Enterprise(string name) : Place(name) {}

    // ���ܷ���
    virtual void accept(Visitor* visitor);

};
// ���������
class Visitor
{
public:
    // ����ѧУ
    virtual void visitSchool(School* school) = 0;

    // ������ҵ
    virtual void visitEnterprise(Enterprise* enterprise) = 0;

};

// ���������-�г�
class Mayor : public Visitor
{
public:
    // ����ѧУ
    virtual void visitSchool(School* school) {
        cout << "Mayor visit: " << school->getName() << endl;
        cout << " ,and say:good!!!!" << endl;
    }

    // ������ҵ
    virtual void visitEnterprise(Enterprise* enterprise) {
        cout << "Mayor visit: " << enterprise->getName() << endl;
        cout << " ,and say:great!" << endl;
    }

};

// ������Ϊ��
class Visiting
{
public:
    // ��ӱ����ʵص�
    void add(Place* place) {
        places.push_back(place);
    }

    // ɾ�������ʵص�
    void remove(Place* place) {
        places.erase(std::remove(places.begin(), places.end(), place), places.end());
    }

    // ���з���
    void accept(Visitor* visitor) {
        for (auto place : places) {
            place->accept(visitor);
        }
    }

private:
    std::vector<Place*> places;
};


// ���ܷ���
void School::accept(Visitor* visitor) {
    visitor->visitSchool(this);
}

// ���ܷ���
void Enterprise::accept(Visitor* visitor) {
    visitor->visitEnterprise(this);
}





int main() {

    Visiting *visiting = new Visiting();
    Place *school = new School("csu");
    Place *enterprise = new Enterprise("huawei");
    Visitor *mayor = new Mayor();

    // ��ӱ����ʶ���
    cout << "first day,";
    visiting->add(school);
    visiting->add(enterprise);
    // �����г����з���
    visiting->accept(mayor);
    // �����г̣�ɾ��ĳ�������ʶ�����ٴη���
    cout << "the second day,";
    visiting->remove(school);
    visiting->accept(mayor);

    // ɾ��
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
