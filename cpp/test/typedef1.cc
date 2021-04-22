#include <iostream>

typedef int INT;

const static int x = 0;

int print1() {
  std::cout << "print1=" << sizeof(INT) << std::endl;
  return 1;
};
