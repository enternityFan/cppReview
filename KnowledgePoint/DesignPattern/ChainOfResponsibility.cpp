/*
@Project ��cppReview 
@File ��ChainOfResponsibility.c
@Author ��HuntingGame
@Date ��2023-06-18 16:50 
C'est la vie!!! enjoy ur day :D
*/


#include<iostream>
using namespace std;


class Job{
protected:
    Job* m_leader = nullptr;
public:
    virtual void approveLeave(int time) = 0; // ��׼����
    void setLeader(Job* handler){
        m_leader = handler;
    }
};

// ���������---����
class Manager: public Job
{
public:
    virtual void approveLeave(int time) override
    {
        if (time <=3){
            cout <<"Manager is dealing with approveLeave..." << endl;
        }
        else if (m_leader != nullptr){
            m_leader->approveLeave(time);
        }else{
            cout <<"illegal approveLeave time!" <<endl;
        }
    }
};


// ���������---�ܼ�
class Director: public Job
{
public:
    virtual void approveLeave(int time) override
    {
        if (time <=7){
            cout <<"Director is dealing with approveLeave..." << endl;
        }
        else if (m_leader != nullptr){
            m_leader->approveLeave(time);
        }else{
            cout <<"illegal approveLeave time!" <<endl;
        }
    }
};


int main() {
    Job* job1 = new Manager();
    Job* job2 = new Director();

    // �����쵼
    job1->setLeader(job2);

    // �յ��������������룬�ֱ�3��7��10��
    job1->approveLeave(3);
    job1->approveLeave(7);
    job1->approveLeave(10);

    delete job1;
    delete job2;
    job1 = nullptr;
    job2 = nullptr;
    return 0;
}
