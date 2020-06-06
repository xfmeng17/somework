#include <iostream>

using namespace std;

int main() {
	int a = 1;
	void* p0 = &a;
	void* p1 = &p0;
	void* p2 = &p1;
	void* p3 = &p2;
	cout << "p0=" << p0 << endl;
	cout << "p1=" << p1 << endl;
	cout << "p2=" << p2 << endl;
	cout << "p3=" << p3 << endl;
	int cnt = 0;
	cout << endl;
	void* p = &a;
	while (p) {
		cout << "p" << cnt << "=" << p << endl;
		p = &p;
		if (cnt++ > 5) {
			break;
		}
	}
	return 0;
}
