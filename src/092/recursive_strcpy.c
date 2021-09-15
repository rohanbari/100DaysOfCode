/*
 * recursive_strcpy.c: This program copies a string to a new string with the
 *                     help of recursion concept.
 *
 * Author: Rohan Bari
 * Date:   2021-09-15
 */

#include <stdio.h>
#include <stdlib.h>

#define REQ_ARGS   2
#define MAX_LENGTH 1024

/*
 * Validate the number of passed arguments.
 */
void validate_args(const int argc, const char *p_name) {
    if (REQ_ARGS != argc) {
        fprintf(stderr, "Usage: %s <word>\n", p_name);
        exit(EXIT_FAILURE);
    }
}

/*
 * Copy the passed string recursively into a new variable.
 */
void rec_strcpy(char *src, char *dest) {
    static size_t len = 0;

    dest[len] = src[len];

    if (src[len] != '\0') {
        len++;
        rec_strcpy(src, dest);
    }
}

int main(int argc, char **argv) {
    char new_string[MAX_LENGTH];

    validate_args(argc, argv[0]);
    rec_strcpy(argv[1], new_string);

    fprintf(stdout, "The new string contains: %s\n", new_string);

    return EXIT_SUCCESS;
}
