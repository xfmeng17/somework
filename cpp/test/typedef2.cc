#include <iostream>

extern int print1();

const static int x = 0;

typedef int INT;

int print2() {
  std::cout << "print2=" << sizeof(INT) << std::endl;
  return 2;
}


int main () {
  print1();
  std::cout << "----------" << std::endl;
  print2();
}
