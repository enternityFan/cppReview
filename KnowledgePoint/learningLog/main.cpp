/*
@Project ��cppReview 
@File ��main.c
@Author ��HuntingGame
@Date ��2023-04-03 10:34 
C'est la vie!!! enjoy ur day :D
*/


#include<iostream>
#include <stdlib.h>
#include "log.h"
#include <string>
using namespace std;

int main() {
    int a = 100;
    std::cout << "hello" << std::endl;
    log_info("hi,im log info!\n");
    log_debug("hi,im log debug!\n");
    log_error("hi,im log error!\n",100);
    system("pause");
    return 0;
}
