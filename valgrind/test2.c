// gcc -Wall -g valgrind_demo.c -o valgrind_demo
//
#include <stdlib.h>

void f(void) {
  int* x = malloc(10 * sizeof(int));
  x[10] = 0;  //问题1:内存越界
              //问题2:内存泄露
}

int main(int argc, char* argv[]) {
  f();
  return 0;
}
