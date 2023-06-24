/*
@Project ��cppReview 
@File ��Memento.c
@Author ��HuntingGame
@Date ��2023-06-18 15:30 
C'est la vie!!! enjoy ur day :D
*/


#include<iostream>
#include <vector>

using namespace std;

class Memento{
private:
    string m_state;
public:
    Memento(string state):m_state(state){}
    string getState() const{
        return m_state;
    }

};


// ������-��Ϸ
class Game
{
public:
    // ����״̬
    void setState(string state) {
        m_state = state;
    }

    // ��ȡ״̬
    string getState() {
        return m_state;
    }

    // ����״̬������¼
    Memento saveStateToMemento() {
        return Memento(m_state);
    }

    // �ӱ���¼��ȡ״̬
    void getStateFromMemento(const Memento& memento) {
        m_state = memento.getState();
    }

private:
    std::string m_state;
};


//����¼������-���ȹ���
class CareTaker
{
private:
    vector<Memento> m_mementos;
public:
    void addMemento(const Memento& memento){
        m_mementos.push_back(memento);
    }
    Memento getMemento(int index){
        return m_mementos[index];
    }
};







int main() {
    Game game;
    CareTaker careTaker;
    // ͨ��
    game.setState("process:1.th passed!");
    game.setState("process:2.th passed!");
    // ������ȣ����ȱ�����ϵͳ����
    careTaker.addMemento(game.saveStateToMemento());
    // ����ͨ��
    game.setState("process:3.th passed!");
    // ������ȣ����ȱ�����ϵͳ����
    careTaker.addMemento(game.saveStateToMemento());
    // ����ͨ��
    game.setState("process:4.th passed!");
    // ��ǰ����
    cout << "cur:" << game.getState() << endl;
    // ��ȡ�׸�����
    game.getStateFromMemento(careTaker.getMemento(0));
    cout << "1)" << game.getState() << endl;
    // ��ȡ�ڶ�������
    game.getStateFromMemento(careTaker.getMemento(1));
    cout << "2)" << game.getState() << endl;


    return 0;
}
