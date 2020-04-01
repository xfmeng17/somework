#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
  stringstream ss;
  int a = 10;
  int *p = &a;

  ss << a << ", p = " << p << endl;

  cout << ss.str();
}
