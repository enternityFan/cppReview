/*
@Project ：cppReview 
@File ：throwAndDestruct.c
@Author ：HuntingGame
@Date ：2023-04-03 18:20 
C'est la vie!!! enjoy ur day :D
*/


#include<iostream>
using namespace std;
class testDestructor{
public:
    //用来测试当抛出异常后，是否这个局部变量还会析构
    testDestructor()=default;
    ~testDestructor();
};
testDestructor::~testDestructor() {
    cout <<"i am destructor!" << endl;
}
int main() {
    try{

        testDestructor t;
        throw -1;
    }
    catch( int i){
        cout <<"error!" << endl;
    }

    //system("pause");
    return 0;
}
