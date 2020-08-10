#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int func(vector<int>& inputs, int N, int K);
int func1(vector<int>& inputs, int N, int K);
bool helper1(vector<int>& inputs, int N, int K, int len);
bool helper2(vector<int>& inputs, int N, int K, int len);

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

bool helper1(vector<int>& inputs, int N, int K, int len) {
	if (len <= 1) {
		return K <= N;
	}

	int final_num = 0;
	int curr_len = 0;
	int curr_idx = -1;
	for (int i = 0; i < inputs.size(); i++) {
		if (curr_len == 0) {
			curr_len = 1;
			curr_idx = i;
			continue;
		}

		if (inputs[i] - inputs[curr_idx] <= 2) {
			curr_len++;
			if (curr_len == len) {
				final_num++;
				curr_len = 0;
				curr_idx = i;
			}
		} else {
			curr_len = 0;
			i = curr_idx;
		}
	}

	return final_num >= K;
}

bool helper2(vector<int>& inputs, int N, int K, int len) {
	if (len <= 1) {
		return K <= N;
	}
	int final_num = 0;
	int i = 0;
	while (i + len <= inputs.size()) {
		if (inputs[i+len-1] - inputs[i] <= 2) {
			final_num++;
			i += len;
		} else {
			i += 1;
		}
	}
	return final_num >= K;
}


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
