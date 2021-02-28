/**
 * @file initializer_lists.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief The initializer-lists are one of the widely used and essential feature
 * introduced in C++11. It makes the code safely optimized and reduces the
 * number of lines to initialize a container.
 *
 * This program defines the ideal implementation of the initializer_list<> in
 * both direct and explicit ways.
 *
 * @version 0.1
 * @date 2021-02-28
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <iostream>
#include <vector>

using std::cout;
using std::initializer_list;
using std::vector;

/**
 * @brief Displays each element of the vector using range-based loop.
 *
 * @tparam T    Required Type
 * @param param The vector
 */
template <typename T> inline void displayContainer(const vector<T>& param) {
  // Displaying each element of the vector<T>
  for (const auto& it : param)
    cout << it << ' ';
  cout << std::endl;
}

int main(void) {
  initializer_list<int> iList{1, 5, 3, 9, 4};
  vector<int> container(iList);

  displayContainer(container);

  // Implicit method to define the initializer_list<>, thus it is the same
  // as above except that it was defined in a direct way
  vector<int> container2{3, 4, 1, 0};
  displayContainer(container2);

  return 0;
}