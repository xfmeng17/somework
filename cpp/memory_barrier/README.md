[理解 Memory barrier（内存屏障）](https://blog.csdn.net/zhangxiao93/article/details/42966279)

[当我们在谈论cpu指令乱序的时候，究竟在谈论什么？](https://zhuanlan.zhihu.com/p/45808885)
> “但是对于x86的cpu来说，在单核视角上，其实它做出了Sequential consistency[1]的一致性保障。” 

起因是，使用gettimeofday()减去trpc::context->GetRecvTimestamp()属性上报溢出（已解决，存在uint64_t溢出问题）

去读trpc::time.cc的代码，读了一串知识盲区：

1. trpc::time.cc trpc_rdtsc \__asm__ __volatile__("rdtsc" : "=a"(low), "=d"(high))

2. 为啥实现上用rdtsc，是为了防止在就机器上，gettimeofday性能不行：[浅谈时间函数gettimeofday的成本](https://blog.csdn.net/russell_tao/article/details/7185588)

3. 软硬终端，软中断是啥？[点个外卖，我把「软中断」搞懂了](https://www.mdeditor.tw/pl/ggsn)

4. > 不过，软中断不只是包括硬件设备中断处理程序的下半部，一些内核自定义事件也属于软中断，比如内核调度等、RCU 锁（内核里常用的一种锁）等。

   RCU 锁 是啥来的？[深入理解 Linux 的 RCU 机制](https://zhuanlan.zhihu.com/p/30583695) 读到了 smp_wmb() 和内存屏障

5. 内存屏障到底是啥来的？[Memory barrier是什么？](https://www.zhihu.com/question/20228202) 这个了解了，又读了 [理解 Memory barrier（内存屏障）](ttps://blog.csdn.net/zhangxiao93/article/details/42966279) 陷入到这个文章中

6. 内核kfifo的实现，源码使用了smp_mb() smp_rmb() smp_wmb()，问了问丙玉

7. 还没看 https://github.com/apache/incubator-brpc/blob/master/docs/cn/atomic_instructions.md


补充:

1. `sar -n DEV 1 3` 查看网卡，参数意义：https://blog.51cto.com/461205160/1939549
2. 查看每个软中断类型的中断次数的变化速率：`watch -d cat /proc/softirqs`
3. 
