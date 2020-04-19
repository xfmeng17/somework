#include <stdio.h>

#include "mergesort/mergesort.h"
#include "quicksort/quicksort.h"

int main() {
  int arr[] = {6, 10, 13, 5, 8, 3, 2, 11};
  int ret = quicksort(arr, 0, 8 - 1);
  for (int i = 0; i < 8; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
