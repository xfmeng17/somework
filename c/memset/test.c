//memset将内存的前n个字节设置为特定的值
//http://c.biancheng.net/cpp/html/157.html
#include <memory.h>
#include <stdio.h>
//#include <string.h>

int grid[110];
int main() {
  memset(grid, 5, 100 * sizeof(int));
  printf("sizeof(int)=%ld\n", sizeof(int));
  printf("%08d\n", grid[0]);
  printf("%08x\n", grid[0]);
  printf("%02d\n", 10);
  printf("%02x\n", 10);
  return 0;
}
