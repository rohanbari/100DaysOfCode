/**
 * @file function_template.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief Templates are of two types: Class templates and function templates.
 * Thus, this program introduces with the function templates.
 *
 * @version 0.1
 * @date 2021-02-24
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <iostream>

/**
 * @brief Example function template.
 *
 * @tparam T1 First typename
 * @tparam T2 Second typename
 * @tparam T3 Return typename
 * @param op1 First operand
 * @param op2 Second operand
 * @param action Operation to be done
 * @return Calculation result
 */
template <class T1 = int, class T2 = int, class T3 = int>
T3 calculate(T1 op1, T2 op2, char action) {
  switch (action) {
    case '+': {
      return op1 + op2;
      break;
    }
    case '-': {
      return op1 - op2;
      break;
    }
    case '*': {
      return op1 * op2;
      break;
    }
    case '/': {
      return op1 / op2;
      break;
    }
    default: {
      std::cerr << "The action is undefined." << std::endl;
      return EXIT_FAILURE;
      break;
    }
  }
}

int main(void) {
  int var1 = 12;
  float var2 = 34.3f;

  std::cout << "var1 + var2 = " << calculate(var1, var2, '+') << std::endl;
  std::cout << "var1 - var2 = " << calculate(var1, var2, '-') << std::endl;
  std::cout << "var1 * var2 = " << calculate(var1, var2, '*') << std::endl;
  std::cout << "var1 / var2 = " << calculate(var1, var2, '/') << std::endl;

  return 0;
}