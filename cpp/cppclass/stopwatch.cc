#include <iomanip>
#include <iostream>
using namespace std;

//秒表类
class stopwatch {
 public:
  stopwatch() : m_min(0), m_sec(0) { cout << "stopwatch()" << endl; }

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
  return *this;
}

stopwatch stopwatch::operator++() { return run(); }

stopwatch stopwatch::operator++(int n) {
  stopwatch s = *this;
  run();
  return s;
}

ostream &operator<<(ostream &out, const stopwatch &s) {
  out << setfill('0') << setw(2) << s.m_min << ":" << setw(2) << s.m_sec;
  return out;
}

int main() {
  stopwatch s1, s2;

  s1 = s2++;
  cout << "s1: " << s1 << endl;
  cout << "s2: " << s2 << endl;
  s1.setzero();
  s2.setzero();

  s1 = ++s2;
  cout << "s1: " << s1 << endl;
  cout << "s2: " << s2 << endl;
  return 0;
}
