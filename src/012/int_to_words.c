/**
 * @file int_to_words.c
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief A program to convert a string passed via the command-line parameter
 * into words, for example One Two Three. This program uses the most efficient
 * method when taking execution time and numbers of executions in consideration.
 *
 * @version 0.1
 * @date 2021-02-12
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdio.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define MAX_LEN 6

/**
 * @brief The conversion subroutine.
 *
 * @param arg The argument passed to be converted
 */
void conv(char arg[]) {
    int count = 0;
    char numbers[][MAX_LEN] = {"Zero", "One", "Two",   "Three", "Four",
                               "Five", "Six", "Seven", "Eight", "Nine"};

    // Until arg[count] hits a null-terminator
    while (arg[count]) {
        // Converting the specified char to int
        int int_num = arg[count] - '0';
        // Displaying the number corresponding to 'int_num'
        fprintf(stdout, "%s ", numbers[int_num]);
        count++;
    }
    putchar('\n');
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s [option]\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Counts the length of the argument string
    static int len;
    while (argv[1][len++])
        ;

    for (int i = 0; i < len - 1; i++)
        // More likely a custom version of isdigit()
        if (argv[1][i] < '0' || argv[1][i] > '9') {
            fprintf(stderr, "[error] The input must be an integer.\n");
            return EXIT_FAILURE;
        }

    // Calling the conversion subroutine
    conv(argv[1]);

    return 0;
}