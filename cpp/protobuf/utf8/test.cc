#include <iostream>
#include <string>

#include "test.pb.h"

int main () {
	utf8::test t;
	std::string s1 = "奇奇怪怪的";
	std::string s2 = "\345\245\207\345\245\207\346\200\252\346\200\252\347\232\204";
	std::string s3 = "\105\106\204";
	std::cout << "s1=" << s1 << std::endl;
	std::cout << "s2=" << s2 << std::endl;
	std::cout << "s3=" << s3 << ",s3.length=" << s3.length() <<  std::endl;
	t.set_s1(s1); 
	t.set_s2(s2);	
	t.set_s3(s1);	
	std::cout << "DebugString:\n" << t.DebugString() << std::endl;
	std::cout << "Utf8DebugString:\n" << t.Utf8DebugString() << std::endl;
}
