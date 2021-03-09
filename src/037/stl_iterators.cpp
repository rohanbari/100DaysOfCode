/**
 * @file stl_iterators.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief The STL provides iterators that work with all containers and can be
 * used to denote the beginning and end of a sequence within a container. They
 * are pointers that points to each element in the specified sequence.
 *
 * The following program has the intention to describe about the STL container
 * iterators and their various implementations thoroughly.
 *
 * @version 0.1
 * @date 2021-03-09
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <iostream>
#include <iterator>
#include <vector>

// Disguising the 'std::vector<int32_t>' with 'vector'
using vector = std::vector<int32_t>;

/**
 * @brief This subroutine defines the implementation of iterators with the
 * vector containers.
 */
void exampleVectorIterators(void) {
  // Defining the 'std::initializer_list<>' explicitly
  std::initializer_list<int32_t> inst{1, 4, 9, 16, 10, 8, 2};
  // Calling the initializer list using copy assignment operator overload
  vector vecObj = inst;

  // Deduces to the type 'vector::iterator'
  for (auto it = vecObj.begin(); it != vecObj.end(); it++)
    std::cout << *it << std::endl;
  std::cout << "-----" << std::endl;
}

/**
 * @brief This subroutine manifests the usage of const_iterator type iterator.
 */
void exampleConstIterators(void) {
  vector object{1, 2, 3, 4, 5};
  // NOTE: Uncomment required for this when (MARK) is uncommented
  // int value = object.at(0);

  for (vector::const_iterator it = object.cbegin(); it != object.cend(); it++) {
    // (MARK) Error: The expression must be a modifiable lvalue
    // *it = value++;
    std::cout << *it << std::endl;
  }
  std::cout << "-----" << std::endl;
}

/**
 * @brief This subroutine exemplifies the implementation of the
 * reverse_iterator (the syntax is similar for vector::const_reverse_iterator).
 */
void exampleReverseIterators(void) {
  vector object{3, -1, 11, 4, 7, 0};

  // This will display members in the reverse order
  for (vector::const_reverse_iterator it = object.crbegin();
       it != object.crend(); it++) {
    std::cout << *it << std::endl;
  }
}

int main(void) {
  exampleVectorIterators();
  exampleConstIterators();
  exampleReverseIterators();

  return 0;
}