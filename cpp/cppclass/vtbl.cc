#include <iostream>
using namespace std;

int main(int argc, char const* argv[]) {
  class Base {
   public:
    virtual void vir_func() {
      cout << "virtual function, this is class Base" << endl;
    }
    void func() { cout << "normal function, this is class Base" << endl; }
  };
  class A : public Base {
   public:
    virtual void vir_func() {
      cout << "virtual function, this is class A" << endl;
    }
    void func() { cout << "normal function, this is class A" << endl; }
  };
  class B : public Base {
   public:
    virtual void vir_func() {
      cout << "virtual function, this is class B" << endl;
    }
    void func() { cout << "normal function, this is class B" << endl; }
  };

  Base* base = new (Base);
  Base* a = new (A);
  Base* b = new (B);
  base->func();
  a->func();
  b->func();
  cout << "====" << endl;
  base->vir_func();
  a->vir_func();
  b->vir_func();
  return 0;
}
