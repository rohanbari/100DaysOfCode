/*
 * number_to_words.c: Program to convert an numeric value into words, e.g. 1503
 * into One Thousands Three.
 *
 * Author: Rohan Bari
 * Date:   2021-09-03
 */

#include <stdio.h>
#include <stdlib.h>

#define REQ_ARGS 2

typedef enum {
    false,
    true
} bool;

/*
 * Verify if the number is a numeric digit.
 */
bool is_digit(const char *str) {
    int counter = 0;

    // Equivalent as (str[counter] != '\0') condition.
    while (str[counter]) {
        int expr = str[counter] - '0';

        if (expr < 0 || expr > 9)
            return false;
        counter++;
    }
    return true;
}

/*
 * Validate the number of arguments passed to the program.
 */
void validate_arguments(const int argc, const char *p_name) {
    if (REQ_ARGS != argc) {
        fprintf(stderr, "Usage: %s <number>\n", p_name);
        exit(EXIT_FAILURE);
    }
}

/*
 * The conversion subroutine.
 */
void conversion(const char *number) {
    // TODO: Begin the conversion system development.
}

int main(int argc, char **argv) {
    validate_arguments(argc, argv[0]);

    // Verify whether the number is an integer or not.
    if (!is_digit(argv[1])) {
        fprintf(stderr, "error: The argument must be an integer.\n");
        return EXIT_FAILURE;
    }
    conversion(argv[1]);

    return EXIT_SUCCESS;
}
