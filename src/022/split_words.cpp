/**
 * @file split_words.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief Welcome to the world of C++! This program is intended to split a
 * std::string into words with whitespace delimiter.
 * 
 * @note At least C++11 is required to compile this code.
 *
 * @version 0.1
 * @date 2021-02-22
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <iostream> // std::cout, std::getline()
#include <sstream>  // std::istringstream
#include <string>   // std::string
#include <vector>   // std::vector

// Using this statement for sake of simplicity, and to remove the redundant
// std:: prefixes from everywhere
using namespace std;

int main(void) {
  string input;
  string temp;
  vector<string> words;
  static int count;

  cout << "Enter a sentence: ";
  getline(cin, input);

  // Declaring the input string stream object for input (std::string)
  istringstream iss(input);

  // Inserting each word separated by whitespace character into the vector
  while (iss >> temp)
    words.push_back(temp);

  // Displaying each vector element safely
  for (const auto& it : words)
    cout << ++count << ' ' << it << endl;

  return 0;
}