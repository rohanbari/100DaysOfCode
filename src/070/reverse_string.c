/*
 * reverse_string.c: Program to reverse a given string without seeking for the
 * help of built-in string functions.
 *
 * @author rohanbari
 * @status PENDING TO BE FINISHED
 * @date   2021-08-19
 */

#include <stdio.h>
#include <stdlib.h>

#define REQ_ARGS   2
#define MAX_LENGTH 512

/*
 * Examine the number of passed arguments.
 */
void validate_args(const int argc, const char *p_name) {
    if (argc != REQ_ARGS) {
        fprintf(stderr, "Usage: %s <string>\n", p_name);
        exit(EXIT_FAILURE);
    }
}

/*
 * Measure the length of the string.
 */
int string_length(const char *str) {
    int counter = 0;
    while (str[++counter]);

    return counter;
}

/*
 * Concatenate two passed strings (by reference) up to N bytes.
 */
void concatenate(char *dest, const char *src, size_t n) {
    size_t dest_len = string_length(dest);
    size_t it = 0;

    for (it = 0; it < n && src[it]; it++) {
        dest[dest_len + it] = src[it];
    }
    dest[dest_len] = 0;
}

/*
 * Reverse the passed string literal.
 */
void reverse_string(const char *str) {
    char *rev = (char *)str;
    int length = string_length(rev);

    for (int idx = 0; idx < length; idx++) {
        rev[idx] = str[length - idx - 2];
    }
    rev[length - 1] = 0;

    fprintf(stdout, "%s\n", rev);
}

int main(int argc, char **argv) {
    char buffer[MAX_LENGTH];

    validate_args(argc, argv[0]);
    concatenate(buffer, argv[1], string_length(argv[1]));

    reverse_string(buffer);

    return EXIT_SUCCESS;
}
