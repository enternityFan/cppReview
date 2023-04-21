/*
@Project £ºcppReview 
@File £ºtest_unique_ptr.c
@Author £ºHuntingGame
@Date £º2023-04-11 10:17 
C'est la vie!!! enjoy ur day :D
*/


#include<iostream>
#include "string"
#include <memory>
using namespace std;


class test
{
public:
    test(){
        cout <<" i am test!" <<endl;
    };
    ~test(){
        cout <<" ~test!" <<endl;
    };
};
int main() {

    unique_ptr<test> ptr(new test);


    system("pause");
    return 0;
}
