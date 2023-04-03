/*
@Project £ºcppReview 
@File £ºreturn_local_var.py
@Author £ºHuntingGame
@Date £º2022-12-16 15:10 
C'est la vie!!! enjoy ur day :D
*/



#include <iostream>

using namespace std;
int * func()
{
    int a = 10;
    return &a;
}

int* func2()
{
    int* a = new int(10);
    return a;
}

int main() {
    int *p = func2();
    cout << *p << endl;
    int *p2 = func();


    cout << *p2 << endl;

    system("pause");

    return 0;
}
