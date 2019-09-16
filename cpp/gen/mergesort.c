#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static void msort(int *arr, int *aux, int lo, int hi);
static void merge(int *arr, int *aux, int lo, int mid, int hi);

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Usage: ./a.out inputfile\n");
		return(0);
	}
	
	FILE *fp = NULL;
	printf("argc[1] = %s\n", argv[1]);
	if (fopen(argv[1], "r") == NULL) {
		printf("fopen error\n");
		return(0);
	}
	int N = 0;
	fscanf(fp, "%d\n", &N);
	printf("N = %d\n", N);
	if (N <= 0) {
		printf("Empty input file with N = %d\n", N);
		return(0);
	}
	int *arr = (int*)malloc(sizeof(int) * N);
	int *aux = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		fscanf(fp, "%d", &arr[i]);
	}
	fclose(fp);
	msort(arr, aux, 0, N-1);

	if (fopen("sorted.out", "w") == NULL) {
		printf("fopen sorted.out error\n");
		return(0);
	}
	fprintf(fp, "%d\n", N);
	for (int i = 0; i < N; i++) {
		fprintf(fp, "%d ", arr[i]);
	}
	return(0);
}

static void msort(int *arr, int *aux, int lo, int hi) {
	if (hi <= lo) {
		return;
	}
	int mid = lo + (hi - lo) / 2;
	msort(arr, aux, lo, mid);
	msort(arr, aux, mid+1, hi);
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

