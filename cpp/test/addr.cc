#include <iostream>
#include <stdint.h>
#include <string>

typedef uint64_t Taddr;

void print_addr(Taddr addr) {
  for (int i = 0; i < 16; i++) {
    std::cout << *(char*)(addr+i);
  }
  std::cout << std::endl;
}

void test1() {
  Taddr addr1 = (Taddr)new(std::nothrow) char[16];
  for (int i = 0; i < 16; i++) {
    *(char*)(addr1 + i) = 'a' + i;
  }
  std::cout << "addr1=" << (void*)addr1 << ", val1:"; 
  print_addr(addr1);
  
  Taddr addr2 = (Taddr)new(std::nothrow) char[16];
  for (int i = 0; i < 16; i++) {
    *(char*)(addr2 + i) = 'A' + i;
  }
  std::cout << "addr2=" << (void*)addr2 << ", val2:"; 
  print_addr(addr2);

  Taddr* addr_p = (Taddr*)addr2;
  std::cout << "#1 addr_p=" << addr_p << ", *addr_p=" << *addr_p << std::endl;

  *addr_p = addr1;
  std::cout << "#2 addr_p=" << addr_p << ", *addr_p=" << *addr_p << std::endl;

  std::cout << "get addr1=";
  print_addr(*addr_p);
}

class T2 {
  public:
    uint64_t a;
    char b;
    std::string c;
    double d;
    
    ~T2() {
      std::cout << "~T2(),c=" << c << ",c.length=" << c.length() << std::endl;
    }

  public:
    void print() {
      std::cout << "class T2" << std::endl;
    }
};

void test2 () {
  T2 t2;
  std::cout << "T2 size=" << sizeof(T2) << std::endl;

  t2.a = 123;
  t2.b = 'b';
  t2.c = "ABC";
  t2.d = 7.89;

  std::cout << "t2 size=" << sizeof(t2) << std::endl;

  void* p = &t2;
  std::cout << "t2_p=" << (void *)p << std::endl;
  std::cout << "p10=" << (void*)((char*)p) <<  ",a=" << *((uint64_t*)p) << std::endl;
  std::cout << "p20=" << (void*)((char*)p+8) <<  ",b=" << *((char*)p+8) << std::endl;

  void* p_str = ((char*)p)+16;
  std::cout << "p_str(void*)=" << (void*)p_str << ",(uint64_t)=" << (uint64_t)p_str << std::endl; 
  uint64_t p_int = *((uint64_t*)(p_str));
  std::cout << "p_int(void*)=" << (void*)p_int << ",(uint64_t)=" << (uint64_t)p_int << std::endl;

  char *p_char = (char*)p_int;
  std::cout << "p_char=" << (void *)p_char << std::endl;
  p_char[0] = '0';
  p_char[1] = '1';
  p_char[2] = '2';
  p_char[3] = '3';
  // p_char[4] = '4';
  // p_char[5] = '5';
  // p_char[6] = '6';
  // p_char[7] = '7';
  for (int i = 3; i < 1000; i++) {
    // p_char[i] = ('a' + i) % 100;
  }

  std::cout << "p_char[0] addr=" << (void*)&(p_char[0]) << std::endl;
  std::cout << "p30=" << (void *)((char *)p + 16) << ",t2.c_to_string=" << std::string(((char *)p_int), 10) << std::endl;
  std::cout << "p40=" << (void*)((char*)p+24) <<  ",d=" << *(double*)((char*)p+24) << std::endl;
}

int main () {
  // std::cout << "string sizeof =" << sizeof(std::string) << std::endl;
  test2();
  return 0;
}
