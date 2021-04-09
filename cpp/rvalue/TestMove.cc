#include <iostream>

using namespace std;

struct Foo {
  Foo(int _i) {
    i = _i;
    cout << "Constructed, i=" << i << endl;
  }
  Foo(const Foo &) { cout << "Copy-constructed" << endl; }
  Foo(Foo &&) { cout << "Move-constructed" << endl; }
  ~Foo() { cout << "Destructed" << endl; }
  Foo &operator=(Foo &&other) {
    cout << "Move-assign" << endl;
    i = other.i;
  }
  int i = 1;
};

int main() {
  Foo f1(10);
  Foo f2(20);

  cout << "f1.add" << &f1 << endl;
  cout << "f2.add" << &f2 << endl;

  Foo f3(std::move(f1));

  cout << f1.i << endl;
  cout << f2.i << endl;
  cout << f3.i << endl;

  cout << "f1.add" << &f1 << endl;
  cout << "f2.add" << &f2 << endl;
  cout << "f3.add" << &f3 << endl;
}
