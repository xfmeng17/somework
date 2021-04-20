#include <iostream>
#include <stdint.h>

typedef uint64_t Taddr;

void print_addr(Taddr addr) {
  for (int i = 0; i < 16; i++) {
    std::cout << *(char*)(addr+i);
  }
  std::cout << std::endl;
}

int main () {

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

  return 0;
}