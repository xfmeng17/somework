#include <iostream>
#include <math.h>

double func01() {
  double n = 888888888888887;
  double r = 0.0;
  for (int i = 0; i < 10000 * 10000; i++) {
    double j0 = (n*n) / (double)(i+7);
    double j1 = j0 / n;
    double j2 = j0 / 23;
    r = (j0 / 13.0) * (j1 / 17.0) * (j2 / 19.0);
  }
  return r;
}

double func02() {
  double n = 888888888888887;
  double r = 0.0;
  for (int i = 0; i < 10000 * 10000; i++) {
    double j0 = (n*n) / (double)(i+7);
    double j1 = log(j0) / log(5);
    r = sqrt(j0*j1);
  }
  return r;
}

int main() {

  while (1) {
    double r1 = func01();
    double r2 = func02();
    std::cout << "r1=" << r1 << ",r2=" << r2 << std::endl;
  }

  return 0;
}
