/*
@Project ：cppReview 
@File ：Memento.c
@Author ：HuntingGame
@Date ：2023-06-18 15:30 
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


// 发起类-游戏
class Game
{
public:
    // 设置状态
    void setState(string state) {
        m_state = state;
    }

    // 获取状态
    string getState() {
        return m_state;
    }

    // 保存状态至备忘录
    Memento saveStateToMemento() {
        return Memento(m_state);
    }

    // 从备忘录获取状态
    void getStateFromMemento(const Memento& memento) {
        m_state = memento.getState();
    }

private:
    std::string m_state;
};


//备忘录管理类-进度管理
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
    // 通关
    game.setState("process:1.th passed!");
    game.setState("process:2.th passed!");
    // 保存进度，进度被管理系统管理
    careTaker.addMemento(game.saveStateToMemento());
    // 继续通关
    game.setState("process:3.th passed!");
    // 保存进度，进度被管理系统管理
    careTaker.addMemento(game.saveStateToMemento());
    // 继续通关
    game.setState("process:4.th passed!");
    // 当前进度
    cout << "cur:" << game.getState() << endl;
    // 获取首个进度
    game.getStateFromMemento(careTaker.getMemento(0));
    cout << "1)" << game.getState() << endl;
    // 获取第二个进度
    game.getStateFromMemento(careTaker.getMemento(1));
    cout << "2)" << game.getState() << endl;


    return 0;
}
