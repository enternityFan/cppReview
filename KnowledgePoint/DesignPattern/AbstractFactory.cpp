/*
@Project ：cppReview 
@File ：AbstractFactory.c
@Author ：HuntingGame
@Date ：2023-04-27 13:13 
C'est la vie!!! enjoy ur day :D
*/

#include <iostream>

//抽象模板类，模板参数为产品抽象类
template<class AbstractProduct_t>
class AbstractFactory
{
public:
    virtual AbstractProduct_t * CreateProduct() = 0;
    virtual ~AbstractFactory(){}
};

//具体模板类
template<class AbstractProduct_t,class ConcreteProduct_t>
class ConcreteFactory:public AbstractFactory<AbstractProduct_t>
{
public:
    AbstractProduct_t * CreateProduct() override
    {
        return new ConcreteProduct_t();
    }
};


// 基类 鞋子
class Shoes
{
public:
    virtual void Show() = 0;
    virtual ~Shoes() {}
};

// 耐克鞋子
class NiKeShoes : public Shoes
{
public:
    void Show()
    {
        std::cout << "我是耐克球鞋，我的广告语：Just do it" << std::endl;
    }
};

// 基类 衣服
class Clothe
{
public:
    virtual void Show() = 0;
    virtual ~Clothe() {}
};

// 优衣库衣服
class UniqloClothe : public Clothe
{
public:
    void Show()
    {
        std::cout << "我是优衣库衣服，我的广告语：I am Uniqlo" << std::endl;
    }
};


int main()
{
    // 构造耐克鞋的工厂对象
    ConcreteFactory<Shoes, NiKeShoes> nikeFactory;
    // 创建耐克鞋对象
    Shoes *pNiKeShoes = nikeFactory.CreateProduct();
    // 打印耐克鞋广告语
    pNiKeShoes->Show();

    // 构造优衣库衣服的工厂对象
    ConcreteFactory<Clothe, UniqloClothe> uniqloFactory;
    // 创建优衣库衣服对象
    Clothe *pUniqloClothe = uniqloFactory.CreateProduct();
    // 打印优衣库广告语
    pUniqloClothe->Show();

    // 释放资源
    delete pNiKeShoes;
    pNiKeShoes = NULL;

    delete pUniqloClothe;
    pUniqloClothe = NULL;

    return 0;
}




