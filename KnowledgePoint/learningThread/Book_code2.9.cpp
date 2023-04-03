/*
@Project ：cppReview 
@File ：Book_code2.c
@Author ：HuntingGame
@Date ：2023-04-03 19:15 
C'est la vie!!! enjoy ur day :D
*/

// 并行版的accumulate简单实现
#include<iostream>
#include <numeric>
#include <thread>
#include <vector>

using namespace std;

template<typename Iterator,typename T>
struct accumulate_block
{
    void operator()(Iterator first,Iterator last,T& result){
        result = std::accumulate(first,last,result);
    }
};

template<typename Iterator,typename T>
T parallel_accumulate(Iterator first,Iterator last,T init){
    unsigned long const length = std::distance(first,last); //用来计算两个容器表示的范围内包含元素的个数
    if(!length){
        return init;
    }
    unsigned long const min_per_thread = 25;
    unsigned long const max_threads = (length + min_per_thread -1) / min_per_thread;
    unsigned long const hardware_threads = std::thread::hardware_concurrency();
    unsigned long const num_threads = min(hardware_threads!=0?hardware_threads:2,max_threads);
    unsigned long const block_size = length/num_threads;
    cout <<"hardware threads:" << hardware_threads << endl;
    vector<T> results(num_threads);
    vector<thread> threads(num_threads-1);
    Iterator block_start = first;
    for(unsigned long i=0;i<(num_threads-1);++i){
        Iterator block_end = block_start;
        advance(block_end,block_size);//把iter前进n步，n为负时则后退。
        threads[i] = thread(accumulate_block<Iterator,T>(),block_start,block_end,ref(results[i]));
        block_start = block_end;
    }
    accumulate_block<Iterator,T>()(block_start,last,results[num_threads-1]);
    for(auto& entry:threads)
        entry.join();
    return accumulate(results.begin(),results.end(),init);
}




int main() {
    //说明多线程的加速性
    //注意这个多线程的累加还是有bug的，如果是做float等的数据不太行，当然还有其他的一些小问题了。

    vector<int> v1,v2;
    for (int i=0;i<100000000;++i){
        v1.push_back(1);
        v2.push_back(1);
    }
    auto s1 = clock();
    int res1 = accumulate(v1.begin(),v1.end(),0);
    auto e1 = clock();
    cout <<"res1:" << res1<<"op1 cost:" << float(e1 - s1)/1000<<endl; // 精确到毫秒
    auto s2 = clock();
    int res = parallel_accumulate(v2.begin(),v2.end(),0);
    auto e2 = clock();
    cout <<"res2:"<<res<<"op2 cost:" << float(e2 - s2)/1000<<endl; // 精确到毫秒


    return 0;

}
