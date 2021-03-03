/**
 * @file lambda_expr.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief Lambda expressions are a part of C++11 standard. A lambda is a source
 * code construct that defines an anonymous or unnamed function. This program
 * introduces to the concept of lambda expressions, and uncovering some of its
 * essential features that every programmer should know.
 *
 * @version 0.1
 * @date 2021-03-03
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <algorithm>
#include <array>
#include <functional>
#include <iostream>

using dArray = std::array<uint32_t, 5>;
using std::cout;

constexpr dArray arr{3, 2, 6, 8, 5};

/**
 * @brief Subroutine that accepts a function (this includes unnamed, known as
 * anonymous ones too) using std::function<> through pass-by-reference.
 *
 * @param closure Function to be used
 */
void function_closure(const std::function<void(dArray::value_type)>& closure) {
  std::for_each(arr.begin(), arr.end(), closure);
}

/**
 * @brief This subroutine prints each element of the arr (of type
 * `array<uint32_t, 5>`) using for_each() STL algorithm alongside lambdas.
 */
void example_arrays(void) {
  auto lambda = [](const auto& var) { cout << var << std::endl; };

  // Use with  c++filt -t  command
  cout << typeid(lambda).name() << std::endl;

  std::for_each(
      // Format of a lambda expression: [capture](param) {...}
      arr.begin(), arr.end(), lambda);

  cout << "-----" << std::endl;
}

/**
 * @brief This subroutine manifests the benefit of using function<> with lambdas
 * to create dynamic functions, and efficiently utilize them.
 */
void example_function_closure(void) {
  auto lambda = [](auto&& param) { cout << param << std::endl; };

  cout << "Displaying using: function_closure()" << std::endl;
  cout << typeid(lambda).name() << std::endl;
  function_closure(lambda);
}

int main() {
  example_arrays();
  example_function_closure();

  return 0;
}