/*
@Project ��cppReview 
@File ��Book_code2.c
@Author ��HuntingGame
@Date ��2023-04-03 18:33 
C'est la vie!!! enjoy ur day :D
*/


#include<iostream>
#include <thread>
#include <cassert>

using namespace std;
void f(int i,std::string const& s)
{
    cout <<"i am f" << endl;
};
void oops(int some_param)
{
    char buffer[1024];                  //    ?---  ��
    sprintf(buffer, "%i",some_param);
    std::thread t(f,3,string(buffer));          //    ?---  ��
    t.detach();
}
int main() {

    auto f = [](){
        cout <<"hi!" << endl;
    };
    oops(1);
    thread t(f);
    t.detach();
    assert(!t.joinable());
    cout << typeid("hello").name() << endl;

    //system("pause");
    return 0;
}
