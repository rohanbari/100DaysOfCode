/**
 * @file variadic_template_packs.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief This program defines how to tackle problems like: Parameters not
 * expanded with '...'.
 * 
 * @version 0.1
 * @date 2021-03-17
 * 
 * @copyright Copyright (c) 2021 Rohan Bari
 * 
 */

#include <iostream>

// Declaration of the variadic template
template <typename... T> void print(T &...msg) {
  using var = int[];
  // Displaying the results properly by expanding the packs
  (void)var{0, (std::cout << msg << std::endl, 0)...};
}

int main(void) {
  // Calling the templated function
  print("hello", "test");
  
  return 0;
}