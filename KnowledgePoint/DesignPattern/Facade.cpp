/*
@Project £ºcppReview 
@File £ºFacade.c
@Author £ºHuntingGame
@Date £º2023-06-18 9:49 
C'est la vie!!! enjoy ur day :D
*/


#include<iostream>
using namespace std;



class SubSystemOne{
public:
    void MethodOne(){
        cout <<"SubSystemOne----MethodOne" << endl;
    }
};

class SubSystemTwo {
public:
    void MethodTwo() {
        cout << "SubSystemTwo----MethodTwo" << endl;
    }
};

class SubSystemThree {
public:
    void MethodThree() {
        cout << "SubSystemThree----MethodThree" << endl;
    }
};

class SubSystemFour {
public:
    void MethodFour() {
        cout << "SubSystemFour----MethodFour" << endl;
    }
};


class Facade{
private:
    SubSystemOne* one;
    SubSystemTwo* two;
    SubSystemThree* three;
    SubSystemFour* four;
public:
    Facade(){
        one = new SubSystemOne;
        two = new SubSystemTwo;
        three = new SubSystemThree;
        four = new SubSystemFour;
    }
    void MethodA(){
        cout <<"method group A() ------------------" << endl;
        one->MethodOne();
        two->MethodTwo();
        four->MethodFour();
    }
    void MethodB(){
        cout <<"method group B() ------------------" << endl;
        one->MethodOne();
        three->MethodThree();
        four->MethodFour();
    }
};




int main() {
    Facade* facade = new Facade();
    facade->MethodA();
    facade->MethodB();
    system("pause");
    return 0;
}
