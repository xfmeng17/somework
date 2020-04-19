#include "quicksort.h"

int quicksort(int* arr, int p, int q) {
  if (p >= q) {
    return 0;
  }
  int i = p;
  int j = i + 1;
  for (; j <= q; j++) {
    if (arr[j] <= arr[i]) {
      i++;
      int t = arr[i];
      arr[i] = arr[j];
      arr[j] = t;
    }
  }
  arr[p] = arr[i];
  return 0;
}
