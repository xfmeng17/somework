# 笔记

## 2021-06

### 梳理一下查memory leak的过程

常用的性能分析工具的简述：

- perf：Linux内核内置的工具，主要是查CPU，查完输出可以编程火焰图，比较好看
- gperftools：google出品，有4个部分：1-tcmalloc，2-heap-checker，3-heap-profiler，4-cpu-profiler，主要是通过tcmalloc和profiler库做这些分析
- asan：Address Sanitizer，可以分析内存的使用，也是google的，不过已经被gcc4.8以上收纳，原理简单说是标记内存的new/free，用单例去查一个会结束的进程的memory leak很好用，但是在线服务这种不会优雅结束的，不太试用
- GNU gprof：GNU G++自带的热点分析工具，使用-pg选项重新编译代码，暂时没去了解
- Valgrind：性能拉跨，工业界基本没见用过

通过heap profiler来看内存使用，对于复杂模块也比较困难，所以排查内存泄漏最好的方法，我目前的理解，还是缩小到某一次commit，或者通过对代码的理解，并不是说有一套工具+排查方法是万金油

- gperftools的使用 `gperftools` 目录
- asan的使用 `asan` 目录
- perf的使用 `perf` 目录，TODO噢

## 2021-05

### gdb + strace sleep

gdb目录下实践了下gdb的相关操作

其中test04，strace了一下进程，发现sleep()的系统调用是：
21:22:51.972329 rt_sigprocmask(SIG_BLOCK, [CHLD], [], 8) = 0 <0.000030>
21:22:51.972422 rt_sigaction(SIGCHLD, NULL, {SIG_DFL, [], 0}, 8) = 0 <0.000022>
21:22:51.972484 rt_sigprocmask(SIG_SETMASK, [], NULL, 8) = 0 <0.000020>
21:22:51.972536 nanosleep({1, 0}, 0x7ffd77fc4ec0) = 0 <1.000113>

非常疑惑，为啥还操作的信号SIGCHLD，搜了一大圈，是历史遗留的粑粑：https://unix.stackexchange.com/questions/528362/sleep-system-call-on-linux-interaction-with-signals
读APUE时也说过，用sig实现sleep非常扯淡，有一个版本系统使用的SIGALAM，还是个BUG

如果strace usleep() 直接就是nanosleep()的系统调用，而nanosleep()实现的原理，我自己的理解：
内核级别的timer，调用时候插入，key=tid，内核到点通过信号/IO唤醒

参考：https://my.oschina.net/u/3857782/blog/1857566

## 2021-03

### 各类用户态timer的demo

timer目录下有各种用户态timer的demo，参考文章:http://www.ilovecpp.com/2019/01/16/timer/

### gtest和gmock的demo

gtest目录下

## 2020-10

### lambde + functional

- cpp/c++11/lambde01.cc lambde使用
- cpp/c++11/functional.cc `std::functional` `std::bind` 使用

------

## 2020-03

### "Pure Virtual Function Called" Bug

总结学习一下最近遇到的core问题，主要是启动rank服务core掉，shell显示"pure virtual method called"的问题

> 参考资料：<https://www.artima.com/cppsource/pure_virtual.html>

1. 运行ranking遇到"pure virtual method called"的core，拉有哥看了小两天，极大联系了分析gdb信息，和model那是如何使用智能指针如何继承的，最后发现是在BUILD中，链接的是别的目录的子目录Model下，未实现对应函数的`.a`
2. 借这个bug，通过参考资料学习了一下，首先复习了虚函数，纯虚函数，继承和虚表的概念
3. 练习了 `"Pure Virtual Function called": An Explanation` 里面5种导致pure virtual method called的习题
4. 最终对CPP的继承，虚函数和虚表有了更清晰的认识，对相关gdb信息有了了解，以后遇到相同问题应该会有经验了

------

## 2020-01

### 布尔检索

- <https://www.cnblogs.com/AndyJee/p/3480273.html>
- 分词简历倒排，记录【词，词频】-> 【docid】链表
- 词频表示出现这个词的文章数，既后面链表的大小
- 多个and时，从词频(doc frequency, DF)小的开始，因为链接的文章数少，可以优化查着效率

### 无锁map

- <http://kaiyuan.me/2017/12/14/lock-free-prog1/> Lock-free 编程
- c++11的shared_ptr，多线程并不安全，pointer和ref的更新不是原子的
