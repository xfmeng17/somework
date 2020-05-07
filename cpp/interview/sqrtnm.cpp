#include <math.h>
#include <stdio.h>
#include <iostream>

double sqrt(int32_t n, int32_t m) {
	if (m < 0) {
		return 0.0;
	}
	double precision = pow(0.1, m+1);
	
	double target = (double)n + 0.0;
	double lo = 0.0;
	double hi = target;
	double mid = (lo + hi) / 2;

	while (abs(target - mid*mid) > precision) {
		if (mid*mid > target) {
			hi = mid;
		} else {
			lo = mid;
		}
		mid = (lo + hi) / 2;
	}

	return mid;
}

int main() {
	int n = 2;
	double r2 = sqrt(n, 2);
	printf("r2=%.2f,r2^=%.9f\n", r2, r2*r2);
	double r3 = sqrt(n, 3);
	printf("r3=%.3f,r3^=%.9f\n", r3, r3*r3);
	double r4 = sqrt(n, 4);
	printf("r4=%.4f,r4^=%.9f\n", r4, r4*r4);
	double r5 = sqrt(n, 5);
	printf("r5=%.5f,r5^=%.9f\n", r5, r5*r5);
	double r6 = sqrt(n, 6);
	printf("r6=%.6f,r6^=%.9f\n", r6, r6*r6);
	
	printf("r9=%0.9f\n", sqrt((double)n));
	return 0;
}
