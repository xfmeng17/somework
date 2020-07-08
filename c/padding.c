#include <stdio.h>
#include <stdlib.h>
struct T {
	int a;
	char b;
	int c;
};
struct T t={ 10, 'C', 20 };

int main(){
	printf("length: %d\n", sizeof(t));
	printf("&a: %X\n&b: %X\n&c: %X\n", &t.a, &t.b, &t.c);
	
	struct T t0 = {11, 'A', 12};
    printf("t0: %d\n", sizeof(t0));

	system("pause");


	return 0;
}
