/*
@Project ��cppReview 
@File ��AbstractFactory.c
@Author ��HuntingGame
@Date ��2023-04-27 13:13 
C'est la vie!!! enjoy ur day :D
*/

#include <iostream>

//����ģ���࣬ģ�����Ϊ��Ʒ������
template<class AbstractProduct_t>
class AbstractFactory
{
public:
    virtual AbstractProduct_t * CreateProduct() = 0;
    virtual ~AbstractFactory(){}
};

//����ģ����
template<class AbstractProduct_t,class ConcreteProduct_t>
class ConcreteFactory:public AbstractFactory<AbstractProduct_t>
{
public:
    AbstractProduct_t * CreateProduct() override
    {
        return new ConcreteProduct_t();
    }
};


// ���� Ь��
class Shoes
{
public:
    virtual void Show() = 0;
    virtual ~Shoes() {}
};

// �Ϳ�Ь��
class NiKeShoes : public Shoes
{
public:
    void Show()
    {
        std::cout << "�����Ϳ���Ь���ҵĹ���Just do it" << std::endl;
    }
};

// ���� �·�
class Clothe
{
public:
    virtual void Show() = 0;
    virtual ~Clothe() {}
};

// ���¿��·�
class UniqloClothe : public Clothe
{
public:
    void Show()
    {
        std::cout << "�������¿��·����ҵĹ���I am Uniqlo" << std::endl;
    }
};


int main()
{
    // �����Ϳ�Ь�Ĺ�������
    ConcreteFactory<Shoes, NiKeShoes> nikeFactory;
    // �����Ϳ�Ь����
    Shoes *pNiKeShoes = nikeFactory.CreateProduct();
    // ��ӡ�Ϳ�Ь�����
    pNiKeShoes->Show();

    // �������¿��·��Ĺ�������
    ConcreteFactory<Clothe, UniqloClothe> uniqloFactory;
    // �������¿��·�����
    Clothe *pUniqloClothe = uniqloFactory.CreateProduct();
    // ��ӡ���¿�����
    pUniqloClothe->Show();

    // �ͷ���Դ
    delete pNiKeShoes;
    pNiKeShoes = NULL;

    delete pUniqloClothe;
    pUniqloClothe = NULL;

    return 0;
}




