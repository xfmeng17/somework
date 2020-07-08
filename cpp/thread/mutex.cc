#include <iostream>  // std::cout
#include <mutex>     // std::mutex
#include <thread>    // std::thread

volatile int counter(0);  // non-atomic counter
std::mutex mtx;           // locks access to counter

void attempt_10k_increases(int i) {
  std::cout << "i = " << i << std::endl;
  for (int i = 0; i < 10000; ++i) {
    if (mtx.try_lock()) {  // only increase if currently not locked:
      ++counter;
      mtx.unlock();
    }
  }
}

int main(int argc, const char* argv[]) {
  std::thread threads[10];
  for (int i = 0; i < 10; ++i)
    threads[i] = std::thread(attempt_10k_increases, i);

  for (auto& th : threads) th.join();
  std::cout << counter << " successful increases of the counter.\n";

  return 0;
}
