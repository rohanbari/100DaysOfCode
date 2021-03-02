/**
 * @file constexpr.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief 'constexpr' (introduced in C++11) - guarantees that the specified
 * expression will be evaluated at compile time. If anything tries to alter its
 * value, the compiler will throw an error.
 *
 * This program does explain the usage of this keyword.
 *
 * @version 0.1
 * @date 2021-03-02
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <array>
#include <iostream>

using std::array;
using std::cout;

/**
 * @brief Initiate value by returning the field to the returnLength().
 *
 */
class Initiator {
  int field;

public:
  constexpr Initiator(const int& param) { field = param; }
  constexpr uint32_t returnLength() const { return field; }
};

/**
 * @brief Test function to return.
 *
 * @return 50
 */
int nonConst(void) { return 50; }

/**
 * @brief Test constexpr function to return.
 *
 * @return constexpr 50
 */
constexpr int someConst(void) { return 50; }

int main(void) {
  // To verify if the expression var{Class{}.member()} is constexpr
  constexpr uint32_t size{Initiator{5}.returnLength()};
  array<uint32_t, size> myArray{3, 4, 5, 1, 9};

  for (auto&& it : myArray)
    cout << it << ' ';
  cout << std::endl;

  const int v1 = nonConst();
  int v2 = (const int)someConst();
  // v1 = 10; // Erroneous code, cannot reassign a 'const'
  v2 = 123;   // Calling reassignment

  cout << v1 << " != " << v2 << std::endl;

  return 0;
}