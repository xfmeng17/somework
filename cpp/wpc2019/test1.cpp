#include <iostream>

using namespace std;

int main() {
	int T = 0;
	cin >> T;
	while (T-- > 0) {
		int n = 0, b = 0;
		cin >> n >> b;
		cout << "n=" << n << ", b=" << b << endl;
		bool ret = false;
		int a = 0;
		for (int i = 0; i < n; i++) {
			cin >> a;
			cout << a << " ";
			if (a > 0 && ((a + b) % 7 == 0)) {
				ret = true;
			}
		}
		cout << "ret=" << ret << endl;
		if (ret) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}
