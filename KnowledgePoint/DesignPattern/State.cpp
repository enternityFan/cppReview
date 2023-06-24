/*
@Project £ºcppReview 
@File £ºState.c
@Author £ºHuntingGame
@Date £º2023-06-18 10:36 
C'est la vie!!! enjoy ur day :D
*/


#include<iostream>
#include <memory>

using namespace std;


class Worker;



class State{
public:
    virtual ~State(){};
    virtual void doing(Worker* w) = 0;
};

class SleepingState: public State{
public:
    void doing(Worker* worker);
};
class WorkingState: public State{
public:
    void doing(Worker* worker);
};

class OtherState: public State{
public:
    void doing(Worker* worker);
};

class Worker{
private:
    unique_ptr<State> state;
    double hour;
public:

    Worker() :state{std::make_unique<WorkingState>()}
    {
    }
    void setState(unique_ptr<State> state){
        this->state = move(state);
    }
    double getHour(){
        return hour;
    }

    void setHour(double hou){
        hour = hou;
    }
    void requestDoing(){
        state->doing(this);
    }

};

void WorkingState::doing(Worker *worker) {
    if (worker->getHour() > 8 && worker->getHour() < 16){
        cout <<"Working State!" << endl;
    }
    else{
        worker->setState(make_unique<OtherState>());
        worker->requestDoing();
    }
}

void SleepingState::doing(Worker* worker)
{
    if (worker->getHour() >= 21 || worker->getHour() < 5)
    {
        std::cout << "SleepingState!" << std::endl;
    }
    else
    {
        worker->setState(std::make_unique<OtherState>());
        worker->requestDoing();
    }
}



void OtherState::doing(Worker* worker)
{
    if ((worker->getHour() >= 5 && worker->getHour() < 8)
        || (worker->getHour() >= 16 && worker->getHour() < 21))
    {
        std::cout << "OtherState!" << std::endl;
    }
    else if (worker->getHour() >= 21 || worker->getHour() < 5)
    {
        worker->setState(std::make_unique<SleepingState>());
        worker->requestDoing();
    }
    else
    {
        worker->setState(std::make_unique<WorkingState>());
        worker->requestDoing();
    }
}

//¿Í»§´úÂë
int main()
{
    auto worker = std::make_unique<Worker>();
    worker->setHour(24);
    std::cout << "time 24" << std::endl;
    worker->requestDoing();

    worker->setHour(11.5);
    std::cout << "time 11.5" << std::endl;
    worker->requestDoing();

    worker->setHour(19);
    std::cout << "time 19" << std::endl;
    worker->requestDoing();

    return 0;
}