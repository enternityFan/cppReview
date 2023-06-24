/*
@Project ：cppReview 
@File ：test_template_args.c
@Author ：HuntingGame
@Date ：2023-04-21 16:38 
C'est la vie!!! enjoy ur day :D
*/

//用来测试半残模板的展开
#include<iostream>
using namespace std;



template<typename T0>
void printf1(T0 value){
    // 利用递归的方式打印所有的模板参数
    cout << value << endl;
}

template<typename T,typename ... Ts>
void printf1(T value,Ts... args)
{
    cout << value << endl;
    printf1(args...);
}


template<typename T0,typename ... T>
void printf2(T0 t0,T... t){
    //c++17对变参模板展开的支持特性
    cout << t0 << endl;
    if constexpr (sizeof ...(t)>0)printf2(t...);
}

template<typename ... T>
auto sum(T... t)-> decltype((t+...)){
    return (t + ...);
}


int main() {
    printf1(1,2,"123",1.1);
    printf2(1,2,"123",1.1);
    cout << sum(1,23,4,5,7,8,9) << endl;

    return 0;
}
