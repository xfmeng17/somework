#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	string str = "11111111111111111111111111111111111111111111111111111111111111111111111111";
	stringstream ss;
	ss << str;

	int i = 0;
	ss >> i;

	cout << "i = " << i << endl;

	return 0;
}
