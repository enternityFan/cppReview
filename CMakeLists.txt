cmake_minimum_required(VERSION 3.10)
project(cppReview)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")
#set(JSONCPP_DIR /home/ubuntu/software/jsoncpp-0.10.7)
#set(lib_DIR /usr/lib/x84_64-linux-gnu)# 为了libjsoncpp.a
#INCLUDE_DIRECTORIES( #相关头文件的目录
#        ${JSONCPP_DIR}/include
#        /usr/local/include)
#
#LINK_DIRECTORIES( #相关库文件的目录
#        ${JSONCPP_DIR}/lib
#
#        /usr/local/lib
#
#        )
#set(lib_DIR /usr/lib/x84_64-linux-gnu)

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
add_executable(learnSingle KnowledgePoint/DesignPattern/Singleton.cpp)
add_executable(Book_code1_1 KnowledgePoint/learningThread/Book_code1.1.cpp)
add_executable(throwAndDestruct KnowledgePoint/InterestingExp/throwAndDestruct.cpp)
add_executable(Book_code2_4 KnowledgePoint/learningThread/Book_code2.4.cpp)
add_executable(move KnowledgePoint/InterestingExp/move.cpp)
add_executable(Book_code2_9 KnowledgePoint/learningThread/Book_code2.9.cpp)
