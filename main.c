/**
 * @file main.c
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief Program to check if a string is palindrome.
 * @version 0.1
 * @date 2021-02-17
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <stdio.h>

#define MAX_LEN 128

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

/**
 * @brief Measures the length of a string.
 *
 * @param c String to be measured
 * @return  Length of the string in integer
 */
int c_strlen(const char *c) {
    int counter = 0;

    do
        if (c[counter] == ' ' && c[counter] == '\0')
            counter--;
    while (c[++counter]);

    return --counter;
}

/**
 * @brief Converts a string to lowercase.
 *
 * @param c    String to be converted
 * @param size String length
 */
void c_str_to_lower(char *c, int size) {
    for (int i = 0; i < size; i++)
        if (c[i] > 'A' && c[i] < 'Z')
            c[i] += 'a' - 'A';
}

/**
 * @brief Subroutine to differentiate whether the specified string is a
 * palindrome or not.
 *
 * @param c    The specified string
 * @param size String size
 */
void is_palindrome(const char *c, int size) {
    short int flag = 0;

    for (int i = 0; i < size; i++)
        if (c[i] != c[size - i - 1]) {
            flag = 1;
            break;
        }

    fputs("The string is ", stdout);

    if (flag)
        fputs("not a", stdout);
    else
        fputs("a", stdout);

    fputs(" palindrome.\n", stdout);
}

int main(void) {
    char str[MAX_LEN];

    fprintf(stdout, "Input a string: ");

    // Verification of the user input
    if (fgets(str, MAX_LEN, stdin) == NULL) {
        fprintf(stderr, "[error] Invalid input.\n");
        return EXIT_FAILURE;
    }

    // Removing the newline character and replacing it will a null-terminator
    int len = c_strlen(str) + 1;
    str[len] = 0;

    // Subroutine call to execute further actions
    c_str_to_lower(str, len - 1);
    is_palindrome(str, len - 1);

    return EXIT_SUCCESS;
}