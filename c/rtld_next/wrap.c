// gcc -fpic -c wrap.c
// gcc --share wrap.o -o libwrap.so
#define RTLD_NEXT ((void *)-1l)
#define RTLD_DEFAULT  ((void *) 0)
// https://code.woboq.org/gcc/include/dlfcn.h.html
// define RTLD_NEXT     ((void *) -1l)
// define RTLD_DEFAULT  ((void *) 0)

#include <dlfcn.h>
#include <errno.h>
#include <stdio.h>
void (*f)();
void load_func() __attribute__((constructor));
void load_func() {
  //f = (void (*)())dlsym(RTLD_NEXT, "print_message");
  f = (void (*)())dlsym(RTLD_DEFAULT, "print_message");
  char *error_str;
  error_str = dlerror();
  if (error_str != NULL) {
    printf("%s\n", error_str);
  }
  printf("load_func() first f'pointer=%p\n", f);
  printf("load_func() f:\n");
  f();
}
void print_message() {
  printf("the wrap lib~~\n");
  f();
}
