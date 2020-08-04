// gcc -fpic -c second_one.c
// gcc --share second_one.o -o libsecond_one.so

#include <stdio.h>
void print_message() { printf("the second lib~~\n"); }

void second() { printf("init second \n"); }
