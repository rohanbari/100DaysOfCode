/**
 * @file alg_count.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief This program enlightens the concept of using std::count_if algorithm.
 * It counts the number of instances found in a container that matches a
 * condition followed by a lambda function, or a user-defined function.
 *
 * @version 0.1
 * @date 2021-03-22
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Counter {
  int number;

 public:
  Counter() = default;
  Counter(int _num) : number(_num) {}
  Counter& operator=(const Counter& rhs) = default;
  ~Counter() = default;

  // To compare
  bool operator>(const Counter& rhs) { return this->number > rhs.number; }
};

int main(void) {
  vector<Counter> container{1, 2, 3, 6, 3, 9, 2, 4, 1, 5};
  const int COMPARE = 4;
  // If the passed value is greater than COMPARE, then do count
  int testCount = count_if(container.begin(), container.end(),
                           [](Counter cont1) { return cont1 > COMPARE; });

  // Display the count
  cout << "Elements in container greater than " << COMPARE << ": " << testCount
       << endl;

  return 0;
}