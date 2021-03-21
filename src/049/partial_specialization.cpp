/**
 * @file partial_specialization.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief This program shows the way to achieve the partial specialization of
 * templates and in action. It is nothing but an explicit support to a user-
 * defined type, especially when it comes to the classes of OOP.
 *
 * @version 0.1
 * @date 2021-03-21
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <iostream>

class Container {
  int member{0};

 public:
  Container() = default;
  Container(int value) : member(value){};
  ~Container() = default;

  int getValue() const { return member; }
};

// Implicit template specialization
template <typename T>
T add(const T& a, const T& b) {
  return a + b;
}

// Partial specialization - explicit specific declaration for Container type
template <>
Container add(const Container& a, const Container& b) {
  return Container(a.getValue() + b.getValue());
}

int main(void) {
  const Container num1{4}, num2{7};
  const Container result{add(num1, num2)};  // Invoking the partial special.

  const double num3{10}, num4{30.2};
  // Invoking the implicit specialization, making it explicit template
  // instantiation by statically casting the num3 and num4 into the type double
  const double res = add(static_cast<double>(num3), static_cast<double>(num4));

  std::cout << "Partial specialization: " << result.getValue() << std::endl;
  std::cout << "Explct. specialization to <dbl., dbl.>: " << res << std::endl;

  return 0;
}