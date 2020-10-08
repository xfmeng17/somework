// https://blog.csdn.net/weixin_41066529/article/details/89480260
#include <iostream>
#include <memory>
using namespace std;

void Check(weak_ptr<int> &wp) {
  shared_ptr<int> sp = wp.lock();  // 重新获得shared_ptr对象
  if (sp != nullptr) {
    cout << "The value is " << *sp << endl;
  } else {
    cout << "Pointer is invalid." << endl;
  }
}

int main() {
  shared_ptr<int> sp1(new int(10));
  shared_ptr<int> sp2 = sp1;
  weak_ptr<int> wp = sp1;  // 指向sp1所指向的内存

  cout << "*sp1=" << *sp1 << endl;
  cout << "*sp2=" << *sp2 << endl;
  Check(wp);

  sp1.reset();  // sp1清除,计数减一
  cout << "*sp2=" << *sp2 << endl;
  Check(wp);

  sp2.reset();  //清除sp2，计数减一，等于0；
  Check(wp);

  return 0;
}
