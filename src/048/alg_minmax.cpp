/**
 * @file alg_minmax.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief This is a basic program that finds the minimum and the maximum
 * elements in a container using the STL collections.
 *
 * @version 0.1
 * @date 2021-03-20
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <algorithm>
#include <array>
#include <iostream>

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
 * @brief Subroutine that applies one of the most common template used to obtain
 * the maximum and the minimum objects within a container.
 */
void example_MinMax(void) {
  using Array = array<Class, 5>;

  Array arr{3, 10, 4, 9, 0};

  auto comparatorClosure = [](Class rhs, Class lhs) { return rhs < lhs; };

  // NOTE:  min_element  and  max_element  takes at least two parameters,
  //        i.e. (arr.begin(), arr.end()) - third is optional.
  auto min = min_element(arr.begin(), arr.end(), comparatorClosure);
  auto max = max_element(arr.begin(), arr.end(), comparatorClosure);

  // This ensures the values containing in the container will be kept constants
  Array::const_iterator cit = arr.cbegin();

  cout << "Elements in the array: ";

  // Moving the iterators in each iteration
  do
    cout << *cit << ' ';
  while (cit++ != arr.cend());

  cout << endl;
  cout << "The minimum number existing in the array: " << *min << endl
       << "The maximum ones is: " << *max << endl;
}

int main(void) {
  example_MinMax();

  return 0;
}