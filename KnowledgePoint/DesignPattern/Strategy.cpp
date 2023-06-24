/*
@Project ：cppReview 
@File ：Strategy.c
@Author ：HuntingGame
@Date ：2023-06-14 20:49 
C'est la vie!!! enjoy ur day :D
 实现策略模式
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
    CashContext(Strategy *csuper):cs(csuper){

    }

public:

    void  GetResult(){
        cs->Algorithmlnterface();
    }
private:
    Strategy *cs;

};


int main() {
    Strategy *s1 = new Strategy1();
    Strategy *s2 = new Strategy2();
    CashContext *cc = new CashContext(s1);
    CashContext *cc2 = new CashContext(s2);
    cc->GetResult();
    cc2->GetResult();


    return 0;
}
