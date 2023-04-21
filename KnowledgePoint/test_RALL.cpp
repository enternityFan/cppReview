/*
@Project £ºcppReview 
@File £ºtest_RALL.c
@Author £ºHuntingGame
@Date £º2023-04-16 13:45 
C'est la vie!!! enjoy ur day :D
*/


#include<iostream>
using namespace std;

class testRALL
{
public:
    testRALL(){
        m_array = new int[10];
        cout <<"i am testRALL~" << endl;
    }

    ~testRALL(){
        cout <<"i am ~testRALL~" << endl;
        delete[] m_array;
        m_array = nullptr;
    }


private:
    int *m_array;
};



int main() {
    testRALL RALL;




    system("pause");
    return 0;
}
