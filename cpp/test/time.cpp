#include <stdio.h>
#include <time.h>

int main(void) {
  time_t now_time = time(NULL);
  printf("now_time=%ld\n", now_time);

  struct tm tm_now_time;
  localtime_r(&now_time, &tm_now_time);
  int tm_now_hour = tm_now_time.tm_hour;
  int tm_now_min = tm_now_time.tm_min;
  printf("tm_now_hour=%d, tm_now_min=%d\n", tm_now_hour, tm_now_min);

  return 0;
}
