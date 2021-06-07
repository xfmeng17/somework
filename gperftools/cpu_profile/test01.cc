#include <iostream>
#include <math.h>

int func01() {
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
int func02() {
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
  while (true) {
    func01();
    func02();
    break;
  }
  return 0;
}
