/*
@Project ：cppReview 
@File ：Prototype.c
@Author ：HuntingGame
@Date ：2023-06-18 9:24 
C'est la vie!!! enjoy ur day :D
 原型模式
*/


#include<iostream>
using namespace std;

class Isplitter{
public:
    virtual void split() = 0;
    virtual Isplitter* clone() = 0;
    virtual ~Isplitter(){}
};



class BinarySplitter:public Isplitter{
public:
    void split() override{
        cout <<"BinarySplitter" << endl;
    }
    Isplitter* clone() override{
        return new BinarySplitter(*this); // 拷贝构造函数
    }
};

class TxtSplitter : public Isplitter{
public:
    void split() override{
        cout <<"TxtSplitter" << endl;
    }
    Isplitter* clone() override{
        return new TxtSplitter(*this);
    }
};


//以解析数据为例，抽象基类是数据分割，子类可以是文本数据、二进制数据等。

class mainForm{
public:
    mainForm(Isplitter* prototype){
        this->prototype = prototype;
    }

    void Button_Click(){
        Isplitter* splitter = prototype->clone();
        splitter->split();
    }


private:
    Isplitter* prototype;
};


int main() {
    mainForm* form1 = new mainForm(new BinarySplitter());
    form1->Button_Click();
    mainForm* form2 = new mainForm(new TxtSplitter());
    form2->Button_Click();

    system("pause");
    return 0;
}
