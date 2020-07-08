// Artima.com: The C++ Source: "Pure virtual function called",
// example 1, virtual function directly called in constructor.

#include <cstdlib>
#include <iostream>

// extern "C" void __cxa_pure_virtual() {
// 	std::cout << "__cxa_pure_virtual()" << std::endl;
// }

class AbstractShape {
 public:
  virtual double area() const = 0;
  double value() const;
  // Meyers 3rd Item 7:
  virtual ~AbstractShape();

 protected:
  AbstractShape(double valuePerSquareUnit);

 private:
  double valuePerSquareUnit_;
};

class Rectangle : public AbstractShape {
 public:
  Rectangle(double width, double height, double valuePerSquareUnit);
  virtual double area() const;
  // Meyers 3rd Item 7:
  virtual ~Rectangle();

 private:
  double width_;
  double height_;
};

AbstractShape::AbstractShape(double valuePerSquareUnit)
    : valuePerSquareUnit_(valuePerSquareUnit) {
  std::cout << "AbstractShape construct" << std::endl;
  // ERROR 1: Violation of Meyers 3rd Item 9!
  // std::cout << "creating shape, area = " << area() << std::endl;

  // ERROR 3: Violation of Meyers 3rd Item 9!
  // std::cout << "creating shape, value = " << value() << std::endl;
}

AbstractShape::~AbstractShape() {
  std::cout << "AbstractShape destruct" << std::endl;
  // ERROR 2: Violation of Meyers 3rd Item 9!
  // std::cout << "destroying shape, area = " << area() << std::endl;

  // ERROR 4: Indirect violation of Meyers 3rd Item 9!
  // std::cout << "destroying shape, value = " << value() << std::endl;
}

#ifdef DEFINE_PURE_VIRTUAL_FUNCTION

// Some compilers optimize away the vtbl, and try to directly call the base
// class version of the virtual function. If the function is defined, the
// program links and runs; if not, it doesn't link.

double AbstractShape::area() const { return 0; }

#endif /* DEFINE_PURE_VIRTUAL_FUNCTION */

double AbstractShape::value() const { return valuePerSquareUnit_ * area(); }

Rectangle::Rectangle(double width, double height, double valuePerSquareUnit)
    : AbstractShape(valuePerSquareUnit), width_(width), height_(height) {
  std::cout << "Rectangle construct" << std::endl;
}

Rectangle::~Rectangle() { std::cout << "Rectangle destruct" << std::endl; }

double Rectangle::area() const { return width_ * height_; }

int main(int argc, char** argv) {
  if (argc != 4) {
    std::cerr << "usage: " << argv[0] << " width height valuePerSquareUnit"
              << std::endl;
    return 1;  // Failure!
  }
  double width = std::atof(argv[1]);
  double height = std::atof(argv[2]);
  double valuePerSquareUnit = std::atof(argv[3]);

  Rectangle r(width, height, valuePerSquareUnit);
  std::cout << "value = " << r.value() << std::endl;

  return 0;  // Success!
}
