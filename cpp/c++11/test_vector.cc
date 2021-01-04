#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

class Person {
 public:
  Person(char* name, int age) {
    cout << "Person()" << endl;
    pName = new char[strlen(name) + 1];
    strncpy(pName, name, strlen(name) + 1);
    mAge = age;
	arrLen = 10;
	array = (int*)malloc( arrLen*sizeof(int) );
	for (int i = 0; i < arrLen; i++) {
		array[i] = i * 10;
		cout << array[i] << " ---- " << endl; 
	}
	cout << "pName=" << pName << ",mAge=" << mAge << ", pName point=" << &pName<< ", array3=" << array[3] << endl;
	printf("array_p=%p\n", array);
  }
  // 增加拷贝构造函数
  // Person(const Person& p) {
  //   this->pName = new char[strlen(p.pName) + 1];
  //   strncpy(this->pName, p.pName, strlen(p.pName) + 1);
  //   this->mAge = p.mAge;
  // }
  // // 重载 operator=操作符
  // Person& operator=(Person& p) {
  //   if (this->pName == NULL) {
  //     delete[] this->pName;
  //   }
  //   this->pName = new char[strlen(p.pName) + 1];
  //   strncpy(this->pName,p.pName, strlen(p.pName) + 1);
  //   this->mAge = p.mAge;
  //   return *this;
  // }
  ~Person() {
    cout << "~Person() pName=" << pName << ",mAge=" << mAge << ", pName point=" << &pName<< endl;
    if (pName != NULL) {
      delete pName;
	  // pName = NULL;
    }
	for (int i = 0; i < arrLen; i++) {
		array[i] = (i + 1) * 10000;
	}
	if (array != NULL) {
		free(array);
	}
  }

 public:
  char* pName;  // 指针容易浅拷贝的问题
  int mAge;
   int arrLen;  // 数组长度
   int *array;  // 数组指针
};

void test01(vector<Person>& vPerson) {
  Person a("abcd", 20);
  vPerson.push_back(a);
}

int main() {
  vector<Person> vPerson;
  test01(vPerson);
  for (auto& v : vPerson) {
	cout << "vPerson:" << endl;
	cout << "pName=" << v.pName << ",mAge=" << v.mAge << ", pName point=" << &(v.pName) << ", array3=" << v.array[3] << endl;
	printf("array_p=%p\n", v.array);
	printf("array_p=%d\n", *(v.array+2));
  }
  return 0;
}
