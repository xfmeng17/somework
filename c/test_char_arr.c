// https://blog.csdn.net/u014470361/article/details/79297601

#include <stdio.h>

int main() {
  char *p = "abcdef";
  printf("p0 %p: %s\n", p, p);
  p = "qwedma";
  printf("p1 %p: %s\n", p, p);
  // This will segment fault
  // p[0] = '1';
  printf("p2 %p: %s\n", p, p);

  char str[] = "abcd";
  printf("str0 %p: %s\n", str, str);
  str[0] = 'e';
  printf("str1 %p: %s\n", str, str);
}

