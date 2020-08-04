// gcc -fpic -c first_one.c
// gcc --share first_one.o -o libfirst_one.so

#include <stdio.h>
void print_message() { printf("the first lib~~\n"); }
void first() { printf("init first\n"); }
