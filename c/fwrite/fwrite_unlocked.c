// https://blog.csdn.net/qu1993/article/details/109382285


#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>
 
#define THREAD_NUM 5
 
FILE *fp;
pthread_t tid[5];
const char *str = "hello world\n";
 
void *func(void *arg)
{
    struct timeval t1;
    struct timeval t2;
    gettimeofday(&t1, NULL);
    for (int i = 0; i < 100000; i++)
    {
        fwrite_unlocked(str, 1, 12, fp);
    }
    gettimeofday(&t2, NULL);
    long us = (t2.tv_sec-t1.tv_sec)*1000000+t2.tv_usec - t1.tv_usec; 
    printf("time_func=%ld\n", us);
    return NULL;
}
 
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("%s file_name\n", argv[0]);
        return 1;
    }
    const char *file_name = argv[1];
    fp = fopen(file_name, "ae");
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&tid[i], NULL, func, NULL);
    }
 
    for (int i = 0; i < 5; i++)
    {
        pthread_join(tid[i], NULL);
    }

    return 0;
}