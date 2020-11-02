#include <iostream>
#include <string>

#include "test.pb.h"

int main () {
	utf8::test t;
	t.set_s1("奇奇怪怪的"); 
	t.set_s2("\345\245\207\345\245\207\346\200\252\346\200\252\347\232\204");	
	std::cout << "DebugString:\n" << t.DebugString() << std::endl;
	std::cout << "Utf8DebugString:\n" << t.Utf8DebugString() << std::endl;
}
