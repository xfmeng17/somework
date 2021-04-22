#include <iostream>
#include <stdlib.h>

int main () {

  int *p = (int *)malloc(sizeof(int));
  free(p);
  free(p);
}
