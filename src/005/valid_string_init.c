/**
 * @file valid_string_init.c
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief This program introduces a number of methods to initialize strings
 * effectively throughout different situations. Most of the amateur programmers
 * stay confused with these, so this clarifies their conceptions too.
 *
 * @version 0.1
 * @date 2021-02-05
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 128

int main(void) {
    // --- VALID TYPES OF INITIALIZATION OF STRINGS --- //

    // Any char* type that is instantly initialized, doesn't require manual
    // memory allocation and saves time
    char *str_origin = "This is a simple string.";
    fprintf(stdout, "original: %s\n", str_origin);

    // Declaring and initializing to NULL
    char *str_2 = NULL;
    // Allocated required bytes of memory + one extra for a null-terminator
    str_2 = (void *)malloc(sizeof(char) * (strlen(str_origin) + 1));

    // Copy string using memcpy() [efficient and safe]
    memcpy(str_2, str_origin, strlen(str_origin) + 1);
    fprintf(stdout, "memcpy to str_2 from str_1: %s\n", str_2);

    // Direct assignment of a previously initialized char* into another
    char *str_3 = str_2;
    fprintf(stdout, "direct init: %s\n", str_3);

    // String initialization using the user input for dynamic memory allocation
    char *str_4 = NULL;
    int len = 0;

    fprintf(stdout, "user input: ");

    if (fscanf(stdin, "%d", &len) != 1) {
        fprintf(stderr, "Invalid input passed.");
        return EXIT_FAILURE; // In case the input was not an integer
    }

    // Dynamic memory allocation of LEN bytes using user's input
    // and performing raw string copy using strncpy() - safer than strcpy()
    str_4 = malloc(sizeof(char) * len);
    fprintf(stdout, "%d bytes allocated in the memory.\n", len);
    // If len < strlen("STRING"), it's okay, no undefined-behavior will invoke
    strncpy(str_4, "STRING", len);

    fprintf(stdout, "str_4 has: %s\n", str_4);

    return EXIT_SUCCESS;
}