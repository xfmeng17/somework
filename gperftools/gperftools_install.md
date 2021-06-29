# gperftools 静态库踩坑记

## 整理一下

起因是想用gperftools，框架自带了支持，需要链接tcmalloc库和打开编译选项。bazelrc:

build:gperf --cxxopt="--std=c++17"
build:gperf --strip="never"
build:gperf --copt="-Og"
build:gperf --copt="-g"
build:gperf --copt="-ggdb3"
build:gperf --copt="-DTRPC_ENABLE_PROFILER"
build:gperf --linkopt="-ltcmalloc_and_profiler"

build:gperf --linkopt="-ltcmalloc_and_profiler" 这种是动态库，devcloud下，
tcmalloc: libtcmalloc_and_profiler.so.4.2.6
unwind: libunwind.so.8.0.1

其中libunwind都是直接`yum install libunwind`

devcloud下的都没啥问题，用的很好，坑比的来了，进入FSGCC8编译环境，上面这个搞，进程起不来，揪开始了踩坑之旅：

## 1. 直接使用tcmalloc_and_profiler动态库，进程死锁

1. 进程堆栈参考**tcmalloc_deadlock.png**只有一个主线程，是tcmalloc在X86_64下已知的BUG
2. 和这篇文章写的注意一样 <https://blog.csdn.net/weixin_30655219/article/details/95254832> 分析在这个文章 <https://www.cnblogs.com/minglee/p/10097644.html>
3. **猜测** FSGCC8的镜像make前configure时，没有加 `--enable-frame-pointers` 为啥能搞上呢，是因为用的mini，估计都没遇到我遇到的问题，汗。所以如果实在搞不定，就用tcmalloc_minimal

## 2. 如何用tcmalloc_and_profiler静态库，DEVCLOUD_GCC_7.3

对应rerank gcc7.3，编译gperftools，要用 `./configure --enable-frame-pointers --disable-libunwind`，具体解释：

1. --enable-frame-pointers，X86_64架构的一个BUG，参考：<https://github.com/gperftools/gperftools/blob/master/INSTALL> => [*** NOTE FOR 64-BIT LINUX SYSTEMS]
2. 如果只有上面一个，编译rerank会报错，如下：

  ```shell
  Use --sandbox_debug to see verbose messages from the sandbox
  src/stacktrace_libunwind-inl.h:112: error: undefined reference to '_Ux86_64_getcontext'
  src/stacktrace_libunwind-inl.h:116: error: undefined reference to '_ULx86_64_init_local'
  src/stacktrace_libunwind-inl.h:120: error: undefined reference to '_ULx86_64_step'
  src/stacktrace_libunwind-inl.h:124: error: undefined reference to '_ULx86_64_get_reg'
  src/stacktrace_libunwind-inl.h:138: error: undefined reference to '_ULx86_64_step'
  src/stacktrace_libunwind-inl.h:143: error: undefined reference to '_ULx86_64_get_reg'
  src/stacktrace_libunwind-inl.h:131: error: undefined reference to '_ULx86_64_get_reg'
  src/stacktrace_libunwind-inl.h:112: error: undefined reference to '_Ux86_64_getcontext'
  src/stacktrace_libunwind-inl.h:116: error: undefined reference to '_ULx86_64_init_local'
  src/stacktrace_libunwind-inl.h:120: error: undefined reference to '_ULx86_64_step'
  src/stacktrace_libunwind-inl.h:124: error: undefined reference to '_ULx86_64_get_reg'
  src/stacktrace_libunwind-inl.h:138: error: undefined reference to '_ULx86_64_step'
  src/stacktrace_libunwind-inl.h:112: error: undefined reference to '_Ux86_64_getcontext'
  src/stacktrace_libunwind-inl.h:116: error: undefined reference to '_ULx86_64_init_local'
  src/stacktrace_libunwind-inl.h:112: error: undefined reference to '_Ux86_64_getcontext'
  src/stacktrace_libunwind-inl.h:116: error: undefined reference to '_ULx86_64_init_local'
  collect2: error: ld returned 1 exit status
  ```

  解决参考：
    - https://github.com/envoyproxy/envoy/issues/1071
    - https://github.com/envoyproxy/envoy/issues/834
    - "My reading of the configure.ac is that when frame pointers are available libunwind is not needed. We explicitly enable frame pointers already, so this change should be harmless."，
    - 简单说就是 --enable-frame-pointers了，就用tcmalloc自己内部的unwind，那就不用链接libunwind.so了
3. build:gperf --linkopt="-ltcmalloc_and_profiler" 改为 build:gperf --linkopt="/usr/local/lib/libtcmalloc_and_profiler.a"

## 3. 如何用tcmalloc_and_profiler静态库，DECKER_FS_GCC_8.3

来到天坑的FSGCC8.3编辑环境，先按上文一样，用 `./configure --enable-frame-pointers --disable-libunwind`，搞一下看看：

1. 编译FS报错：

  ```shell
  Use --sandbox_debug to see verbose messages from the sandbox
  /usr/bin/ld.gold: error: /usr/local/lib/libtcmalloc_and_profiler.a(libtcmalloc_and_profiler_la-tcmalloc.o): requires dynamic R_X86_64_32 reloc which may overflow at runtime; recompile with -fPIC
  /usr/bin/ld.gold: error: /usr/local/lib/libtcmalloc_and_profiler.a(libtcmalloc_and_profiler_la-tcmalloc.o): requires dynamic R_X86_64_PC32 reloc against '_ZN62FLAG__namespace_do_not_use_directly_use_DECLARE_double_instead27FLAGS_tcmalloc_release_rateE' which may overflow at runtime; recompile with -fPIC
  /usr/bin/ld.gold: error: /usr/local/lib/libtcmalloc_and_profiler.a(libtcmalloc_and_profiler_la-tcmalloc.o): requires dynamic R_X86_64_PC32 reloc against '_ZN62FLAG__namespace_do_not_use_directly_use_DECLARE_double_instead27FLAGS_tcmalloc_release_rateE' which may overflow at runtime; recompile with -fPIC
  ```

  提示是用 -fPIC 重新编译一下gperftools，具体为啥，网上还真没搜到，所以我先用`CXXFLAGS=-fPIC`试试，然后就成功了...
2. 可见又是一个小坑，不过按提示解决了，发现FS用了之后效果不明显，使用`./configure --enable-frame-pointers --disable-libunwind CXXFLAGS=-fPIC --with-tcmalloc-pagesize=256`
3. 不是不明显了，基本就是反向优化，后续补个perf，目测一堆进程级别的SpinLock
