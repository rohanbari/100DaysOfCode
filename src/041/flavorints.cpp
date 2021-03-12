/**
 * @file flavorints.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief Using the types that contains '_t' and are defined in the  cinttypes
 * header guarantees that the capacity of the variable does not change (i.e.
 * independent of the machine architecture.) - that is the number of bytes are
 * confirmed to be reserved.
 *
 * This program introduces this highlighted feature that is often used for
 * numeric operations trustfully in the C++ standard.
 *
 * @version 0.1
 * @date 2021-03-13
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <cinttypes>
#include <iostream>
#include <limits>

using std::numeric_limits;

template <typename T> auto get(const T &rhs) {
  return numeric_limits<T>::max();
}

int main(void) {
  // NOTE:  The following four lines are just examples. There are similar types
  //        available that are not mentioned in the code to keep it simple.
  int8_t bit_8_int = get(bit_8_int);
  int16_t bit_16_int = get(bit_16_int);
  uint32_t bit_32_uns_int = get(bit_32_uns_int);
  uint64_t bit_64_uns_int = get(bit_64_uns_int);

  // Converting the int8_t (signed char) to int16_t (signed short)
  // NOTE:  Suggesting to use c++filt -t alongside the execution command
  std::cout << typeid(bit_8_int).name() << ' '
            << static_cast<int16_t>(bit_8_int) << std::endl;

  std::cout << typeid(bit_16_int).name() << ' ' << bit_16_int << std::endl;
  std::cout << typeid(bit_32_uns_int).name() << ' ' << bit_32_uns_int
            << std::endl;
  std::cout << typeid(bit_64_uns_int).name() << ' ' << bit_64_uns_int
            << std::endl;

  return 0;
}