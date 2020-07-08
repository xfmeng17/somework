#include "my_list.h"
#include <string>

struct student {
  std::string name;
  int age;

  student(std::string n, int a) : name(n), age(a) {}

  //重载输出操作符
  friend std::ostream &operator<<(std::ostream &os, const student &stu) {
    os << stu.name << " " << stu.age;
    return os;
  }
};

int main() {
  my_list<student> l;
  l.push_back(student("bob", 1));  //临时量作为实参传递给push_back方法
  l.push_back(student("allen", 2));
  l.push_back(student("anna", 3));
  l.print();

  for (my_list<student>::iterator it = l.begin(); it != l.end(); it++) {
    std::cout << *it << std::endl;
    *it = student("wengle", 18);
  }
  l.print();
  return 0;
}
