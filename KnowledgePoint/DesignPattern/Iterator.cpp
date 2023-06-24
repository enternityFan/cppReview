/*
@Project ：cppReview 
@File ：Iterator.c
@Author ：HuntingGame
@Date ：2023-06-18 16:04 
C'est la vie!!! enjoy ur day :D
*/


#include<iostream>
#include<vector>
using namespace std;

//TODO 改写为模板类
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

// 定义容器接口
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
    // 创建迭代器
    virtual Iterator* create_iterator() override{
        return new ConcreteItertor(m_data);
    }
};





int main() {

    // 创建容器和迭代器
    std::vector<int> data = { 1, 2, 3, 4, 5 };
    Container* container = new ConcreteContainer(data);
    Iterator* iterator = container->create_iterator();

    // 迭代器输出
    while (iterator->hasNext()) {
        std::cout << iterator->next() << " ";
    }

    // 清除
    delete iterator;
    delete container;
    iterator = nullptr;
    container = nullptr;
    return 0;

    return 0;
}
