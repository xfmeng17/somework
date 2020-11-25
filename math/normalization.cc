#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {

	vector<float> vec1(16, 1.0);
	for (size_t i = 0; i < vec1.size(); i++) {
		vec1[i] = vec1[i] + 0.01 * i;
	}
	
}
