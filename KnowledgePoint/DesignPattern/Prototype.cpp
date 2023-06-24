/*
@Project ��cppReview 
@File ��Prototype.c
@Author ��HuntingGame
@Date ��2023-06-18 9:24 
C'est la vie!!! enjoy ur day :D
 ԭ��ģʽ
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
        return new BinarySplitter(*this); // �������캯��
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


//�Խ�������Ϊ����������������ݷָ����������ı����ݡ����������ݵȡ�

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
