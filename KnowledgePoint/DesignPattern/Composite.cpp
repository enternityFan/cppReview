/*
@Project ��cppReview 
@File ��Composite.c
@Author ��HuntingGame
@Date ��2023-06-18 15:54 
C'est la vie!!! enjoy ur day :D
͸����ʽ
 */


#include<list>
#include<iostream>
using namespace std;


class Node{
private:
    string m_name;
public:
    explicit Node(string name):m_name(name){};
    virtual ~Node(){};
    virtual void add(Node *node){};
    virtual void remove(Node* node){};
    virtual void show(int space){
        for(int i=0;i<space;++i){
            cout <<" ";
        }
        cout << m_name << endl;
    }
};

//�����ࣺWord�ļ�
class WordFile:public Node
{
public:
    explicit WordFile(string name):Node(name){};
    virtual ~WordFile(){};
};

class Folder:public Node
{
private:
    list<Node*> nodeList;
public:
    explicit Folder(string name): Node(name){};
    virtual ~Folder(){
        nodeList.clear();
    }
    virtual void add(Node * node) override{
        nodeList.emplace_back(node);
    }

    virtual void remove(Node *node){
        nodeList.remove(node);
    }
    virtual void show(int space){
        Node::show(space);
        space ++;
        for(auto node : nodeList){
            node->show(space);
        }
    }







};





int main() {

    Node *f0 = new Folder("MyFolder");
    // �ļ���1�з���Word2��Word3�������ļ���1�����ҵ��ļ���
    Node *f1 = new Folder("Folder1");
    Node *w2 = new WordFile("Word2");
    Node *w3 = new WordFile("Word3");
    f1->add(w2);
    f1->add(w3);
    f0->add(f1);
    // ��Word1�����ҵ��ļ���
    Node *w1 = new WordFile("Word1");
    f0->add(w1);
    // ��ʾ�ҵ��ļ����е�����
    f0->show(0);
    // ɾ���ļ���1�е�Word2�ļ����ٴ���ʾ�ҵ��ļ����е�����
    f1->remove(w2);
    f0->show(0);
    // ɾ��ָ�벢�ÿ�
    delete f0, f1, w1, w2, w3;
    f0 = nullptr;
    f1 = nullptr;
    w1 = nullptr;
    w2 = nullptr;
    w3 = nullptr;
    return 0;

    return 0;
}
