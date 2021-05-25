#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>

using namespace std;

mutex _mutex;
static int total = 0;

//创建一个函数，供多个线程调用
void fun(int num)
{
    while(1)
    {
        sleep(2);
        lock_guard<mutex>lock(_mutex);
        total +=num;
        cout<<"num:"<<num<<endl;
    }
}


int main()
{
    thread t1(fun,3);
    thread t2(fun,5);
    t1.join();
    t2.join();
    return 0;
}

// g++ -std=c++11 test03.cc -lpthread -g
// https://zhuanlan.zhihu.com/p/173652671