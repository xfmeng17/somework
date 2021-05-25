// https://blog.csdn.net/zhangye3017/article/details/80382496

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

void* pthread_run1(void* arg)
{
    (void)arg;

    while(1)
    {
        printf("I am thread1,ID: %d\n",pthread_self());
        sleep(1);
    }
}

void* pthread_run2(void* arg)
{
    (void)arg;

    while(1)
    {
        printf("I am thread2,ID: %d\n",pthread_self());
        sleep(1);
    }
}


int main()
{

    pthread_t tid1;
    pthread_t tid2;

    pthread_create(&tid1,NULL,pthread_run1,NULL);
    pthread_create(&tid2,NULL,pthread_run2,NULL);

    printf("I am main thread\n");

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    return 0;
}

// 1.查看进程：info inferiors
// 2.查看线程：info threads
// 3.查看线程栈结构：bt
// 4.切换线程：thread n（n代表第几个线程）

// break thread_test.c:123 thread all（例：在相应函数的位置设置断点break pthread_run1）
// 在所有线程中相应的行上设置断点

// thread apply ID1 ID2 command
// 让一个或者多个线程执行GDB命令command

// thread apply all command
// 让所有被调试线程执行GDB命令command

// set scheduler-locking off
// 不锁定任何线程，也就是所有线程都执行，这是默认值

// set scheduler-locking on
// 只有当前被调试程序会执行

// set scheduler-locking on step
// 在单步的时候，除了next过一个函数的情况(熟悉情况的人可能知道，这其实是一个设置断点然后continue的行为)以外，只有当前线程会执行