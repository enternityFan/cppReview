/*
@Project ：cppReview 
@File ：Bridge.c
@Author ：HuntingGame
@Date ：2023-06-18 16:16 
C'est la vie!!! enjoy ur day :D
*/

//在这里，客户端是Main函数，其中做了两个抽象类，一个是图形，一个是笔。
#include<iostream>
using namespace std;


class Figure{
protected:
    int m_size = 10;
public:
    virtual void create() = 0;
    int getSize(){
        return m_size;
    }
    void setSize(int size){
        m_size = size;
    }
};

class Circle:public Figure
{
public:
    virtual void create() override{
        cout << "o" << endl;
    }
};

class Rectangle:public Figure
{
public:
    virtual void create() override{
        cout << "D" << endl;
    }
};

class Pen{
protected:
    string m_color = "white";
    Figure* m_figure;
public:
    Pen(Figure * figure){
        m_figure = figure;
    }
    virtual ~Pen(){
        if(m_figure != nullptr){
            delete m_figure;
            m_figure = nullptr;
        }
    }
    virtual void draw() = 0;
    string getColor(){
        return m_color;
    }
    void setColor(string color){
        m_color = color;
    }

};

class BallPen:public Pen{
public:
    BallPen(Figure* figure): Pen(figure){};
    virtual void draw(){
        cout << getColor() << "BallPen 's shape is : " << m_figure->getSize();
        m_figure->create();
    }
};
class OilPen:public Pen{
public:
    OilPen(Figure* figure): Pen(figure){};
    virtual void draw(){
        cout << getColor() << "OilPen 's shape is : " << m_figure->getSize() ;
        m_figure->create();
    }
};

int main() {

    Figure *figure1 = new Rectangle();
    figure1->setSize(20);
    Pen *pen1 = new BallPen(figure1);
    pen1->setColor("black");
    pen1->draw();
    figure1 = nullptr;
    delete pen1;
    pen1 = nullptr;

    return 0;
}
