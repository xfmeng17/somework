#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int T = 0;
  cin >> T;
  while (T-- > 0) {
    int n = 0;
    cin >> n;
	if (n <= 3) {
		cout << 1 << endl;
	} else {
		cout << 1 + (n - 2) / 2 << endl;
	}
  }
  return 0;
}
