#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool helper1(vector<int>& inputs, int N, int size, int num);

int func(vector<int>& inputs, int N, int K) {
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
			cur = inputs[i];
		}
	}

	for (int i = N/K; i >= 1; i--) {
		int num = 0;
		for (auto s : seg) {
			num += s / i;
		}
		if (num >= K) {
			return i * K;
		}
	}
	return -1;
}

int func1(vector<int>& inputs, int N, int K) {
	sort(inputs.begin(), inputs.end());
	//TODO binery search optimize
	for (int i = N/K; i >= 1; i--) {
		if (helper2(inputs, N, i, K)) {
			return i * K;
		}
	}
	return -1;
}

bool helper1(vector<int>& inputs, int N, int size, int num) {
	if (size <= 1) {
		return num <= inputs.size();
	}

	int final_num = 0;
	int curr_size = 0;
	int curr_index = -1;
	for (int i = 0; i < inputs.size(); i++) {
		if (curr_size == 0) {
			curr_size = 1;
			curr_index = i;
			continue;
		}

		if (inputs[i] - inputs[curr_index] <= 2) {
			curr_size++;
			if (curr_size == size) {
				final_num++;
				curr_size = 0;
				curr_index = i;
			}
		} else {
			curr_size = 0;
			i = curr_index;
		}
	}

	return final_num >= num;
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
    // cout << func(inputs, N, K) << endl;
    cout << func1(inputs, N, K) << endl;
  }

  return 0;
}
