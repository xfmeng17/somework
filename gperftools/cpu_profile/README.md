# gperftools

## 下面主要是cpuprofile

https://bitjoy.net/2017/02/07/gperftools-tutorial/

https://wiki.geany.org/howtos/profiling/gperftools
https://gperftools.github.io/gperftools/cpuprofile.html
https://developer.ridgerun.com/wiki/index.php?title=Profiling_with_GPerfTools#A.29_Profile_the_whole_process_runtime
https://www.dazhuanlan.com/2019/12/07/5dea86840d2b9/

test01
test02

CPUPROFILE=./test02.prof CPUPROFILESIGNAL=12 ./bin/test02
一直运行的，可以使用CPUPROFILESIGNAL，但是，必须设置环境变量CPUPROFILE，暂时记住，还没理解为啥

只关注一个函数
pprof --text --focus=func02 bin/test02 ./test02.prof.0

研究研究有引申开来研究了下bazel是如何编译的，为啥在copts加-lprofiler，ldd产出的test02并没有链接profiler
ldd如果没链接libprofiler.so，可以设置`LD_PRELOAD=/usr/lib64/libprofiler.so`
> LD_PRELOAD，是个环境变量，用于动态库的加载，动态库加载的优先级最高，一般情况下，其加载顺序为LD_PRELOAD>LD_LIBRARY_PATH>/etc/ld.so.cache>/lib>/usr/lib

bazel aquery gperftools/cpu_profile:test02
bazel build gperftools/cpu_profile:test02 --sandbox_debug (or -s)

test02_aquery.txt显式了过程:

1. Compiling
2. Writing params
3. Linking
4. Stripping
5. Writing dwp
6. Creating source manifest
7. Creating runfiles tree
8. Creating file sources list
简单就是 1-compiling + 2-linking + 4-stripping

copts是编译，看test02_aquery.txt第一行 `action 'Compiling` 末尾是gcc -c 只编译，-lprofiler也加了，但是没用，gcc会忽略

### gcc/g++指令选项

从 C、C++源代码生成可执行文件需要经历 4 个过程，分别为预处理、编译、汇编和链接
简单理解 `g++` = `gcc -xc++ -lstdc++ -shared-libgcc`

gcc 什么参数都不输入，默认直接4步骤一起完事到可执行程序，可以额外添加 -save-temps 选项

1. 预处理，gcc -E 展开宏头文件，默认产生一个.i
2. 编译，gcc -S 编译成汇编语言，默认产生一个.s
3. 汇编，gcc -c 汇编成机器码，默认产生一个.o
4. 链接，gcc + .o 自动完成链接成一个.out可执行程序

需要强调的一点是，和 gcc -S 类似，gcc -c 选项并非只能用于加工 .s 文件。事实上，-c 选项只是令 GCC 编译器将指定文件加工至汇编阶段，但不执行链接操作。这也就意味着：
如果指定文件为源程序文件（例如 demo.c），则 gcc -c 指令会对 demo.c 文件执行预处理、编译以及汇编这 3 步操作；
如果指定文件为刚刚经过预处理后的文件（例如 demo.i），则 gcc -c 指令对 demo.i 文件执行编译和汇编这 2 步操作；
如果指定文件为刚刚经过编译后的文件（例如 demo.s），则 gcc -c 指令只对 demo.s 文件执行汇编这 1 步操作。
注意，如果指定文件已经经过汇编，或者 GCC 编译器无法识别，则 gcc -c 指令不做任何操作。

GCC 的-l选项（小写的 L）可以让我们手动添加链接库：

1. 把链接库作为一般的目标文件，为 GCC 指定该链接库的完整路径与文件名：`gcc main.c -o main.out /usr/lib/libm.a`
2. 使用-L选项，为 GCC 增加另一个搜索链接库的目录：`gcc main.c -o main.out -L/usr/lib -lm`
3. 把包括所需链接库的目录加到环境变量 LIBRARYPATH 中 `export LIBRARYPATH=LIBRARYPATH:/xx/xx/xx`

具体可以`man gcc`查询:

- -E（大写） 预处理指定的源文件，不进行编译
- -S（大写） 编译指定的源文件，但是不进行汇编
- -c 编译、汇编指定的源文件，但是不进行链接
- -o 指定生成文件的文件名。
- -llibrary（-I library） 其中 library 表示要搜索的库文件的名称。该选项用于手动指定链接环节中程序可以调用的库文件。建议 -l 和库文件名之间不使用空格，比如 -lstdc++。
- -ansi 对于 C 语言程序来说，其等价于 -std=c90；对于 C++ 程序来说，其等价于 -std=c++98。
- -std= 手动指令编程语言所遵循的标准，例如 c89、c90、c++98、c++11 等。
- -save-temps 输入中间结果
- -fverbose-asm 选项，编译阶段，GCC 编译器会自行为汇编代码添加必要的注释
- -xc++  -x是language，表示c++语言写的