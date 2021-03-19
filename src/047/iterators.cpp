/**
 * @file iterators.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief An iterator is an abstraction mechanism that allows traversal
 * behavior on many different STL collections. All of the STL algorithms works
 * with iterators. They share three common properties with pointers.
 *
 * This program enlightens the implication of all types of iterators.
 *
 * @version 0.1
 * @date 2021-03-19
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief An example class implied in the examples.
 */
class Class {
  int element;

public:
  Class() = default;
  Class(int elem) : element(elem) {}

  // Required by max_element, min_element
  bool operator<(const Class &other) { return this->element < other.element; }
  // Required when an assignment operator is called in the program
  void operator=(const Class &rhs) { element = rhs.element; }

  // Needed when << (put-to) operator is invoked
  friend ostream &operator<<(ostream &out, const Class &rhs) {
    out << rhs.element;
    return out;
  }
};

/**
 * @brief This subroutine describes about all the algorithmic iterators.
 */
void example_Iterators() {
  using Vector = vector<Class>;

  Vector value{10, 20, 30, 40, 50};

  // Listing all the iterators here
  Vector::iterator it = value.begin();
  Vector::const_iterator cit = value.cbegin();
  Vector::reverse_iterator rit = value.rbegin();
  Vector::const_reverse_iterator crit = value.crbegin();

  // Values are non-const, forward, editable
  for (; it != value.end(); it++)
    cout << *it << ' ';
  cout << endl;

  // Values are const, forward, non-editable
  for (; cit != value.cend(); cit++) {
    // Values of 'value' vector are completely const here!
    // i.e. attempting to edit their values will result a compilation error
  }

  // Values are non-const, backward, editable
  for (; rit != value.rend(); rit++)
    cout << *rit << ' ';
  cout << endl;

  // Values are cost, backward, non-editable
  for (; crit != value.crend(); rit++) {
    // Goes backward, but the value is const!
    // i.e. similar to Vector::const_iterator, but reversed
  }
}

int main(void) {
  example_Iterators();

  return 0;
}