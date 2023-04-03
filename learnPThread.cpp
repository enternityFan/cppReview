/*
@Project ：cppReview 
@File ：learnPThread.c
@Author ：HuntingGame
@Date ：2023-03-27 9:07 
C'est la vie!!! enjoy ur day :D
*/


#include<iostream>
#include<pthread.h>
using namespace std;

#define NUM_THREADS 3
struct student{

    student(string n,int a):name(n),age(a){}
    string name;
    int age;

};

void *thread_entry(void* args){

    //int tid = *(int *) args;
    student *pStu = (student *) args;
    int pid = getpid();
    int tid = pthread_self();
    cout << tid << ":Hello thread!" << endl;
    cout <<"stu name:" << pStu->name << "stu age:" << pStu->age << endl;
    pthread_exit(NULL);

}




int main() {
    pthread_t tids[NUM_THREADS];
    int index[NUM_THREADS];
    student stu1=student("tom",20);
    student stu2=student("tom2",24);
    student stu3=student("tom3",31);
    student stu[3]={stu1,stu2,stu3};

    // 创建线程
    for(int i=0;i<NUM_THREADS;++i){
        index[i] = i;
        pthread_create(&tids[i],NULL,thread_entry,(void *)&stu[i]);
    }
    for (int i=0;i<NUM_THREADS;++i){
        pthread_join(tids[i],NULL);
    }




    system("pause");
    return 0;
}
