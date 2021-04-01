/**
 * @file word_initials.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief This program finds the number of strings initialized with a given
 * character sequence in common.
 *
 * @version 0.1
 * @date 2021-04-01
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <array>
#include <iostream>
#include <string>

const int ARRAY_SIZE = 5;

using std::array;
using std::string;

// Type-alias to represent the array type defined here
using Array = array<string, ARRAY_SIZE>;

/**
 * @brief This namespace contains the solution.
 *
 */
namespace Solution {

    /**
     * @brief This subroutine defines the solution that works with the
     * standardized C++98 and above versions.
     *
     * @param words   Array of std::string
     * @param EXAMINE std::string to be examined
     */
    void withPortable(const Array &words, const string &EXAMINE) {
        int counter = 0;

        for (const auto &it : words) {
            // Find until null position to the std::string is reached
            if (it.find(EXAMINE) != string::npos) {
                counter++;
            }
        }

        std::cout << "withPortable(): Total matching instances: " << counter
                  << std::endl;
    }

    /**
     * @brief This subroutine defines the solution that requires C++20 standard.
     *
     * @warning C++20 standard must be used to compile this!
     * @note Comment the containing code if this program needs to be compiled
     * but the machine has not C++20 supported.
     *
     * @param words   Array of std::string
     * @param EXAMINE std::string to be examined
     */
    void withStandard20(const Array &words, const string &EXAMINE) {
        int counter = 0;

        for (const auto &it : words) {
            // Member function starts_with is introduced in C++20 that verifies
            // if the string really starts with the given sequence
            if (it.starts_with(EXAMINE.c_str())) {
                counter++;
            }
        }

        std::cout << "withStandard20(): Total matching instances: " << counter
                  << std::endl;
    }
} // namespace Solution

int main(void) {
    // The word list to be checked
    const Array list{"Hello", "Helium", "Helpful", "Helix", "Alpha"};
    const string initials = "Hel";

    Solution::withPortable(list, initials);
    Solution::withStandard20(list, initials);

    return 0;
}