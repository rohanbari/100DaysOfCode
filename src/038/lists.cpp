/**
 * @file lists.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief There are seven containers defined in the STL. One of them are lists.
 * list<T, A> are the doubly linked-lists of type T. This program represents
 * the usage of the lists.
 *
 * @version 0.1
 * @date 2021-03-10
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <algorithm>
#include <iostream>
#include <list>

using list = std::list<int32_t>;

int main(void) {
  const list myList{10, 4, 7, 12, 3};
  std::list<std::string> names{"Rohan", "Maxwell", "Franklin", "Ken"};
  list truncated{};

  list::const_iterator listIt = myList.cbegin();

  for (; listIt != myList.cend(); listIt++)
    if (*listIt >= 5)
      truncated.push_back(*listIt);

  // Sorting the elements of the container
  truncated.sort();
  listIt = truncated.cbegin();

  for (; listIt != truncated.cend(); listIt++)
    std::cout << *listIt << std::endl;

  // Deduces to: std::_List_const_iterator<std::string>
  // Alternatively, std::list<std::string>::const_iterator
  auto it = names.cbegin();

  for (; it != names.cend(); it++)
    std::cout << *it << std::endl;

  // Rest functions are similar to use that are defined in 'stl_iterators.cpp'

  return 0;
}