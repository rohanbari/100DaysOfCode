/**
 * @file basic_template.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief The template mechanism enables us to achieve the generic programming.
 * This is one of the most valued feature of C++ standard. This is an
 * introductory program for this feature.
 *
 * @version 0.1
 * @date 2021-02-24
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <iostream>

/**
 * @brief Template class
 *
 * @tparam T Type (defaults to 'int')
 */
template <typename T = int> class MetaClass {
  T *t; // Template variable

public:
  MetaClass() {}
  MetaClass(T val) {
    // Allocating the required bytes of memory for the template variable
    t = new T(val);
  }
  ~MetaClass() { delete t; }

  friend std::ostream &operator<<(std::ostream &out, const MetaClass &mC) {
    return out << *mC.t;
  }
};

int main(void) {
  // Calling the constructor MetaClass(T val) {}
  MetaClass<int> mClass(10);
  // Gathering the output into an std::ostream& and calling the overloaded
  // operator<< definition from the template class MetaClass
  std::cout << mClass << std::endl;

  return 0;
}
