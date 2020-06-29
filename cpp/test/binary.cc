#include <iostream>
#include <vector>
using namespace std;
int64_t floor_pow_2(int64_t n) {
  if (n <= 0) {
    return 0;
  }

  int64_t p = 1;
  while (p <= n) {
    p *= 2;
  }
  cout << "n=" << n << ",p=" << p / 2 << endl;
  return p / 2;
}

int main(int argc, char** argv) {
  int64_t n = std::stoi(argv[1]);
  vector<int64_t> result;
  while (n > 0) {
    int64_t p = floor_pow_2(n);
    result.push_back(p);
    n -= p;
  }

  for (size_t i = 0; i < result.size(); i++) {
    cout << result[i] << ", ";
  }
  cout << endl;
  return 0;
}
