# 笔记

## 2021-05-25

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

## 2020-10-10

- cpp/c++11/lambde01.cc lambde使用
- cpp/c++11/functional.cc `std::functional` `std::bind` 使用 

------

## 2020-03-21

### "Pure Virtual Function Called" Bug

总结学习一下最近遇到的core问题，主要是启动ranking服务core掉，shell显示"pure virtual method called"的问题

> 参考资料：<https://www.artima.com/cppsource/pure_virtual.html>

1. 运行ranking遇到"pure virtual method called"的core，拉有哥看了小两天，极大联系了分析gdb信息，和model那是如何使用智能指针如何继承的，最后发现是在BUILD中，链接的是别的目录的子目录Model下，未实现对应函数的`.a`。
2. 借这个bug，通过参考资料学习了一下，首先复习了虚函数，纯虚函数，继承和虚表的概念。
3. 练习了 `"Pure Virtual Function called": An Explanation` 里面5种导致pure virtual method called的习题。
4. 最终对CPP的继承，虚函数和虚表有了更清晰的认识，对相关gdb信息有了了解，以后遇到相同问题应该会有经验了。

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
