#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
  stringstream ss;
  int a = 10;
  int* p = &a;

  ss << a << ", p = " << p << endl;

  cout << ss.str();

  string n = "";
  float f = 0.0f;
  try {
    f = stof(n);
  } catch (std::exception& e) {
    f = 0.0f;
  }
  cout << "f = " << f << endl;
}
