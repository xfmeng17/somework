#include <iostream>
using namespace std;

class complex {
 public:
  complex(double real = 0.0, double imag = 0.0) : m_real(real), m_imag(imag){};

 public:
  friend complex operator+(const complex &A, const complex &B);
  friend complex operator-(const complex &A, const complex &B);
  friend complex operator*(const complex &A, const complex &B);
  friend complex operator/(const complex &A, const complex &B);
  friend istream &operator>>(istream &in, complex &A);
  friend ostream &operator<<(ostream &out, complex &A);

 public:
  double m_real;  //实部
  double m_imag;  //虚部
};

//重载加法运算符
complex operator+(const complex &A, const complex &B) {
  complex C;
  C.m_real = A.m_real + B.m_real;
  C.m_imag = A.m_imag + B.m_imag;
  return C;
}

//重载减法运算符
complex operator-(const complex &A, const complex &B) {
  complex C;
  C.m_real = A.m_real - B.m_real;
  C.m_imag = A.m_imag - B.m_imag;
  return C;
}

//重载乘法运算符
complex operator*(const complex &A, const complex &B) {
  complex C;
  C.m_real = A.m_real * B.m_real - A.m_imag * B.m_imag;
  C.m_imag = A.m_imag * B.m_real + A.m_real * B.m_imag;
  return C;
}

//重载除法运算符
complex operator/(const complex &A, const complex &B) {
  complex C;
  double square = A.m_real * A.m_real + A.m_imag * A.m_imag;
  C.m_real = (A.m_real * B.m_real + A.m_imag * B.m_imag) / square;
  C.m_imag = (A.m_imag * B.m_real - A.m_real * B.m_imag) / square;
  return C;
}

//重载输入运算符
istream &operator>>(istream &in, complex &A) {
  in >> A.m_real >> A.m_imag;
  return in;
}

//重载输出运算符
ostream &operator<<(ostream &out, complex &A) {
  out << A.m_real << " + " << A.m_imag << " i ";
  ;
  return out;
}
ostream &operator<<(ostream &out, const complex &A) {
  out << A.m_real << " + " << A.m_imag << " i ";
  ;
  return out;
}

int main() {
  complex c1, c2, c3;
  cin >> c1 >> c2;

  c3 = c1 + c2;
  cout << "c1 + c2 = " << c3 << endl;

  c3 = c1 - c2;
  cout << "c1 - c2 = " << c3 << endl;

  c3 = c1 * c2;
  cout << "c1 * c2 = " << c3 << endl;

  c3 = c1 / c2;
  cout << "c1 / c2 = " << c3 << endl;

  const complex c4(c3);
  complex *p = const_cast<complex *>(&c4);
  p->m_real = 2.33;
  cout << "c4=" << c4 << endl;
  cout << "*p=" << *p << endl;

  const double d4 = 0.01;
  double *pp = const_cast<double *>(&d4);
  *pp = 0.123;
  cout << "d4=" << d4 << ", pp=" << *pp << endl;
  return 0;
}
