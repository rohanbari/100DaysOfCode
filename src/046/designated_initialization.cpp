/**
 * @file designated_initialization.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief The Designated Initialization feature introduces a new syntax that
 * initializes an aggregate by specifying pairs of public data member
 * designators followed by two ways to initialize object properties, via direct
 * initialization or braces.
 *
 * This program attempts to take some benefit from it.
 *
 * @note C++20 standard is required for compilation.
 *
 * @version 0.1
 * @date 2021-03-18
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <iostream>
#include <string>

using string = std::string;
using ostream = std::ostream;

struct data {
  string name;
  uint32_t age;
  double salary;

  // Overloading put-to operator for displaying in std::cout statements
  friend ostream &operator<<(ostream &out, const data &rhs) {
    out << rhs.name << ' ' << rhs.age << ' ' << rhs.salary << std::endl;
    return out;
  }
};

int main(void) {
  // OK:       Supported by all standards
  data instance{"Rohan Bari", 17, 25000.00};
  // WARNING:  Supported only from C++20
  data desig_Instance{.name = "Rohan Bari", .age = 17, .salary = 25000.00};

  std::cout << "Normal: " << instance;
  std::cout << "Designated: " << desig_Instance;

  return 0;
}