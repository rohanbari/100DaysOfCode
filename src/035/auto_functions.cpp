/**
 * @file auto_functions.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief This program uses the templates and type deduction + the keyword
 * 'decltype' combined to double its power.
 *
 * @version 0.1
 * @date 2021-03-07
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <iostream>

/**
 * @brief Using the token '->' - the return type of the function is forced to be
 * the same as the type mentioned afterwards. Here, decltype() does this job.
 *
 * @tparam T    Adjusted type
 * @param param Parameter to be returned
 * @return      The parameter of type decltype(param)
 */
template <typename T> auto returnExample(const T &param) -> decltype(param) {
  return param;
}

/**
 * @brief The alternative form of returnExample, without introducing '->' token
 *
 * @tparam T    Adjusted type
 * @param param Parameter to be returned
 * @return      The param
 */
template <typename T> auto returnExampleAlt(const T &param) { return param; }

int main(void) {
  // Type deduction, better to view when IntelliSense is supported
  auto ret = returnExample(10);
  auto ret2 = returnExampleAlt(3.5);

  // Displaying the results by converting the values to std::basic_string<char>
  std::cout << std::to_string(ret) + ' ' + std::to_string(ret2) << std::endl;

  return 0;
}