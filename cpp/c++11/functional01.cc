// https://www.sczyh30.com/posts/C-C/cpp-stl-functional/

#include <functional>
#include <iostream>

double f(int x, char y, double z) { return x + y + z; }

void print_num(int num) { std::cout << num << std::endl; }

struct Dog {
  int id;
  explicit Dog(int id) : id(id) {}
  void print_add(int i) const { std::cout << id + i << std::endl; }
};

class PrintString {
 public:
  void operator()(std::string &&s) const { std::cout << s << std::endl; }
};

void func_muti(int a, std::string &&b, const char *c, double d, char e) {
  std::cout << a << ", " << b << ", " << c << ", " << d << ", " << e << "\n";
}

int main(int argc, char **argv) {
  // common function
  std::function<void(int)> func_display_num = print_num;
  func_display_num(9);
  // common function
  std::function<double(int, char, double)> func_display = f;
  std::cout << func_display(3, 'a', 1.7) << "\n";
  // lambda expression
  std::function<void(const char *)> lbd_dsp_str = [](const char *s) {
    std::cout << s << std::endl;
  };
  lbd_dsp_str("Scala");
  // bind expression
  auto func_num_bind = std::bind(&f, std::placeholders::_1, 'c', 2.4);
  std::cout << func_num_bind(24) << "\n";
  // function object
  std::function<void(std::string &&)> func_obj_print = PrintString();
  func_obj_print("C++ 17 Nice!");
  // function object, 其实不是函数对象，就是和下面一样的成员函数了
  PrintString ps;
  std::function<void(const PrintString&, std::string &&)> func_obj_print_1 = &PrintString::operator();
  func_obj_print_1(ps, "C++ 17 Nice!");
  // member function
  const Dog dog(2424);
  std::function<void(const Dog &, int)> func_mem_display_num = &Dog::print_add;
  func_mem_display_num(dog, 24);
	
  // 下面这个会报错
  // std::function<void(int)> func_xx = Dog::print_add;
  // func_xx(23);

  // bind
  std::function<void(std::string && b, double d)> f =
      std::bind(&func_muti, 24, std::placeholders::_1, "Haha",
                std::placeholders::_2, 'P');
  f("XXXX", 22.2222);
  return 0;
}
