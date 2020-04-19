#include <stdlib.h>

#include "mergesort.h"

static int msort(int *arr, int *aux, int lo, int hi);
static int merge(int *arr, int *aux, int lo, int hi);

int mergesort(int *arr, int lo, int hi) {
  int size = hi - lo + 1;
  int *aux = (int *)malloc(sizeof(int) * size);
  msort(arr, aux, lo, hi);
  free(aux);

  return 0;
}

static int msort(int *arr, int *aux, int lo, int hi) {
  if (hi <= lo) {
    return 0;
  }
  int mid = lo + (hi - lo) / 2;
  msort(arr, aux, lo, mid);
  msort(arr, aux, mid + 1, hi);
  merge(arr, aux, lo, hi);
  return 0;
}

static int merge(int *arr, int *aux, int lo, int hi) {
  // 1. copy arr to aux
  for (int k = lo; k <= hi; k++) {
    aux[k] = arr[k];
  }
  // 2. merge
  // such "mid" makes left size >= right size
  int mid = lo + (hi - lo) / 2;
  int i = lo;
  int j = mid + 1;
  for (int k = lo; k <= hi; k++) {
    if (i > mid) {
      arr[k] = aux[j];
      j++;
    } else if (j > hi) {
      arr[k] = aux[i];
      i++;
    } else if (arr[i] < arr[j]) {
      arr[k] = arr[i];
      i++;
    } else {
      arr[k] = arr[j];
      j++;
    }
  }
  return 0;
}
