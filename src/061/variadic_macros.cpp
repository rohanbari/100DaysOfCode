/**
 * @file variadic_macros.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief A macro can be declared to accept a variable number of arguments much
 * as a function can. This program demonstrates __VA_ARGS__ in action.
 *
 * @version 0.1
 * @date 2021-04-02
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <iostream>

#define SIMPLE_MACRO "hello"
#define PRINT(fmt, ...) fprintf(stdout, fmt, __VA_ARGS__)

using std::cout;

namespace MacroApplier {
    void simpleMacro() {
        // Equivalent to: cout ... << "hello" << ...;
        cout << "simpleMacro(): " << SIMPLE_MACRO << std::endl;
    }

    void printMacro() {
        // Using variadic arguments
        PRINT("printMacro(): %d %s %.2f\n", 5, "Hi", 10.245);
    }
} // namespace MacroApplier

int main(void) {
    std::cout << "Hello from C++!\n";

    MacroApplier::simpleMacro();
    MacroApplier::printMacro();

    return 0;
}