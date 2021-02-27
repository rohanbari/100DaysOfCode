/**
 * @file basic_vector.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief Vectors are one of the most widely used containers in C++ that is
 * significantly better than the C-style raw arrays. It contains lots of
 * built-in methods to perform operations quickly without reinventing the wheel.
 *
 * However, this program attempts to show the most basic structure of a vector
 * as a class to demonstrate what happens in the background in some cases.
 *
 * @version 0.1
 * @date 2021-02-27
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <iostream>

using std::cerr;
using std::cout;
using std::endl;
using std::ostream;

/**
 * @brief The Vector Class.
 *
 * @tparam T Dynamic type
 */
template <typename T = int> class Vector {
  T *vec;
  size_t len;

public:
  Vector() {
    // Allocating the initial memory if the object is created without having
    // the size declared
    vec = new T;
    vec[0] = 0;
  }
  Vector(size_t rhsLen) : len(rhsLen) { vec = new T[len]; }
  // Copy constructor
  Vector(const Vector &rhs) : vec(rhs.vec) {
    for (const auto &it : rhs)
      it = 0;
  }
  // Copy-assignment operator overload
  Vector &operator=(const Vector &rhs) {
    this->vec = rhs.vec;
    return *this;
  }
  // Destructor
  ~Vector() { delete[] vec; }

  /**
   * @brief This returns the value stored at the specified index.
   *
   * @param loc Index of the element
   * @return T  Value at the index
   */
  T at(size_t loc) {
    if (loc > len) {
      // Out of bounds
      std::cerr << "[error] Requested location is out of bounds.\n";
      exit(1);
    } else if (loc < 0) {
      // Out of bounds (negative array location)
      std::cerr << "[error] Negative range is not permitted.\n";
      return -1;
    }

    // Everything is fine, return the value...
    return *(vec + loc);
  }
};

int main(void) {
  Vector<int> vec(5);
  cout << vec.at(0) << endl;

  return 0;
}