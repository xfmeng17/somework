#include <iostream>

using namespace std;

uint64_t mask55(uint64_t x) {
  static const uint64_t mask = ((uint64_t)1 << 55) - 1;
  cout << "mask = " << mask << endl;
  return x & mask;
}

int main() {
  uint64_t x = 1;
  uint64_t y = 0;
  y = mask55(x);
  cout << "y = " << y << endl;
}
