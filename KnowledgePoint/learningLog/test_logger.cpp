/*
@Project £ºcppReview 
@File £ºtest_logger.c
@Author £ºHuntingGame
@Date £º2023-04-15 10:02 
C'est la vie!!! enjoy ur day :D
*/


#include<iostream>
#include"Logger.h"
using namespace Sakura::Logger;

int main()
{
    //std::cout<<"hello Sakura"<<std::endl;
    Logger::getInstance()->open("./test.log");
    Logger::getInstance()->setMax(1024);
    //Logger::getInstance()->setLevel(Logger::INFO);
    //Logger::getInstance()->log(Logger::DEBUG,__FILE__,__LINE__,"hello Sakura");
    //Logger::getInstance()->log(Logger::DEBUG,__FILE__,__LINE__,"name is %s,age is %d","ĞıÎĞÃùÈË",18);

    debug("hello Sakura");
    debug("name is %s,age is %d","ĞıÎĞÃùÈË",18);
    info("info message");
    warn("warn message");
    erro("erro message");
    fatal("fatal message");

    return 0;
}
