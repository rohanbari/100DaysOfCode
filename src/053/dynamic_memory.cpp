/**
 * @file dynamic_memory.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief This program has two different abilities to allocate memory: fills up
 * to the maximum available physical memory, and the other that requires N bytes
 * of size to be allocated.
 *
 * @warning The first option should not be used for more than 5 seconds. The
 * system may become unresponsive that may lead an unexpected system crash.
 *
 * @version 0.1
 * @date 2021-03-25
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <iostream>

using namespace std;

/**
 * @brief This subroutine allocates up to the maximum RAM capacity of a system.
 */
void allocateInfinite(void) {
    uint8_t *heap_ptr = nullptr;
    __uint128_t size = 0;

    while (true) {
        try {
            heap_ptr = new uint8_t[size++];
            if (size % 64 == 0)
                cout << '.';

        } catch (const bad_alloc &ba) {
            // Handling bad allocation exception
            cerr << "bad allocation: " << ba.what() << endl;
            cout << "calling deallocation" << endl;

            delete heap_ptr;

            break;
        }
    }
}

/**
 * @brief This subroutine asks user to specify a size to allocate the
 * specified bytes of memory on the heap.
 */
void allocateSpecified(void) {
    uint8_t *heap_ptr = nullptr;
    uint64_t size = 0;

    cout << "Enter the required bytes of size: ";

    // Verifying if the input was valid and passes the desired condition
    if (!(cin >> size)) {
        cout << "error: The input must be a valid 64-b integer.\n";
        exit(EXIT_FAILURE);
    }

    // Allocating the specified bytes of memory
    heap_ptr = new uint8_t[size];

    cout << "allocation completed: calling deallocation" << endl;
    delete heap_ptr;
}

int main(void) {
    // Expands to  short int  type
    int16_t choice;

    cout << "[1] Allocate memory infinitely" << endl
         << "[2] Allocate specified bytes of memory" << endl
         << endl
         << "\tInput => ";

    if (!(cin >> choice)) {
        cerr << "error: The choice must be a valid 2-b integer.\n";
        return EXIT_FAILURE;
    }

    switch (choice) {
        case 1:
            allocateInfinite();
            break;
        case 2:
            allocateSpecified();
            break;
        default:
            cerr << "Invalid input choice.\n";
            break;
    }

    cout << "Thank you for using this program! :)\n";

    return 0;
}