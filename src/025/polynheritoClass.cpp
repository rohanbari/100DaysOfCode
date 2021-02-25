/**
 * @file polynheritoClass.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief This program completes the previous 'idealClass.cpp' part. The file
 * name name is the concatenated version of two words: Poly(morphism) +
 * I(nherit)ance.
 *
 * @version 0.1
 * @date 2021-02-25
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

class IdealClass {
  int ic_X;

  // The derived classes would have access to the protected class fields
  // and the parent class itself
protected:
  int ic_Y;

public:
  IdealClass() {}
  IdealClass(int param) : ic_X(param), ic_Y(param) {}

  friend ostream &operator<<(ostream &out, const IdealClass &iC) {
    return out << iC.ic_X;
  }
};

// Achieving the Inheritance
class Derived : public IdealClass {
public:
  Derived() : IdealClass(0) {}
  Derived(int param) : IdealClass(param) {}

  // Achieving the polymorphism - similarly, we can overload the operators
  int useICY(void) { return ic_Y; }
  int useICY(int value) {
    ic_Y = value;
    return ic_Y;
  }
};

int main(void) {
  IdealClass idealClass(10);
  Derived derived;

  cout << "idealClass object : " << idealClass << endl;
  cout << "useICY(void)      : " << derived.useICY() << endl;
  cout << "useICY(int)       : " << derived.useICY(100) << endl;

  return 0;
}