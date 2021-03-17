看到了fwrite_unlocked函数，查了下是无锁版本，顺便了解了下fwrite咋锁的，原来是用了一个内部的mutex，无锁的性能好

参考文章：https://blog.csdn.net/qu1993/article/details/109382285

其他：

> 在**同一个进程内**, 针对同一个**FILE\***的**操作**(比如fwrite), 是**线程安全**的. 当然这只在POSIX兼容的系统上成立, Windows上的FILE*的操作并不是线程安全的.[http://gcc.gnu.org/onlinedocs/libstdc++/manual/using_concurrency.html](https://link.zhihu.com/?target=http%3A//gcc.gnu.org/onlinedocs/libstdc%2B%2B/manual/using_concurrency.html)
> As an example, the POSIX standard requires that C stdio FILE* operations are atomic. POSIX-conforming C libraries (e.g, on Solaris and GNU/Linux) have an internal mutex to serialize operations on FILE*s. However, you still need to not do stupid things like calling fclose(fs) in one thread followed by an access of fs in another.