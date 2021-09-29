/*
 * number_to_words.c: Program to convert an numeric value into words, e.g. 1503
 * into One Thousands Three.
 *
 * Author: Rohan Bari
 * Date:   2021-09-03, 2021-09-05
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REQ_ARGS    2
#define BUFFER_SIZE 24
#define MAX_LENGTH  256

typedef enum {
    false,
    true
} bool;

const char *ones[] = {
    "", "One ", "Two ", "Three ", "Four ",
    "Five ", "Six ", "Seven ", "Eight ",
    "Nine ", "Ten ", "Eleven ", "Twelve ",
    "Thirteen ", "Fourteen ", "Fifteen ",
    "Sixteen ", "Seventeen ", "Eighteen ",
    "Nineteen "
};
const char *tens[] = {
    "", "",
    "Twenty ", "Thirty ", "Forty ", "Fifty ",
    "Sixty ", "Seventy ", "Eighty ", "Ninety "
};

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
 * Place value conversion system.
 */
char *conv_base(const int pos, const char *unit, char *buf, int len) {
    memset(buf, 0, len);

    if (pos > (BUFFER_SIZE - 1)) {
        strcat(buf, tens[pos / 10]);
        strcat(buf, ones[pos % 10]);
    } else
        strcat(buf, ones[pos]);

    if (pos)
        strcat(buf, unit);
    return buf;
}

/*
 * The conversion subroutine.
 */
void conversion(const char *number) {
    char buffer[MAX_LENGTH];
    char str[BUFFER_SIZE] = {0};
    long n = strtol(number, NULL, 10);

    strcat(buffer, conv_base(n / 10000000, "Crore ", str, BUFFER_SIZE));
    strcat(buffer, conv_base(n / 100000 % 100, "Lakh ", str, BUFFER_SIZE));
    strcat(buffer, conv_base(n / 1000 % 100, "Thousand ", str, BUFFER_SIZE));
    strcat(buffer, conv_base(n / 100 % 10, "Hundred ", str, BUFFER_SIZE));

    if (n > 100 && n % 100) {
        strcat(buffer, "and ");
    }

    strcat(buffer, conv_base(n % 100, "", str, BUFFER_SIZE));

    fprintf(stdout, "%s\n", buffer);
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
