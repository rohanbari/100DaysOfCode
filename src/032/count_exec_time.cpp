/**
 * @file count_exec_time.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief Modern C++ provides STL templates and classes that provide portable
 * time handling capabilities. std::chrono is a namespace that contains those
 * powerful features.
 *
 * This program gives a slightly introduction to the implementation of its
 * core feature to count the difference between start-up of a program to the end
 * in nanoseconds.
 *
 * @version 0.1
 * @date 2021-03-04
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <chrono>
#include <iostream>

using namespace std;
using namespace chrono;

int main(void) {
  // Obtaining the initial time point
  auto startPoint = system_clock::now();

  // Some tasks...
  int a = 0;
  for (int i = 0; i < 100000; i++)
    a += 10;

  // Taking the end point
  auto endPoint = system_clock::now();

  // Note that 'nanoseconds' is disguised under
  // std::chrono::duration<int64_t, std::nano>
  // Subtracting the endPoint from the startPoint
  auto timeReq = duration_cast<nanoseconds>(endPoint - startPoint);

  // Displaying the calculation results
  cout << (double)timeReq.count() / 100000 << 's' << endl;

  return 0;
}