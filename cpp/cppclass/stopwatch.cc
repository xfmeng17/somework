#include <iomanip>
#include <iostream>
using namespace std;

//秒表类
class stopwatch {
 public:
  stopwatch() : m_min(0), m_sec(0) { cout << "stopwatch()" << endl; }
  stopwatch(const stopwatch &copy) {
    m_min = copy.m_min;
    m_sec = copy.m_sec;
    cout << "copy() this=" << this << ",value" << *this;
    cout << " | copy=" << &copy << ",value" << copy << endl;
  }

 public:
  void setzero() {
    m_min = 0;
    m_sec = 0;
  }
  stopwatch run();            // 运行
  stopwatch operator++();     //++i，前置形式
  stopwatch operator++(int);  // i++，后置形式
  friend ostream &operator<<(ostream &, const stopwatch &);

 private:
  int m_min;  //分钟
  int m_sec;  //秒钟
};

stopwatch stopwatch::run() {
  ++m_sec;
  if (m_sec == 60) {
    m_min++;
    m_sec = 0;
  }
  cout << "++m_sec" << endl;
  cout << "run() this=" << this << endl;
  return *this;
}

stopwatch stopwatch::operator++() { return run(); }

stopwatch stopwatch::operator++(int n) {
  stopwatch s = *this;
  cout << "p_this=" << this << endl;
  cout << "p_s=" << &s << endl;
  cout << "stopwatch s = *this" << endl;
  run();
  cout << "i++ after run()" << endl;
  s.m_min = 88;
  return s;
}

ostream &operator<<(ostream &out, const stopwatch &s) {
  out << setfill('0') << setw(2) << s.m_min << ":" << setw(2) << s.m_sec;
  return out;
}

int main() {
  stopwatch s1, s2;
  cout << "s1: " << s1 << " ps1: " << &s1 << endl;
  cout << "s2: " << s2 << " ps2: " << &s2 << endl;
  cout << endl;

  s1 = s2++;
  cout << "s1: " << s1 << " ps1: " << &s1 << endl;
  cout << "s2: " << s2 << " ps2: " << &s2 << endl;
  s1.setzero();
  s2.setzero();
  cout << endl;

  s1 = ++s2;
  cout << "s1: " << s1 << " ps1: " << &s1 << endl;
  cout << "s2: " << s2 << " ps2: " << &s2 << endl;
  return 0;
}

// 39行return *this和52行return s都发生了拷贝
//但是外面66行和73行的赋值，都没有发生拷贝
//只是把临时对象内的值，赋给了外面的对象
