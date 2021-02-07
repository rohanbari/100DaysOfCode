/**
 * @file multi_dim_array.c
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief The concept of multidimensional array might be confusing for most of
 * the newbie programmers who step at it firstly. It's not that complex feature
 * but a useful one. This program demonstrates a variety of usages of a
 * multidimensional array in applications and signify how does it makes the code
 * look cleaner and shortened.
 *
 * @version 0.1
 * @date 2021-02-07
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <stdio.h>

#define MAX_ROWS 4
#define MAX_SUBARRAYS 3
#define MAX_LENGTH 128

/**
 * @brief Two-dimensional array used as a collection of strings.
 */
void twodim_strings() {
    // Each
    char string[MAX_ROWS][MAX_LENGTH] = {
        "this one is a simple array", "part two", "and the third one",
        "but this one is fourth",
        // "nope, it's five" // overflow
    };

    // string = string[][] ... string[0] = "this one is a simple array"
    size_t len = sizeof(string) / sizeof(string[0]);

    fprintf(stdout, "The two-dim array contains %ld strings.\n---\n", len);
}

/**
 * @brief Multidimensional array used as a complex collection of strings.
 */
void multidim_strings() {
    // Explanation: [Total Sub Arrays][Arrays under Sub Arrays][Each Length]
    char string[MAX_SUBARRAYS][MAX_ROWS][MAX_LENGTH] = {
        {"Hello there", "What's up?"},
        {"Bonjour", "Aloha!"},
        // 5 elements > MAX_ROWS --- Overflow if uncommented
        // {"Think", "Thonk", "Thank", "Ok", "ARRAY_OVERFLOW"}
    };

    // sizeof string[][][] / sizeof {"Hello there", "What's up?"}
    size_t len_lvl1 = sizeof(string) / sizeof(string[0]);
    // sizeof {"Hello there", "What's up?"} / sizeof "Hello there"
    size_t len_lvl2 = sizeof(string[0]) / sizeof(string[0][0]);
    // sizeof "Hello there" / sizeof "H"
    size_t len_lvl3 = sizeof(string[0][0]) / sizeof(string[0][0][0]);
    // sizeof {"Hello there", "What's up?"} / sizeof "H"
    size_t len_lvl4 = sizeof(string[0]) / sizeof(string[0][0][0]);
    // sizeof string[][][] / sizeof "H"
    size_t len_lvl5 = sizeof(string) / sizeof(string[0][0][0]);
    
    // Displaying the different sizes contained in the 3-dimemnsional array
    fprintf(stdout, "Total strings at LEVEL1: %ld\n", len_lvl1);
    fprintf(stdout, "Total strings at LEVEL2: %ld\n", len_lvl2);
    fprintf(stdout, "Total strings at LEVEL3: %ld\n", len_lvl3);
    fprintf(stdout, "Total strings at LEVEL4: %ld\n", len_lvl4);
    fprintf(stdout, "Total strings at LEVEL5: %ld\n", len_lvl5);
}

int main(void) {
    twodim_strings();
    multidim_strings();

    return 0;
}