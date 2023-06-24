cmake_minimum_required(VERSION 3.10)
project(cppReview)

set(CMAKE_CXX_STANDARD 14)
add_definitions(-DUBUNTU=0)
if(UBUNTU)
#下面的是ubuntu的
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")
set(JSONCPP_DIR /home/ubuntu/software/jsoncpp-0.10.7)
set(lib_DIR /usr/lib/x84_64-linux-gnu)# 为了libjsoncpp.a
set(MYSQL_LIBS mysqlclient)
INCLUDE_DIRECTORIES( #相关头文件的目录
        ${JSONCPP_DIR}/include
        /usr/local/include)

LINK_DIRECTORIES( #相关库文件的目录
        ${JSONCPP_DIR}/lib

        /usr/local/lib

        )
set(lib_DIR /usr/lib/x84_64-linux-gnu)#链接库路径

else()
#下面的是windows的
INCLUDE_DIRECTORIES(
        D:/Study/soft_ware/mysql-8.0.16-winx64/Connector C++ 8.0/include
        C:/Program Files/MySQL/MySQL Server 8.0/include
)
LINK_DIRECTORIES(
        D:/Study/soft_ware/mysql-8.0.16-winx64/Connector C++ 8.0/lib64/vs14

        C:/Program Files/MySQL/MySQL Server 8.0/lib
)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/KnowledgePoint/learningLog)
#add_executable(cppReview Chapter.cpp)
#add_executable(1_1 1_1global_static_var.cpp )
#add_executable(1_2 return_local_var.cpp)
##add_executable(test test.cpp)
#add_executable(main Person.h main.cpp)
#add_executable(learnPThread learnPThread.cpp)
#add_executable(learningLog KnowledgePoint/learningLog/main.cpp KnowledgePoint/learningLog/log.h)
#add_executable(learningJson KnowledgePoint/learningJson/learningJson.cpp )
#target_link_libraries(learningJson jsoncpp)
add_executable(test_Logger KnowledgePoint/learningLog/test_logger.cpp KnowledgePoint/learningLog/Logger.h KnowledgePoint/learningLog/Logger.cpp)

add_executable(Book_code1_1 KnowledgePoint/learningThread/Book_code1.1.cpp )
add_executable(throwAndDestruct KnowledgePoint/InterestingExp/throwAndDestruct.cpp)
add_executable(Book_code2_4 KnowledgePoint/learningThread/Book_code2.4.cpp)
add_executable(move KnowledgePoint/InterestingExp/move.cpp)
add_executable(Book_code2_9 KnowledgePoint/learningThread/Book_code2.9.cpp)
add_executable(copy_withThreads tinyProject/copy_withThreads.cpp)
add_executable(copy_withThreads2 tinyProject/copy_withThreads2.cpp)
add_executable(copy_withThreadsPoll tinyProject/copy_withThreadsPoll.cpp)
add_executable(connectMysql tinyProject/connectMysql.cpp)
add_executable(connectMysqlLogin tinyProject/connectMysqlLogin.cpp)
target_link_libraries(connectMysql ${MYSQL_LIBS})#ubuntu
target_link_libraries(connectMysqlLogin ${MYSQL_LIBS})#ubuntu

add_executable(test_RALL KnowledgePoint/test_RALL.cpp)
add_executable(test_template_args test_template_args.cpp)
add_executable(niuke NiuKe/test_meiju.cpp)
add_executable(test0427 test0427.cpp)
# Add subdirectory
#add_subdirectory(KnowledgePoint/DesignPattern)



# 设计模式i相关
add_executable(learnSingle KnowledgePoint/DesignPattern/Singleton.cpp)
add_executable(learnStrategy KnowledgePoint/DesignPattern/Strategy.cpp)
add_executable(learnStrategy_Easy_Factory KnowledgePoint/DesignPattern/Strategy_add_EasyFactory.cpp)
add_executable(learnDecorator KnowledgePoint/DesignPattern/Decorator.cpp)
add_executable(learnProxy KnowledgePoint/DesignPattern/Proxy.cpp)
add_executable(TemplateMethod KnowledgePoint/DesignPattern/TemplateMethod.cpp)
add_executable(Facade KnowledgePoint/DesignPattern/Facade.cpp)
add_executable(Builder KnowledgePoint/DesignPattern/Builder.cpp)
add_executable(Observer KnowledgePoint/DesignPattern/Observer.cpp)
add_executable(State KnowledgePoint/DesignPattern/State.cpp)
add_executable(Adapter KnowledgePoint/DesignPattern/Adapter.cpp)
add_executable(Memento KnowledgePoint/DesignPattern/Memento.cpp)
add_executable(Iterator KnowledgePoint/DesignPattern/Iterator.cpp)
add_executable(Bridge KnowledgePoint/DesignPattern/Bridge.cpp)
add_executable(Command KnowledgePoint/DesignPattern/Command.cpp)
add_executable(ChainOfResponsibility KnowledgePoint/DesignPattern/ChainOfResponsibility.cpp)
add_executable(Mediator KnowledgePoint/DesignPattern/Mediator.cpp)
add_executable(Flyweight KnowledgePoint/DesignPattern/Flyweight.cpp)
add_executable(Visitor KnowledgePoint/DesignPattern/Visitor.cpp)






