// tLinux2.2 gcc verison 7.3.1
// g++ -g -O0 addr.cc
// ./a.out        -> 赋值的长度len默认为18
// ./a.out <len>  -> 输入赋值的长度len

#include <iostream>
#include <stdint.h>
#include <string>

class Test {
  public:
    uint64_t a;
    char* b;
    std::string c;
    double d;
    ~Test() {
      std::cout << "~Test(),a="<< a << ",b=" << b << ",c=" << c << ",c.size=" << c.size() << ",d=" << d << std::endl;
    }
  public:
    void print() {
      std::cout << "class Test print()" << std::endl;
    }
};

int main (int argc, char** argv) {
  std::cout << "sizeof(Test)=" << sizeof(Test) << std::endl;

  Test t2;
  t2.a = 123;
  t2.b = "X";
  t2.c = "ABCD";
  t2.d = 4.44;

  std::cout << "sizeof(t2)=" << sizeof(t2) << std::endl;

  void* p = &t2;
  std::cout << "t2_p=" << (void *)p << std::endl;
  std::cout << "p_a=" << (void*)((char*)p) <<  ",a=" << *((uint64_t*)p) << std::endl;
  std::cout << "p_b=" << (void*)((char*)p+8) << ",b=" << *((char*)p+8) << std::endl;
  std::cout << "p_d=" << (void*)((char*)p+24) << ",d=" << *(double*)((char*)p+24) << std::endl;

  void* p_c = ((char*)p)+16;
  uint64_t p_c_addr = *((uint64_t*)(p_c));
  char *p_c_char = (char*)p_c_addr;
  std::cout << &p_c_addr << std::endl;
  std::cout << "p_c=" << p_c << ",p_c_addr=" << p_c_addr << ",(void*)p_c_char=" << (void*)p_c_char << ",p_c_char=" << p_c_char << std::endl;

  // ???? 小于等于18不会coredumo，大于18就会，为啥啊！！
  int len = 18; 
  if (argc >= 2) {
    len = atoi(argv[1]);
  }
  std::cout << "len=" << len << std::endl;

  for (int i = 0; i < len; i++) {
    p_c_char[i] = ('a' + i);
    std::cout << p_c_char[i];
  }
  std::cout << std::endl;

  for (int i = 0; i < 4; i++) {
    std::cout << "p_c_char[" << i << "].addr=" << (void*)&(p_c_char[i]) << ",value=" << p_c_char[i] << std::endl;
  }

  std::string str(p_c_char, len);
  // ???? 为什么str得值和上面打印得p_c_char的值对不上，并且str打印的长度是17
  // str=abcdefghijklmnopA
  // str.size=18
  std::cout << "str=" << str << std::endl;
  std::cout <<"str.size=" << str.size() <<std::endl;

  return 0;
}
