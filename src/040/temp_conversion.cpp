/**
 * @file temp_conversion.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief Seems easy, no? - Because, it is. But, the fact is that it is a quick
 * program challenge that I've done in nearly 2 minutes from scratch.
 *
 * @version 0.1
 * @date 2021-03-12
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <iostream>

using namespace std;

int main(void) {
  int32_t input;
  double c, f;
  double value;

  cout << "Enter the required amount: ";
  cin >> value;

  cout << "Select your option: (C to F - 1) or 2: ";
  cin >> input;

  if (!cin) {
    cerr << "Invalid input." << endl;
    return EXIT_FAILURE;
  }

  cout << "The result is: ";

  switch (input) {
    case 1: {
      c = 5 * (value - 32) / 9.0;
      cout << c << endl;
      break;
    }
    case 2: {
      f = 9 * value / 5.0 + 32;
      cout << f << endl;
      break;
    }
    default: {
      cerr << "No such option." << endl;
      break;
    }
  }

  return 0;
}