/**
 * @file vector_list.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief This program attempts to describe an elegant way to initialize a
 * vector using an initializer-list with user-defined operator overloads and
 * function definitions.
 *
 * @version 0.1
 * @date 2021-04-05
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <initializer_list>
#include <iostream>
#include <vector>

// Forward-declaration to the Class class
class Class;
// Type-alias to represent the default vector declaration
using Vector = std::vector<Class>;
// Type-alias to represent the default initializer list declaration
using ListInit = std::initializer_list<Class>;

class Class {
    uint32_t member;

  public:
    // The default constructor
    Class() = default;
    // Adding support for initializer lists
    Class(int _mem) : member(_mem) {}
    // The default copy constructor of the class
    Class(const Class &rhs) = default;
    // The default copy constructor operator overload
    Class &operator=(const Class &rhs) = default;
    // The default destructor
    ~Class() = default;

    // Will be invoked when  std::cout <<  statement is occurred
    friend std::ostream &operator<<(std::ostream &out, const Class &rhs) {
        out << rhs.member;
        return out;
    }
};

namespace Solution {
    /**
     * @brief Invokes operator overload << to print on the output stream.
     *
     * @param rhs Vector to be displayed
     */
    void displayResult(const Vector &rhs) {
        if (rhs.empty()) {
            std::cerr << "displayResult(): The parameter is empty.\n";
            exit(EXIT_FAILURE);
        }

        for (const auto &it : rhs) {
            std::cout << it << std::endl;
        }
    }
} // namespace Solution

int main(void) {
    ListInit iList{10, 20, 30, 40}; // The initializer-list
    Vector instance{iList};         // Calling the class's explicitly defined
                                    // initializer list

    Solution::displayResult(instance);

    return 0;
}