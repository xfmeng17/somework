#include <iostream>
#include <sstream>
#include <string>

using namespace std;

const std::string get() {
  std::string x = "xxxx";
  return x;
}

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

  string x = {};
  cout << "x=" << x << endl;

  std::string aaa = get();
  cout << aaa << endl;

  std::cout << "sizeof(std::string)=" << sizeof(std::string) << std::endl;
}
