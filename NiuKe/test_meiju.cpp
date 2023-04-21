/*
@Project £ºcppReview 
@File £ºtest_meiju.c
@Author £ºHuntingGame
@Date £º2023-04-18 12:31 
C'est la vie!!! enjoy ur day :D
*/

#if 1
#include<iostream>
using namespace std;


template<class T>
T fun(T a,T b){
    return a * a + b * b;
}

struct testvistual{
    virtual int a();
};


template<typename T>
auto add(T a,T b)-> decltype(a+b)
{
    return a + b;
}

enum weather: char{sun};
int main(int argc,char* argv[]) {

    enum week{sun,mon, tue=3,wed,thu,fri, sat} w;
    cout <<"sun:" << sun << endl;
    cout <<"mon: " << mon <<endl;
    cout <<"wed: " << wed << endl;

    fun(2.2,1.0);
    cout <<add(10,3) << endl;
    int arr[] = {1,2,3,4,5,6};
    for (auto &e:arr){
        cout <<e << " " << endl;
    }
    cout <<sun << endl;
    //system("pause");
    return 0;
}




#endif