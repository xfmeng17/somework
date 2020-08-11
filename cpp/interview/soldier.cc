// n个士兵准备阅兵仪式，每个士兵的身高用a[]0,a[1]...a[n]表示
// 现在要选出一部分士兵 组成k行参加阅兵，要求：
// (1)每一行士兵数相同
// (2)每一行士兵身高差不多于2
// 问最多可以选出多少士兵

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int func(vector<int>& inputs, int N, int K);

int func1(vector<int>& inputs, int N, int K);
bool check1(vector<int>& inputs, int N, int K, int len);

int func2(vector<int>& inputs, int N, int K);
bool check2(vector<int>& inputs, int N, int K, int len);

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
    cout << "func1(): " << func1(inputs, N, K) << endl;
    cout << "func2(): " << func2(inputs, N, K) << endl;
    cout << "========" << endl;
  }

  return 0;
}

int func1(vector<int>& inputs, int N, int K) {
  sort(inputs.begin(), inputs.end());
  // TODO binery search optimize
  for (int i = N / K; i >= 1; i--) {
    if (check1(inputs, N, K, i)) {
      return i * K;
    }
  }
  return -1;
}

bool check1(vector<int>& inputs, int N, int K, int len) {
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

int func2(vector<int>& inputs, int N, int K) {
  sort(inputs.begin(), inputs.end());
  int lo = 1;
  int hi = N / K;
  int mid = (lo + hi) / 2;
  while (lo <= hi) {
    if (check2(inputs, N, K, mid)) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
    mid = (lo + hi) / 2;
  }
  if (lo <= N / K && check2(inputs, N, K, lo)) {
    return lo * K;
  }
  if (hi >= 1 && check2(inputs, N, K, hi)) {
    return hi * K;
  }

  // for (int i = N / K; i >= 1; i--) {
  //   if (check2(inputs, N, K, i)) {
  //     return i * K;
  //   }
  // }
  return -1;
}
bool check2(vector<int>& inputs, int N, int K, int len) {
  if (len <= 1) {
    return K <= N;
  }
  int final_num = 0;
  int i = 0;
  while (i + len <= inputs.size()) {
    if (inputs[i + len - 1] - inputs[i] <= 2) {
      final_num++;
      i += len;
    } else {
      i += 1;
    }
  }
  return final_num >= K;
}
// Error solution
int func(vector<int>& inputs, int N, int K) {
  sort(inputs.begin(), inputs.end());
  vector<int> seg;
  int cur = inputs[0];
  int cnt = 1;
  seg.emplace_back(1);
  for (int i = 1; i < inputs.size(); i++) {
    if (inputs[i] - cur <= 2) {
      seg[seg.size() - 1]++;
    } else {
      seg.emplace_back(1);
      cur = inputs[i];
    }
  }

  for (int i = N / K; i >= 1; i--) {
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
