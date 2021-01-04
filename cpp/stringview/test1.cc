#include <iostream>
#include <string>
#include <string_view>

using namespace std;

int main() {
	string s = "1234567890";

	string_view sv1 = s;
	string_view sv2 = s;

	cout << (sv1 == sv2) << endl;
	
	sv1.remove_prefix(1);
	sv2.remove_suffix(3);

	cout << "sv1 size" << sv1.size() << endl;
	cout << "sv2 size" << sv2.size() << endl;

	cout << "equal? " << (sv1 == sv2) << endl;

	return 0;
}
