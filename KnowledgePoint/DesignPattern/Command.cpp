/*
@Project ��cppReview 
@File ��Command.c
@Author ��HuntingGame
@Date ��2023-06-18 16:32 
C'est la vie!!! enjoy ur day :D
*/


#include<iostream>
using namespace std;

//receiver--->army
class Army
{
private:
    string m_name;
public:
    Army(string name):m_name(name){}
    string getName(){return m_name;}
    void fight(){
        cout <<m_name <<" will fight!!!" << endl;
    }
    void retreat(){
        cout << m_name <<" will retreat!!!" << endl;
    }
};






class Command{
public:
    virtual void execute() = 0; // ִ��
};


class FightCommand:public Command
{
private:
    Army* m_army;
public:
    FightCommand(Army* army):m_army(army){
        cout <<"ready to send Fight command to " << m_army->getName() << endl;
    }
    //��������ִ�в���
    void setArmy(Army* army){
        cout <<"ready to send Fight command to" << army->getName() << endl;
        m_army = army;
    }
    virtual void execute(){
        cout <<"fight execute!" << endl;
        m_army->fight();
    }



};


class RetreatCommand:public Command
{
private:
    Army* m_army;
public:
    RetreatCommand(Army* army):m_army(army){
        cout <<"ready to send Retreat command to " << m_army->getName() << endl;
    }
    //��������ִ�в���
    void setArmy(Army* army){
        cout <<"ready to send Retreat command to" << army->getName() << endl;
        m_army = army;
    }
    virtual void execute(){
        cout <<"Retreat execute!" << endl;
        m_army->retreat();
    }



};

//��������ߣ�ָ�Ӳ�
class Headquarters{
private:
    Command* m_command;
public:
    void setCommand(Command* command){
        m_command = command;
    }

    void execute_command(){
        m_command->execute();
    }



};




int main() {

    // ����֧���ӷֱ�����������
    Army* army1 = new Army("du li tuan");
    Command* command1 = new FightCommand(army1);
    Army* army2 = new Army("gang qi lian");
    Command* command2 = new RetreatCommand(army2);

    // ָ�Ӳ�������������ų�桢����������
    Headquarters* headquarters = new Headquarters();
    headquarters->setCommand(command1);
    headquarters->execute_command();
    headquarters->setCommand(command2);
    headquarters->execute_command();

    // ���
    delete army1;
    delete command1;
    delete army2;
    delete command2;
    delete headquarters;
    army1 = nullptr;
    command1 = nullptr;
    army2 = nullptr;
    command2 = nullptr;
    headquarters = nullptr;


    return 0;
}
