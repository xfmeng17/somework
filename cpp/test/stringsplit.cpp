#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void print(vector<string>& arr);
vector<string> split(string str, char del);
vector<string> ssplit(string str, string del);

int main() {
  string test1 = "^901^0^1";
  string test2 = "a^b^c^d^";

  vector<string> ret1 = split(test1, '^');
  print(ret1);

  vector<string> ret2 = split(test2, '^');
  print(ret2);

  vector<string> ret3 = ssplit(test1, "^");
  print(ret3);

  vector<string> ret4 = ssplit(test2, "^");
  print(ret4);
}

void print(vector<string>& arr) {
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << ", ";
  }
  cout << "size=" << arr.size() << endl;
}

vector<string> split(string str, char del) {
  stringstream ss(str);
  string item;
  vector<string> ret;

  while (getline(ss, item, del)) {
    ret.emplace_back(item);
  }
  return ret;
}

std::vector<std::string> ssplit(std::string text, std::string delimeter) {
  std::vector<string> ret;
  int lo = 0;
  int hi = 0;
  while ((hi = text.find(delimeter, lo)) < text.length()) {
    std::string item = text.substr(lo, hi - lo);
    ret.emplace_back(item);
    lo = hi + delimeter.length();
  }
  if (lo < text.length()) {
    std::string item = text.substr(lo);
    ret.emplace_back(item);
  }
  return ret;
}
