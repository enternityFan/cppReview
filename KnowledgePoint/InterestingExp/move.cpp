/*
@Project ��cppReview 
@File ��move.c
@Author ��HuntingGame
@Date ��2023-04-03 19:01 
C'est la vie!!! enjoy ur day :D
*/


#include<iostream>
#include <vector>
#include "time.h"
using namespace std;

int main() {
    // ��һ��ʵ�飬������move�����������ٵ�Ч��
    // ʵ��������ȷʵmove����١����40�����Ұ����ʵ�顣
    vector<string> v1,v2;

    auto s1 = clock();
    for (int i=0;i<100000000;++i){
        v1.push_back("hello");
    }
    auto e1 = clock();
    cout <<"op1 cost:" << float(e1 - s1)/1000<<endl; // ��ȷ������
    auto s2 = clock();
    for (int i=0;i<100000000;++i){
        v2.push_back(move("hello"));
    }
    auto e2 = clock();
    cout <<"op2 cost:" << float(e2 - s2)/1000<<endl; // ��ȷ������
    return 0;
}
