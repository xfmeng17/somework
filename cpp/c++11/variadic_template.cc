#include <iostream>
using namespace std;

template<class... T>
void func(T... args) {
	cout<<"num="<<sizeof...(args)<<endl;
}

int main() {
	func();
	func(1);
	func(2, 10.0);
	return 0;
}
