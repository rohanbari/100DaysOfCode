/**
 * @file spaceship_operator.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief The spaceship operator allows the compiler to automatically generate
 * comparison operators instead of manually coding it. It is invoked by using
 * <=> operator (valid from C++20 and above). It requires to include "compare".
 *
 * This program introduces an example to this newly added feature.
 *
 * @note At least C++20 standard is required to compile this.
 *
 * @version 0.1
 * @date 2021-04-03
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <compare>
#include <iostream>
#include <string>

using std::weak_ordering;

struct Type {
    int a;
    int b;
};

/**
 * @brief Operator-overload to <=> - the spaceship operator.
 *
 */
constexpr weak_ordering operator<=>(const Type &t1, const Type &t2) {
    int expr1 = t1.a + t1.b; // Adds both values of struct 1
    int expr2 = t2.a + t2.b; // Adds both values of struct 2

    return expr1 <=> expr2;
}

/**
 * @brief Comparison function.
 *
 * @param rhs The required expression to be evaluated.
 */
void compare(const weak_ordering &rhs) {
    std::string str;

    if (rhs == 0)
        str = "equal";
    else if (rhs > 0)
        str = "greater";
    else if (rhs < 0)
        str = "lesser";
    else
        str = "bad_value";

    std::cout << "compare(): " << str << std::endl;
}

int main(void) {
    // Initializing using designated initializers
    Type t1{.a = 5, .b = -4};
    Type t2{.a = 3, .b = 10};

    // Invoking the spaceship comparison with a comparator subroutine
    compare(t1 <=> t2);

    return 0;
}