#include <iostream>

int main() {
	int a = 10;
	int b = 1;
	int c = 2;
	int d = c - 2*b;
	int e = 0;
	try {
		e = a / d;
	} catch (...) {
		std::cerr << "catch" << std::endl;
	}
	return 0;
}
