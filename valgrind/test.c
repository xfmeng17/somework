#include <stdlib.h>
void foo() {
  int *arr = (int *)malloc(10 * sizeof(int));
  arr[10];
}
int main() {
  foo();
  return 0;
}
