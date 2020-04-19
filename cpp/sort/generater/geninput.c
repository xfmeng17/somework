// generate random number
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MIN_NUM = 1;
const int MAX_NUM = 1000000;

int main(int argc, char *argv[]) {
  // printf("Usage: ./genrn.out min_num max_num\n");
  int min = 0, max = 0;
  if (argc < 3) {
    min = MIN_NUM;
    max = MAX_NUM;
  } else {
    min = atoi(argv[1]);
    max = atoi(argv[2]);
    if (min >= max) {
      printf("Usage: min_num=%d must less than max_num=%d!\n", min, max);
      exit(-1);
    }
  }

  int num = max - min + 1;
  int *arr = (int *)malloc(sizeof(int) * num);
  for (int i = 0; i < num; i++) {
    arr[i] = i + min;
  }

  srand((unsigned)time(NULL));
  for (int i = num - 1; i >= 0; i--) {
    int j = rand() % (i + 1);
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
  }
  printf("%d\n", num);
  for (int i = 0; i < num; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return (0);
}
