#include <atomic>
#include <chrono>
#include <functional>
#include <iostream>
#include <thread>
#include <utility>

void f1(int n) {
  std::cout << "f1(), n=" << n << std::endl;
  for (int i = 0; i < 1; ++i) {
    std::cout << "f1(), i= " << i << " executing\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
  std::cout << "f1() end!" << std::endl;
}

void f2(int& n) {
  std::cout << "f2(), n=" << n << std::endl;
  for (int i = 0; i < 5; ++i) {
    ++n;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
  std::cout << "f2() end!" << std::endl;
}

int main() {
  int n = 0;
  std::thread t1;                   // t1 is not a thread
  std::thread t2(f1, n + 1);        // pass by value
  std::thread t3(f2, std::ref(n));  // pass by reference
  std::thread t4(
      std::move(t3));  // t4 is now running f2(). t3 is no longer a thread
  t2.join();
  t4.join();
  std::cout << "Final value of n is " << n << '\n';
}
