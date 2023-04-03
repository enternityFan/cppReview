/*
@Project £ºcppReview 
@File £ºmain.c
@Author £ºHuntingGame
@Date £º2023-04-03 10:34 
C'est la vie!!! enjoy ur day :D
*/


#include<iostream>
#include <stdlib.h>
#include "log.h"

using namespace std;

int main() {
    std::cout << "hello" << std::endl;
    log_info("hi,im log info!\n");
    log_debug("hi,im log debug!\n");
    log_error("hi,im log error!\n");
    system("pause");
    return 0;
}
