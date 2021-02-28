/**
 * @file type_deduction.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief Type deduction helps to improve the maintainability of the code, and
 * increases readability too. At compile time, it adjusts to the best suited
 * type for the value to hold.
 *
 * This program has the exact intention to define.
 *
 * @version 0.1
 * @date 2021-02-28
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <iostream>
#include <typeinfo>

using std::cout;

/**
 * @brief A flexible function that detects the parameter type on function call
 * and returns itself with the same type.
 *
 * @tparam T    Type to be accepted and returned
 * @param param Parameter value to be accepted
 * @return      Parameter itself
 */
template <typename T> auto testReturn(T param) { return param; }

int main(void) {
  auto var1 = 250.4;
  cout << var1 << std::endl;

  // const char *
  auto v1 = testReturn(std::string("Hello"));
  // double
  auto v2 = testReturn(123.45);
  // long int
  auto v3 = testReturn(9999999999);

  // On Linux, using the command:  ./a.out | c++filt -t  will help displaying
  // the names explicitly
  cout << typeid(v1).name() << std::endl;
  cout << typeid(v2).name() << std::endl;
  cout << typeid(v3).name() << std::endl;

  return 0;
}