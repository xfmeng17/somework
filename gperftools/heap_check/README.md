# test01

http://qiushao.net/2020/07/11/Linux/memory-leak-analyze-tcmalloc/

bazel build ... --compilation_mode=dbg --strip="never"
HEAPCHECK=normal ./bin/test01
pprof ./bin/test01 profile.0001.heap --lines --text --stack

使用完 tcmalloc 之后，我们有以下几个疑问，只要把这几个疑问解决了，那我们对 tcmalloc 的基本原理也就清楚了。

1. 如何记录内存分配，释放:
tcmalloc 其实就是定义了一套自己的内存分配释放函数把标准库中的 malloc, alloc, free, new, delete 等替换掉。在分配内存的时候，通过 libunwind 获取调用堆栈，把内存分配调用堆栈记录下来。
2. 如何替换标准库的内存分配，释放函数：
D_PRELOAD 是 Linux 系统的一个环境变量，它可以影响程序的运行时的链接，它允许你定义在程序运行前优先加载的动态链接库。这个功能主要就是用来有选择性的载入不同动态链接库中的相同函数。通过这个环境变量，我们可以在主程序和其动态链接库的中间加载别的动态链接库，甚至覆盖正常的函数库。一方面，我们可以以此功能来使用自己的或是更好的函数（无需别人的源码），而另一方面，我们也可以以向别人的程序注入程序，从而达到特定的目的。
3. 如何在程序 main 函数结束后，执行内存泄漏分析：
只要定义一个全局静态类变量就行，这个变量的构造函数会在 main 之前执行，析构函数会在 main 函数之后执行。


https://gperftools.github.io/gperftools/heapprofile.html

bazel build ... --compilation_mode=dbg --strip="never"
HEAPPROFILE=/data/github/tempwork/gperftools/heap_check/test02 HEAP_PROFILE_ALLOCATION_INTERVAL=1048576 ./bin/test02
pprof --pdf --base=./test02.0002.heap ./bin/test02 ./test02.0012.heap > test02_0012_0002.pdf
