/**
 * @file vectors.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief Vectors are one of the most widely used container ever introduced in
 * the C++ standard. Basically, these are flexible arrays defined as classes
 * that can resize itself as required. There are lots of methods in its
 * definition that could be applied in order to save tons of time.
 *
 * This program introduces the std::vector<> container feature.
 *
 * @note This program requires at least C++11 standard.
 *
 * @version 0.1
 * @date 2021-03-01
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <iostream>
#include <vector>

using std::cout;
using std::iterator;
using std::string;
using std::vector;

/**
 * @brief Displays each element containing in a vector container on the screen
 * by using a range-based loop.
 *
 * @tparam T    Type of the vector
 * @param param Required object to be displayed
 */
template <typename T> void display(vector<T> param) {
  for (const auto& it : param)
    cout << it << ' ';
  cout << std::endl;
}

int main(void) {
  // Declaration style 1: Calling list-initializer directly
  vector<int> numbers{3, -1, 9, 4, 0, 7};
  // Declaration style 2: Assigning the list-initializer
  vector<string> names = {"John", "David", "Rohan"};
  // Declaration style 3: Defining the size before its initialization
  vector<double> salaries(5);
  // Declaration style 4: Completely vacant vector
  vector<char> letters;

  // (contd.) STYLE 3: Initializing using assignment operator method
  salaries[0] = 500;
  salaries[1] = 10000;
  salaries[2] = 25000;
  salaries[3] = 90000;
  salaries[4] = 125000;

  // Using empty() method to verify if the container is empty
  cout << "Is 'letters' empty? " << (letters.empty() ? "yes\n" : "no\n");

  // (contd.) STYLE 4: Initializing using push_back() in the loop
  for (int i = 0; i < 26; i++)
    letters.push_back('A' + i);

  cout << "Is 'letters' empty now? " << (letters.empty() ? "yes\n" : "no\n");

  // Note that <...> is not required here, but - for sake of clarity, this is
  // added to manifest the call explicitly
  display<int>(numbers);
  display<string>(names);
  display<double>(salaries);
  display<char>(letters);

  // Getting the number of elements contianing in 'numbers' vector
  cout << "Total elements in 'numbers': " << numbers.size() << std::endl;
  cout << "Element at 0th index in 'name': " << names.at(0) << std::endl;

  cout << "Displaying using iterator pointer:" << std::endl;
  for (vector<double>::iterator pt = salaries.begin(); pt != salaries.end();
       pt++)
    cout << *pt << std::endl;

  return 0;
}