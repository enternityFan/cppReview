/*
@Project ��cppReview 
@File ��Iterator.c
@Author ��HuntingGame
@Date ��2023-06-18 16:04 
C'est la vie!!! enjoy ur day :D
*/


#include<iostream>
#include<vector>
using namespace std;

//TODO ��дΪģ����
class Iterator
{
public:
    virtual int next() = 0;
    virtual bool hasNext() = 0;
};

class ConcreteItertor: public Iterator{
private:
    vector<int> m_data;
    int index;
public:
    ConcreteItertor(vector<int> data):m_data(data),index(0){}
    virtual int next() override{
        return m_data[index++];
    }
    virtual bool hasNext() override{
        return index < m_data.size();
    }

};

// ���������ӿ�
class Container
{
public:
    virtual Iterator* create_iterator() = 0;

};

class ConcreteContainer: public Container
{
private:
    vector<int> m_data;
public:
    ConcreteContainer(vector<int> data):m_data(data){}
    // ����������
    virtual Iterator* create_iterator() override{
        return new ConcreteItertor(m_data);
    }
};





int main() {

    // ���������͵�����
    std::vector<int> data = { 1, 2, 3, 4, 5 };
    Container* container = new ConcreteContainer(data);
    Iterator* iterator = container->create_iterator();

    // ���������
    while (iterator->hasNext()) {
        std::cout << iterator->next() << " ";
    }

    // ���
    delete iterator;
    delete container;
    iterator = nullptr;
    container = nullptr;
    return 0;

    return 0;
}
