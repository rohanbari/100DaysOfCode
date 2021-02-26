/**
 * @file operator_overload.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief This program demonstrates an essential feature of OOP, and thus C++.
 * It is called operator-overloading that is utilized to achieve Polymorphism
 * to interact with objects naturally while writing expressions.
 *
 * @note Alongside operator-overloading, this program also describe about
 * the implementation of Rule-of-Three that contains a copy constructor,
 * destructor, and a copy-assignment operator overload.
 *
 * @version 0.1
 * @date 2021-02-26
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

class Math {
  int x;

public:
  // Explicit declaration for a default-constructor to prevent the possible
  // conflicts when instantiating objects later (so they could be assigned
  // anywhere, not necessarily at the instant where it's declared.)
  Math() {}
  // List-initializer to initialize an object
  Math(int a) : x(a) {}

  // Rule of Three: Copy constructor, destructor and copy assignment operator
  Math(const Math &a) : x(a.x) {}
  ~Math() {}

  Math &operator=(const Math &m) {
    this->x = m.x;
    return *this;
  }

  // Required operator overloads to perform basic mathematical calculations.
  // Note that these are unary operator overloads!
  Math operator+(const Math &m) {
    this->x += m.x;
    return *this;
  }

  Math operator-(const Math &m) {
    this->x -= m.x;
    return *this;
  }

  Math operator*(const Math &m) {
    this->x *= m.x;
    return *this;
  }

  Math operator/(const Math &m) {
    this->x /= m.x;
    return *this;
  }

  // Overloading << operator to be used for displaying using std::cout.
  // Note that when overloading operator<<(), it must have two parameters,
  // i.e. first for an output stream and the last could be anything required
  // to be passed to the std::ostream
  friend ostream &operator<<(ostream &out, const Math &m) { return out << m.x; }
};

int main(void) {
  Math op1, op2, op3, op4;

  // Calling copy assignment operator for all of these
  op1 = 3;
  op2 = 10;
  op3 = 5;

  // ... = ... -> Call: Copy assignment operator overload
  // ... + ... -> Call: operator+()
  // ... - ... -> Call: operator-()
  // ... * ... -> Call: operator*()
  // ... / ... -> Call: operator/()
  op4 = op1 + (op2 / op3);

  // Call: operator<<()
  cout << op4 << endl;

  return 0;
}