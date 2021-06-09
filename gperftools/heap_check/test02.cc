#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>

char* get_buffer(size_t size) {
    char *buffer = (char *)malloc(size);  // 这里分配了内存，但后面 leak_memory 函数使用完之后没有释放，造成内存泄漏。
    memset(buffer, 0, size);
    return buffer;
}

void leak_memory() {
    char *buffer = get_buffer(1024 * 1024);
    sprintf(buffer, "do something with buffer");
    // printf("%s\n", buffer);
}

int main() {
    printf("tcmalloc test");
    int num = 10;
    int cnt = 0;
    
    while (cnt++ <= num) {
        leak_memory();
        sleep(1);
    }

    return 0;
}