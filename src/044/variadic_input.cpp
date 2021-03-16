/**
 * @file variadic_input.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief This program works like an addition calculator that sums up all the
 * numbers separated by space character at runtime.
 *
 * @version 0.1
 * @date 2021-03-16
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// Type aliasing
using vector = std::vector<int>;
using std::string;
using std::stringstream;

int main(void) {
  vector numbers;
  string input;
  int temp;

  std::cout << "Input variadic numbers separated by SPACE: ";
  std::getline(std::cin, input);

  // Using a stringstream instance to break the strings into pieces ...
  stringstream iss(input);

  // ... using this loop
  while (iss >> temp)
    numbers.push_back(temp);

  int sum = 0;

  // At last, summing the contained numbers up
  for (const auto &it : numbers)
    sum += it;

  std::cout << "Sum of the numbers: " << sum << std::endl;

  return 0;
}