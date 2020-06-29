#include <iostream>
using namespace std;

void display();
void display(int);

namespace ns {
void display();
}

class Demo {
 public:
  void display();
};

int main() {
  display();
  display(1);
  ns::display();
  Demo obj;
  obj.display();

  return 0;
}
