/**
 * @file inline.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief Inline keyword only suggests the compiler to make the requested
 * function/subroutine in-line in order to increase the performance. Note that
 * the inline functions defeat the compiler optimization, and are not supposed
 * to be optimized by the compiler when a long function definition is written -
 * it should be used when small functions comes into the job.
 *
 * This program explains the implementation, various significances, pros. and
 * cons. of inline functions/subroutines/methods.
 *
 * @version 0.1
 * @date 2021-02-26
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <iostream>

using std::cout;
using std::endl;

// OK: This is a simple inline subroutine
inline void print(const char *str) { cout << str << endl; }

class InlineExample {
public:
  InlineExample() {}
  ~InlineExample() {}

  // It's non-static if 'static' is not explicitly mentioned
  // By using 'static', we can directly access these methods without
  // instantiating into the objects
  static void print(const char *str) { cout << str << endl; }
};

// Few important notes here:
//   1. The template methods/functions are not guaranteed to be inline
//   2. Their presence in an header will not make them automatically inline
template <typename T> inline void print(T param) {
  // This template method is called when print(anything_except_const_char_*)
  cout << "Call: (Template) " << param << endl;
}

int main(void) {
  print("Call: Inline subroutine print()");
  InlineExample::print("Call: static inline print() from Class InlineExample");

  print(123.3);
  print(9e23);

  // Do It Yourself:
  //   Now, try removing all the 'inline' from this program. What you will see
  //   after the successful compilation is that the file size is slightly lesser
  //   than the prior compilation - this is a disadvantage of inline specifier.

  return 0;
}