/**
 * @file loops.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief A loop is a programming structure that repeats the same instructions,
 * or processes the same information iteratively until a condition is not met.
 *
 * Loops are often used during code to compress the effort of writing code. This
 * program introduces several types of loops, and using them efficiently in
 * different circumstances.
 *
 * @version 0.1
 * @date 2021-03-27
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <array>
#include <iostream>

using namespace std;

const int MAX = 10;

class Loops {
   public:
    /**
     * @brief Only while-loops are used when the programmer wants to execute a
     * code segment until the condition is met.
     */
    void simpleWhileLoop(void) {
        int it = 0;

        cout << "simpleWhileLoop():\n";

        // Condition is checked before the loop begins, does not execute if the
        // given condition is not met
        while (it != MAX) {
            cout << it << ' ';
            it++;
        }
        cout << endl;
    }

    /**
     * @brief Do-while loops are used when a code block is expected to run at
     * least once throughout a program.
     */
    void doWhileLoop(void) {
        cout << "doWhileLoop(): (no output)\n";

        int it = 0;

        do {
            // Condition will be checked later, execute the code at least once
            it++;
        } while (it != MAX);
    }

    /**
     * @brief For-loops are one of the most commonly used loops. This could be
     * applied in all places, however, ALL does not means it will fit everywhere
     * when efficiency is considered.
     */
    void simpleForLoop(void) {
        cout << "simpleForLoop():\n";

        for (int it = 0; it < MAX; it++) {
            cout << it << ' ';
        }
        cout << endl;
    }

    /**
     * @brief Infinite loops are basically applied in embedded systems. However,
     * they are also used to keep going until the user gets fed up, or a break
     * statement is explicitly called.
     */
    void infiniteLoop(void) {
        cout << "infiniteLoop(): (code commented)\n";

        // while (true) {
        //     // Anything written inside this code block will be running
        //     // infinitely until a termination signal is sent
        // }

        // for (;;) {
        //     // This is also a valid infinite loop
        // }
    }

    /**
     * @brief Range-based loops are used in the places where the index does not
     * matter, e.g. to print all values contained in a container, array, etc.
     */
    void rangeBasedLoop(void) {
        array<int, 5> container{10, -2, 4, 0, 1};

        cout << "rangeBasedLoop():\n";

        for (auto &&it : container) {
            cout << it << ' ';
        }
        cout << endl;
    }
};

int main(void) {
    Loops loops;

    loops.simpleWhileLoop();
    loops.doWhileLoop();
    loops.simpleForLoop();
    loops.infiniteLoop();
    loops.rangeBasedLoop();

    return 0;
}