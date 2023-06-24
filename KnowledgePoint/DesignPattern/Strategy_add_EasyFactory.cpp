/*
@Project £ºcppReview 
@File £ºStrategy_add_EasyFactory.c
@Author £ºHuntingGame
@Date £º2023-06-14 21:13 
C'est la vie!!! enjoy ur day :D
*/


#include<iostream>
using namespace std;

class Strategy
{
public:
    virtual void Algorithmlnterface()=0;
};

class Strategy1: public Strategy
{
public:
    void Algorithmlnterface() override{
        cout << "strategy1" << endl;
    }
};
class Strategy2: public Strategy
{
public:
    void Algorithmlnterface() override{
        cout << "strategy2" << endl;
    }
};

class Strategy3: public Strategy {
public:
    void Algorithmlnterface() override {
        cout << "strategy3" << endl;
    }

};

class CashContext
{
public:
    CashContext(string type){
        if (type == "Strategy1"){
            cs = new Strategy1();
        }
        else if (type == "Strategy2"){
            cs = new Strategy2();
        }else if (type == "Strategy3"){
            cs = new Strategy3();
        }

    }

public:

    void  GetResult(){
        cs->Algorithmlnterface();
    }
private:
    Strategy *cs;

};


int main() {
    CashContext *cc = new CashContext("Strategy1");
    CashContext *cc2 = new CashContext("Strategy2");
    cc->GetResult();
    cc2->GetResult();


    return 0;
}