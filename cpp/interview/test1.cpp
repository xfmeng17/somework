#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int func(vector<int> inputs, int N, int K) {
	sort(inputs.begin(), inputs.end());
	vector<int> seg;
	int cur = inputs[0];
	int cnt = 1;
	seg.emplace_back(1);
	for (int i = 1; i < inputs.size(); i++) {
		if (inputs[i] - cur <= 2) {
			seg[seg.size()-1]++;
		} else {
			seg.emplace_back(1);
		}
		cur = inputs[i];
	}

	for (int i = N/K; i >= 1; i--) {
		int num = 0;
		for (auto s : seg) {
			num += s / i;
		}
		if (num >= K) {
			return i;
		}
	}
	return -1;
}


int main() {
  int T = 0;
  cin >> T;
  while (T-- > 0) {
    int N = 0, K = 0;
    vector<int> inputs;
    cin >> N >> K;
    if (N <= 0 || K <= 0) {
        cout << -1 << endl;
        continue;
    }
    for (int i = 0; i < N; i++) {
       int n = 0;
       cin >> n;
       inputs.emplace_back(n);
    }
    cout << func(inputs, N, K) * K << endl;
  }

  return 0;
}
