/**
 * @file basic_string.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief The strings in C++ and its functions are defined in 'string' library.
 * This program presents some of the core concepts of this library.
 *
 * @version 0.1
 * @date 2021-03-06
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <iostream>
#include <string>

using std::cout;

/**
 * @brief Subroutine that declares the basic_string<> (untypedeffed) version
 * of std::string identifier.
 */
void baseString(void) {
  // This statement is equivalent to: std::string mainString
  std::basic_string<char> mainString;

  cout << "Enter a string: ";
  getline(std::cin, mainString);

  cout << "The string was: " << mainString << std::endl;
}

/**
 * @brief Subroutine that concatenates two strings by calling the built-in
 * operator+() overload.
 */
void concatenate(void) {
  std::string str1 = "Hello ";
  std::string str2 = "World";

  std::string str3 = str1 + str2;
  auto strDeduce = str3.c_str();

  cout << str3 << std::endl;
  cout << typeid(strDeduce).name() << " version: " << strDeduce << std::endl;
}

/**
 * @brief Subroutine that uses find() member function of std::string.
 *
 * @param str Substring to be found
 */
void findSomething(const std::basic_string<char> &str) {
  std::string baseString;

  cout << "Input a string: ";
  getline(std::cin, baseString);

  cout << "Verifying if that contains the string \"" << str << "\"...\n";

  cout << "That "
       << ((baseString.find("test") != std::string::npos) ? "" : "does not")
       << " exists." << std::endl;
}

int main(void) {
  concatenate();
  findSomething("test");
  baseString();

  return 0;
}