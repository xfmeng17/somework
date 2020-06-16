#include <iostream>
#include <memory>

using namespace std;

class Student : public enable_shared_from_this<Student> {
 public:
  Student() {}
  ~Student() { cout << "~Student() called" << endl; }
  string name;
  void setName(string name);
  string getName();
};

void Student::setName(string name) { this->name = name; }

string Student::getName() { return name; }

int main() {
  int *p = new int(10);

  // std::shared_ptr<int> ptr = p;这样赋值是错误的额,只要是智能指针,
  // 这样直接用=赋值是有问题的必须std::shared_ptr<int> ptr(p);
  shared_ptr<int> ptr(p);
  shared_ptr<int> ptr1 = make_shared<int>(15);
  shared_ptr<int> ptr2(ptr1);

  std::cout << "ptr.use_count() is:" << ptr.use_count() << "  *ptr is:" << *ptr
            << std::endl;
  std::cout << "ptr1.use_count() is:" << ptr1.use_count()
            << "  *ptr1 is:" << *ptr1 << std::endl;
  std::cout << "ptr2.use_count() is:" << ptr2.use_count()
            << "  *ptr2 is:" << *ptr2 << std::endl;

  ptr2.reset();
  // 这是时候ptr2已经销毁,指向的对象引用计数会减1,这个指针的不再指向任何对象
  // 所以我们不能使用*ptr2了,下面一行代码使用肯定会报错,我先注释掉
  // std::cout << "ptr2.use_count() is:" << ptr2.use_count() << "*ptr2 is:" <<
  // *ptr2 << std::endl;
  std::cout << "ptr1.use_count() is:" << ptr1.use_count()
            << "   *ptr1 is:" << *ptr1 << std::endl;
  Student *stu = new Student();
  shared_ptr<Student> ptr_stu(stu);
  string name = "test";
  ptr_stu->setName(name);
  string result = ptr_stu->getName();
  std::shared_ptr<Student> ptr_stu_1;
  ptr_stu_1 = ptr_stu;
  cout << "ptr_stu.use_count() is:" << ptr_stu.use_count() << endl;
  cout << "my name is:" << result << endl;
  return 0;
}
