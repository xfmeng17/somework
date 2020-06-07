#include <stdio.h>

int dummy(int n) {
	printf("n=%d\n", n);
	char str[1024 * 1024 * 4];
	if (n > 0) {
		dummy(n--);
	}
	return 0;
}

int main() {
	int n = 100000;
	dummy(n);
	return 0;
}
