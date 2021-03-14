/**
 * @file move_semantics.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief Move semantics is about transferring resources rather than copying
 * them when the the source value is no longer needed.
 *
 * This program illustrates the implementation, the casualties, and the effects
 * of the move semantics.
 *
 * @version 0.1
 * @date 2021-03-14
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <iostream>
#include <vector>

using std::cout;
using std::ostream;

/**
 * @brief The Vehicle class.
 *
 */
class Vehicle {
  std::string field;

public:
  // The default constructor
  Vehicle() = default;
  // Constructor with an argument
  Vehicle(std::string _field) : field(_field) {}

  // Copy constructor
  Vehicle(const Vehicle &rhs) = default;
  // Move constructor
  Vehicle(Vehicle &&rhs) = default;

  // Overloading copy assignment operator
  Vehicle &operator=(const Vehicle &rhs) = default;
  // Overloading move assignment operator
  Vehicle &operator=(Vehicle &&rhs) = default;

  // The default destructor
  ~Vehicle() = default;

  // Overloading the put-to operator to display the object on the screen
  friend ostream &operator<<(ostream &out, const Vehicle &rhs) {
    return out << rhs.field;
  }
};

int main(void) {
  Vehicle model1{"String"};
  // Invoking the move constructor
  Vehicle model2{std::move(model1)};

  cout << model1 << std::endl; // It's emptied as soon as the move constructor
                               // was invoked

  cout << model2 << std::endl; // Moved model1 object into model2

  return 0;
}