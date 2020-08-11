#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
  int T = 0;
  cin >> T;
  while (T-- > 0) {
	string s;
	cin >> s;
	
	int len = s.length();
	int cnt0 = 0;
	int cnt1 = 0;
	for (auto c : s) {
		if (c == '0') {
			cnt0++;
		} else {
			cnt1++;
		}
	}
	if (abs(cnt0 - cnt1) <= 1) {
		cout << 1 << " " << s.length() << endl;
		continue;
	}

	char p = cnt0 > cnt1 ? '0' : '1';
	int need_len = abs(cnt0 - cnt1) / 2;
	
	int curr_len = 0;
	int curr_idx = -1;
	int max_len = 0;
	int max_idx = -1;

	for (int i = 0; i < s.length(); i++) {
		if (curr_len == 0 && s[i] != p) {
			continue;
		}
		if (curr_len == 0 && s[i] == p) {
			curr_len = 1;
			curr_idx = i;
			if (curr_len > max_len) {
				max_len = curr_len;
				max_idx = curr_idx;
			}
			continue;
		}
		if (curr_len != 0 && s[i] == p) {
			curr_len++;
			if (curr_len > max_len) {
				max_len = curr_len;
				max_idx = curr_idx;
			}
			continue;
		}
		if (curr_len != 0 && s[i] != p) {
			if (curr_len > max_len) {
				max_len = curr_len;
				max_idx = curr_idx;
			}
			curr_len = 0;
			curr_idx = -1;
			continue;
		}
	}
	if (curr_len != 0) {
		if (curr_len > max_len) {
			max_len = curr_len;
			max_idx = curr_idx;
		}
	}

	int min_len = min(need_len, max_len);
	cout << max_idx + 1 << " " << max_idx + min_len << endl;
  
  }

  return 0;
}
