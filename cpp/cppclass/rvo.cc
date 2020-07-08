#include <iostream>

struct C {
  C(int j) {
    i = j;
    std::cout << "A XXXX was made.\n";
	std::cout << "this=" << this << std::endl;
  }
  C(const C& copy) {
	std::cout << "A copy was made.\n";
	std::cout << "copy_p=" << &copy << " | " << "this=" << this << std::endl;
  }

  int i;
};

C f() { return C(0); }

C f(bool cond) {
  C first(101);
  C second(102);
  // the function may return one of two named objects
  // depending on its argument. RVO might not be applied
  return cond ? first : second;
}

int main() {
  std::cout << "Hello World!\n";
  C obj0 = f();
  std::cout << "obj0=" << &obj0 << std::endl;
  std::cout << std::endl;
  
  C obj1 = f(true);
  std::cout << "obj1=" << &obj1 << std::endl;
  std::cout << std::endl;

  C obj2(2);
  obj2 = f(true);
  std::cout << "obj2=" << &obj2 << std::endl;
}
