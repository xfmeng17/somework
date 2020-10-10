// https://yilingui.xyz/2019/07/10/190710_cpp_shared_object_pool/
#include <iostream>
#include <memory>

class Object {
  int a;
  char b;

 public:
  Object() { std::cout << "Object()" << std::endl; }
  ~Object() { std::cout << "~Object()" << std::endl; }
};

int main(int argc, char **argv) {
  Object *obj1 = new Object();
  bool obj1_deleted = false;
  std::shared_ptr<Object> p1(obj1, [&obj1_deleted](Object *p) {
    if (p && !obj1_deleted) {
      delete p;
      p = nullptr;
      obj1_deleted = true;
      std::cout << "delete p1\n";
    }
  });
  std::cout << p1.use_count() << std::endl;
  std::shared_ptr<Object> p2(obj1, [&obj1_deleted](Object *p) {
    if (p && !obj1_deleted) {
      delete p;
      p = nullptr;
      obj1_deleted = true;
      std::cout << "delete p2\n";
    }
  });
  std::cout << p2.use_count() << std::endl;
  return 0;
}
