/**
 * @file initial_letters.c
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief A program to find out whether the initial letters of each string given
 * in an array is equal or not.
 * @version 0.1
 * @date 2021-02-06
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <stdio.h>

#define MAX_LENGTH 128

int main(void) {
    char string[][MAX_LENGTH] =
        {"This is string ONE.",
        "This one is TWO.",
        "This is the THIRD string.",
        "This is the FOURTH."};

    char first_letter = string[0][0];
    int total_strs = sizeof(string) / sizeof(string[0]);
    int FLAG = 1;

    // Iterating through each char[]
    for (int i = 0; i < total_strs; i++)
        // If the iterated string's first letter is equal to the common
        // initial_letter, then keep continue, otherwise break and set FLAG = 0
        if (string[i][0] != first_letter) {
            FLAG = 0;
            break;
        }

    if (FLAG)
        fprintf(stdout, "The strings have same initial letters.\n");
    else
        fprintf(stdout, "Not all strings have same initial letters.\n");

    return 0;
}