/*
 * anagrams.c: Check whether two strings are anagrams or not.
 *
 * Author: Rohan Bari
 * Date:   2021-09-13
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REQ_ARGS 3

typedef enum {
    false,
    true
} bool;

/*
 * Validate the number of passed arguments.
 */
void validate_arguments(const int argc, const char *p_name) {
    if (REQ_ARGS != argc) {
        fprintf(stderr, "Usage: %s <first word> <second word>\n", p_name);
        exit(EXIT_FAILURE);
    }
}

/*
 * Validate whether the string contains non-alphabetic characters.
 */
void validate_string(const char *str) {
    // The condition is equivalent to: str[i] != '\0'
    for (int i = 0; str[i]; i++)
        if (str[i] < 'A' || str[i] > 'z') {
            fprintf(stderr, "%s: Only alphabets are supported.\n", __func__);
            exit(EXIT_FAILURE);
        }
}

/*
 * Sort the passed string. (Overrides content!)
 */
char *sort_string(char *str) {
    size_t len = strlen(str);

    for (int i = 0; i < (int)len - 1; i++)
        for (int j = i + 1; j < (int)len; j++)
            // Swap between two strings if the ASCII-code of str[i] is greater
            // than that of str[j] character.
            if (str[i] > str[j]) {
                str[i] += str[j];
                str[j] = str[i] - str[j];
                str[i] -= str[j];
            }

    // Returning the modified string.
    return str;
}

/*
 * Check whether the passed string is an anagram. (Overrides content!)
 */
bool is_anagram(char *str1, char *str2) {
    sort_string(str1);
    sort_string(str2);

    return !strcmp(str1, str2);
}

int main(int argc, char **argv) {
    bool status = false;

    // Validation processes...
    validate_arguments(argc, argv[0]);
    validate_string(argv[1]);
    validate_string(argv[2]);

    status = is_anagram(argv[1], argv[2]);

    fprintf(stdout, "The strings are %s anagrams.\n", (status ? "\b" : "not"));

    return EXIT_SUCCESS;
}
