/*
@Project £ºcppReview 
@File £ºBuilder.c
@Author £ºHuntingGame
@Date £º2023-06-18 9:56 
C'est la vie!!! enjoy ur day :D
*/


#include<iostream>
using namespace std;

typedef string Graphics;
typedef string Pen;
class PersonBuilder{
public:
    virtual void buildHead()=0;
    virtual void buildBody()=0;
    virtual void buildArm()=0;
    virtual void buildLeg()=0;
    PersonBuilder(Graphics g,Pen p){
        this->g = new Graphics (g);
        this->p = new Pen (p);
    };
    virtual ~PersonBuilder(){
        delete g;
        delete p;
    };
private:
    Graphics *g;
    Pen *p;
};

class PersonThinBuilder:public PersonBuilder{
public:
    PersonThinBuilder(Graphics g,Pen p): PersonBuilder(g,p){};
    void buildArm() override{
        cout <<"Thin,draw Arm" << endl;
    }
    void buildHead() override{
        cout <<"Thin,draw Head" << endl;
    }
    void buildBody() override{
        cout <<"Thin,draw Body" << endl;
    }
    void buildLeg() override{
        cout <<"Thin,draw Leg" << endl;
    }
};
class PersonFatBuilder:public PersonBuilder{
public:
    PersonFatBuilder(Graphics g,Pen p): PersonBuilder(g,p){};
    void buildArm() override{
        cout <<"Fat,draw Arm" << endl;
    }
    void buildHead() override{
        cout <<"Fat,draw Head" << endl;
    }
    void buildBody() override{
        cout <<"Fat,draw Body" << endl;
    }
    void buildLeg() override{
        cout <<"Fat,draw Leg" << endl;
    }
};

class PersonDirector{
public:
    PersonDirector(PersonBuilder* pb)
    {this->pb = pb;};
    void createPerson(){
        pb->buildHead();
        pb->buildBody();
        pb->buildArm();
        pb->buildLeg();
    }
private:
    PersonBuilder *pb;
};





int main() {

    PersonThinBuilder *pT = new PersonThinBuilder("»­ÊÝ×Ó", "ºì±Ê");
    PersonDirector *pD = new PersonDirector(pT);

    pD->createPerson();

    delete pT;
    delete pD;

    cout << "------------ »ª Àö µÄ ·Ö ¸î Ïß ------------" << endl;

    PersonFatBuilder *pF = new PersonFatBuilder("»­ÅÖ×Ó", "ºÚ±Ê");
    PersonDirector *pD2 = new PersonDirector(pF);
    pD2->createPerson();

    delete pF;


    system("pause");
    return 0;
}
