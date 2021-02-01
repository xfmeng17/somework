## 2021-02-01

### 起因

muduo 2.1.2 gdb 调试 `thread apply all bt` 显示了全部thread栈信息，就扩展去学了下gdb debug 多线程

https://cloud.tencent.com/developer/article/1087369 => `deadlock.c`

1. pstack ${pid} 可以打印当前进程的栈调用
2. kill -6 ${pid} 给进程发送`SIGABRT` 可以产生coredump进行gdb，复习了下可能3中情况会产生`SIGABRT`:
    - double free/free 没有初始化的地址或者错误的地址
    - 执行abort()函数
    - 执行到assert函数
3. 用到的相关gdb指令：
    - `info threads` 打印多个线程，应该是同理 `thread apply all bt` **__lll_lock_wait** 是锁等待
    - `thread 8` 定位具体线程
    - `p mutex1` 打印mutex信息，__owner是持有它的LWP
    - `i locals` to list "Local variables of current stack frame" (names and values), including static variables in that function. **i是info的缩写**
    - `info variables` to list "All global and static variable names".
    - `info args` to list "Arguments of the current stack frame" (names and values). 
    - https://stackoverflow.com/questions/6261392/printing-all-global-variables-local-variables
4. 具体也可以参考：https://www.jianshu.com/p/3efe896fbabc

其他补充：

- sched_yield()是主动放弃CPU执行权，移动到任务等待的队尾，让位其他相同优先级的任务进行；nanosleep()是睡眠一段时间后再唤醒：https://www.cnblogs.com/arnoldlu/p/11287972.html
