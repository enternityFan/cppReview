/*
@Project ：cppReview 
@File ：move.c
@Author ：HuntingGame
@Date ：2023-04-03 19:01 
C'est la vie!!! enjoy ur day :D
*/


#include<iostream>
#include <vector>
#include "time.h"
using namespace std;

int main() {
    // 做一个实验，来看看move可以提升多少的效率
    // 实验结果表明确实move会加速。差不多40秒左右吧完成实验。
    vector<string> v1,v2;

    auto s1 = clock();
    for (int i=0;i<100000000;++i){
        v1.push_back("hello");
    }
    auto e1 = clock();
    cout <<"op1 cost:" << float(e1 - s1)/1000<<endl; // 精确到毫秒
    auto s2 = clock();
    for (int i=0;i<100000000;++i){
        v2.push_back(move("hello"));
    }
    auto e2 = clock();
    cout <<"op2 cost:" << float(e2 - s2)/1000<<endl; // 精确到毫秒
    return 0;
}
