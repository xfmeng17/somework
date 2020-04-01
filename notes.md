# 阅读笔记

## 2020-01

### 布尔检索

- <https://www.cnblogs.com/AndyJee/p/3480273.html>
- 分词简历倒排，记录【词，词频】-> 【docid】链表
- 词频表示出现这个词的文章数，既后面链表的大小
- 多个and时，从词频(doc frequency, DF)小的开始，因为链接的文章数少，可以优化查着效率

### 无锁map

- <http://kaiyuan.me/2017/12/14/lock-free-prog1/> Lock-free 编程
- c++11的shared_ptr，多线程并不安全，pointer和ref的更新不是原子的
