#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

static void msort(int *arr, int *aux, int lo, int hi);
static void merge(int *arr, int *aux, int lo, int mid, int hi);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: ./a.out inputfile\n");
    return (0);
  }

  FILE *fp = NULL;
  if ((fp = fopen(argv[1], "r")) == NULL) {
    printf("fopen error\n");
    return (0);
  }
  int N = 0;
  if (fscanf(fp, "%d\n", &N) != 1) {
    printf("fscanf error\n");
  }
  if (N <= 0) {
    printf("Empty input file with N = %d\n", N);
    return (0);
  }
  int *arr = (int *)malloc(sizeof(int) * N);
  int *aux = (int *)malloc(sizeof(int) * N);
  for (int i = 0; i < N; i++) {
    fscanf(fp, "%d", &arr[i]);
  }
  fclose(fp);

  struct timeval tv_beg, tv_end;
  gettimeofday(&tv_beg, NULL);

  msort(arr, aux, 0, N - 1);

  gettimeofday(&tv_end, NULL);

  // * output time cost to file
  int timecost = 0;
  timecost += tv_end.tv_sec * 1000 + tv_end.tv_usec / 1000;
  timecost -= tv_beg.tv_sec * 1000 + tv_beg.tv_usec / 1000;
  if ((fp = fopen("timecost.txt", "a+")) == NULL) {
    printf("fopen timecost.txt error");
    return (0);
  }
  time_t timer;
  char buffer[26];
  struct tm *tm_info;
  time(&timer);
  tm_info = localtime(&timer);
  strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
  fprintf(fp, "%s | mergesort range [%d, %d] | time cost: %d ms\n", buffer, 1,
          N, timecost);
  fclose(fp);

  // * output result to stdout
  printf("%d\n", N);
  for (int i = 0; i < N; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return (0);
}

static void msort(int *arr, int *aux, int lo, int hi) {
  if (hi <= lo) {
    return;
  }
  int mid = lo + (hi - lo) / 2;
  msort(arr, aux, lo, mid);
  msort(arr, aux, mid + 1, hi);
  merge(arr, aux, lo, mid, hi);
}

static void merge(int *arr, int *aux, int lo, int mid, int hi) {
  for (int k = lo; k <= hi; k++) {
    aux[k] = arr[k];
  }
  int i = lo, j = mid + 1;
  for (int k = lo; k <= hi; k++) {
    if (i > mid) {
      arr[k] = aux[j];
      j++;
    } else if (j > hi) {
      arr[k] = aux[i];
      i++;
    } else if (aux[i] < aux[j]) {
      arr[k] = aux[i];
      i++;
    } else {
      arr[k] = aux[j];
      j++;
    }
  }
}
