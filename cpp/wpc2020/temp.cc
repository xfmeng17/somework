#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool check(const vector<int>& input_0, const vector<int>& input_1) {
  for (int i = 0; i < input_0.size(); i++) {
    if (input_0[i] >input_1[i]) {
      return false;
    }
  }

  return true;
}

int main() {
  int T = 0;
  cin >> T;
  while (T-- > 0) {
    int n = 0;
    cin >> n;
    if (n % 2 == 1) {
      cout << "Yes";
      if (T > 0) cout << "\n";
      continue;
    }

    std::vector<int> input_0;
    std::vector<int> input_1;
    for (int i = 0; i < n; i++) {
      int x = 0;
      cin >> x;
      if (i % 2 == 0) {
        input_0.emplace_back(x);
      } else {
        input_1.emplace_back(x);
      }
    }
    sort(input_0.begin(), input_0.end());
    sort(input_1.begin(), input_1.end());
    if (check(input_0, input_1)) {
      cout << "Yes";
    } else {
      cout << "No";
    }
    if (T > 0) cout << "\n";
  }
  return 0;
}
