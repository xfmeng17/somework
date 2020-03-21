#include <iostream>
using namespace std;

class AbstractShape {
 public:
  virtual double area() const = 0;
  double value() const;
  virtual ~AbstractShape() { cout << "AbstractShape deconstruct" << endl; };

 protected:
  AbstractShape(double valuePerSquareUnit) {
    cout << "AbstractShape construct" << endl;
  }

 private:
  double valuePerSquareUnit_;
};

class Rectangle : public AbstractShape {
 public:
  Rectangle(double width, double height, double valuePerSquareUnit) {
    cout << "AbstractShape deconstruct" << endl;
  }
  virtual double area() const;
  virtual ~Rectangle() { cout << "Rectangle deconstruct" << endl; }
};

class Circle : public AbstractShape {
 public:
  Circle(double width, double height, double valuePerSquareUnit) {
    cout << "AbstractShape deconstruct" << endl;
  }
  virtual double area() const;
  virtual ~Circle() { cout << "Circle deconstruct" << endl; }
};

double Rectangle::value() const {
  cout << "Rectangle::value()" << endl;
  return 0.0;
}
double Circle::value() const {
  cout << "Circle::value()" << endl;
  return 0.0;
}

int main() { return 0; }
