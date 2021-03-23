/**
 * @file alg_sort.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief The STL provides the sort algorithm to reorder data in a sequence.
 * The sequence order is lower to greater by default, but a custom order could
 * be defined using anonymous function as the third parameter of std::sort.
 *
 * This program illustrates the various methods to sort an STL container.
 *
 * @version 0.1
 * @date 2021-03-23
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>

// Type-aliasing to represent an integer vector container
using Vector = std::vector<int>;
const Vector container{10, 3, 2, 7, -4, 0, 1};

void displayEach(const Vector& vect) {
  // Using range-based loop to display the results
  // NOTE:  auto&& does not mean to MOVE, it is a neat trick!
  for (auto&& it : vect) std::cout << it << ' ';
  std::cout << std::endl;
}

/**
 * @brief This subroutine has a vector that is sorted later from lower to
 * greater sequence (by default sort option).
 */
void sortLowerToGreater() {
  Vector box{container};

  // Applying the std::sort STL algorithm here
  std::sort(box.begin(), box.end());
  // Calling the function to display on the screen
  displayEach(box);
}

/**
 * @brief This subroutine has a vector that is sorted using a built-in template
 * function std::greater<>().
 */
void sortGreaterToLower(void) {
  Vector box{container};

  // Greater to lower using a built-in template function
  std::sort(box.begin(), box.end(), std::greater<int>());
  displayEach(box);
}

/**
 * @brief This subroutine shows how to sort a vector using lambda function.
 */
void sortUsingLambda(void) {
  Vector box{container};

  std::sort(box.begin(), box.end(), [](int left, int right) {
    // Explicitly casting to boolean
    // NOTE:  (a > b)  will sort from greater to lower
    return static_cast<bool>(left < right);
  });
  displayEach(box);
}

int main(void) {
  sortLowerToGreater();
  std::cout << "---" << std::endl;
  sortGreaterToLower();
  std::cout << "---" << std::endl;
  sortUsingLambda();

  return 0;
}