#include <stdio.h>

void print_message();
void first();
void second();

int main() {
  printf("main() !!!\n");
  first();
  second();
  print_message();
  return 0;
}
