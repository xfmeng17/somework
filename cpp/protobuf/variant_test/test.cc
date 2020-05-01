#include <iostream>
#include <string>
#include <vector>

#include "test.pb.h"

using namespace std;

int main() {
	tutorial::AddressBook ab;
	ab.set_a(10);
	cout << ab.Utf8DebugString();
	
	string ab_str = "";
	bool r = ab.SerializeToString(&ab_str);
	cout << "r=" << r << endl;
	cout << "ab_str=" << ab_str.c_str() << endl;
	vector<char> bytes(ab_str.begin(), ab_str.end());
	cout << "bytes.size()=" << bytes.size() << endl;
	for (auto b : bytes) {
		cout << (int)b << endl;
	}

	char ab_arr[256];
	for (int i = 0; i < 256; i++) {
		ab_arr[i] = '\0';
	}
	r = ab.SerializeToArray(ab_arr, 256);
	cout << "r=" << r << endl;
	cout << "strlen=" << strlen(ab_arr) << endl;
	int i = 0;
	while (ab_arr[i] != '\0') {
		cout << "i=" << i << ",v=" << (int)ab_arr[i] << endl;
		i++;
	}
	for (int j = 0; j < strlen(ab_arr); j++) {
		cout << "j=" << j << ",v=" << (int)ab_arr[j] << endl;
	}

	return 0;
}
