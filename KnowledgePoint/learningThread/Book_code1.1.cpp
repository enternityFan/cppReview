/*
@Project ：cppReview 
@File ：Book_code1.c
@Author ：HuntingGame
@Date ：2023-04-03 15:24 
C'est la vie!!! enjoy ur day :D
*/


#include<iostream>
#include <thread>

using namespace std;

void hell(){
    cout << " Hello World\n" << endl;
}
class background_task{
public:
    void operator()() const
    {
        auto a = [](){cout <<"hello!" << endl;};
        cout <<"lambda func's type:" << typeid(a).name() << endl;
        a();
    }
};

class testDestructor{
public:
    //用来测试当抛出异常后，是否这个局部变量还会析构
    testDestructor()=default;
    ~testDestructor();
};
testDestructor::~testDestructor() {
    cout <<"i am destructor!" << endl;
}


class thread_guard
{
    std::thread& t;
public:
    explicit thread_guard(std::thread& t_):
            t(t_)
    {}
    ~thread_guard()
    {
        cout <<"thread_guard destruct!" << endl;
        if(t.joinable())
        {
            t.join();
        }
    }
    thread_guard(thread_guard const&)=delete;
    thread_guard& operator=(thread_guard const&)=delete;
};
struct func
{
    int& i;
    func(int& i_):i(i_){}
    void operator()()
    {
        for(unsigned j=0;j<10;++j)
        {
           cout <<j<<endl;
        }
        cout << "i am finished!" << endl;
    }

};

void f()
{
    int some_local_state=0;
    func my_func(some_local_state);
    std::thread t(my_func);
    thread_guard g(t);
    auto do_something_in_current_thread = [](){
        throw -1;
    };
    do_something_in_current_thread();
}

int main() {
    thread t2([]{
        cout <<"hello,i am "<<this_thread::get_id()<<"!:)" << endl;
    });
    t2.join();
    thread t1(f);
    t1.join();

//    background_task f;
//    thread t1(f);

//    t1.join();
    //testDestructor test;
    //throw -1;

    //system("pause");
    return 0;
}



