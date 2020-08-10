#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
  int T = 0;
  cin >> T;
  while (T-- > 0) {
    int N = 0, K = 0;
    vector<int> inputs;
    cin >> N >> K;
    if (N <= 0 || k <= 0) {
        cout << -1 << end;
        continue;
    }
    for (int i = 0; i < N; i++) {
       int n = 0;
       cin >> n;
       inputs.emplace_backn(n);
    }
    cout << func(input, N, K);
  }

  return 0;
}
