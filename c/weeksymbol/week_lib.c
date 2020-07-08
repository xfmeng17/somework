#include <stdio.h>

void foobar() __attribute__ ((weak));
void foobar(void)
{
	printf("libfoobar test\n");
}
