// https://www.cnblogs.com/DswCnblog/p/5629165.html
#include <iostream>

int main() {
  int a = 123;
  auto f1 = [&]() -> void { a = 1; };
  f1();
  std::cout << a << std::endl;

  auto f2 = [&]() { a = 2; };
  f2();
  std::cout << a << std::endl;
  
  auto f3 = [&] { a = 3; };
  f3();
  std::cout << a << std::endl;
  
  auto f4 = [=]mutable { a = 4; };
  f4();
  std::cout << a << std::endl;
}
