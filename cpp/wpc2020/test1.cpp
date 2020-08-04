#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int T = 0;
  cin >> T;
  while (T-- > 0) {
    string ipv6 = "";
    cin >> ipv6;

    vector<string> vec;
    size_t lo = 0;
    size_t hi = 0;
    while ((hi = ipv6.find(':', lo)) != std::string::npos) {
      vec.push_back(ipv6.substr(lo, hi - lo));
      lo = hi + 1;
    }

    string result = "";
    for (auto s : vec) {
      if (s.size() == 4) {
        result += s;
      } else if (s.size() > 0) {
        for (int i = 0; i < 4 - s.size(); i++) {
          result += "0";
        }
        result += s;
      } else {
        result += "0000";
      }
      result += ":";
    }

    return result.substr(0, result.length() - 1);
  }

  return 0;
}
