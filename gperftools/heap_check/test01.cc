#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* get_buffer(size_t size) {
    char *buffer = (char *)malloc(size);  // 这里分配了内存，但后面 leak_memory 函数使用完之后没有释放，造成内存泄漏。
    memset(buffer, 0, size);
    return buffer;
}

void leak_memory() {
    char *buffer = get_buffer(1024 * 1024);
    sprintf(buffer, "do something with buffer");
    printf("%s\n", buffer);
}

int main() {
    printf("tcmalloc test");
    for(int i=0; i < 10; i++) {
        leak_memory();
    }
    return 0;
}