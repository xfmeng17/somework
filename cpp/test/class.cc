#include <iostream>

class T {
	public:
		int a_;
		int b_;
	public:
		T(int a) : a_(a) {}
};

int main() {
	// T t(1);
	T t();
	std::cout << t.a_ << ", " << t.b_ << std::endl;
}
