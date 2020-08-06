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
	if (n <= 0) {
		cout << "Good luck and Enjoy TPC!" << endl;
	} else {
		cout << "You are the future of Tencent!" << endl;
	}
  }
  return 0;
}
