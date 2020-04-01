#include <iostream>
#include <sstream>

using namespace std;

int main(void) {
  stringstream ss;
  ss.clear();
  double val1 = 612353.78901213456789;
  ss << val1;
  cout << "val1 = " << ss.str() << endl;
  ss.clear();

  string val2 = "612353e+005";
  val1 = atof(val2.c_str());
  cout << "val = " << val1 << endl;
}
