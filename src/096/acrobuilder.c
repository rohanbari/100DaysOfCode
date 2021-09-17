/*
 * acrobuilder.c: Build up acronyms. For example, the World Health Organization
 *                has the acronym of W.H.O. Fun program.
 *
 * Author: Rohan Bari
 * Date:   2021-09-19
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REQ_ARGS    3
#define BUFFER_SIZE 128

/*
 * Validate the number of passed arguments.
 */
void validate_args(const int argc, const char *p_name) {
    if (argc < REQ_ARGS) {
        fprintf(stderr, "Usage: %s <full form of the acronym>\n", p_name);
        exit(EXIT_FAILURE);
    }
}

/*
 * Append a character to the end of a string.
 */
void append_char(char *str, char c) {
    size_t len = strlen(str);

    // To prevent buffer overrun undefined-behavior.
    if ((len + 1) > BUFFER_SIZE) {
        fprintf(stderr, "error: Cannot append further. Buffer size is FULL.\n");
        return;
    }

    char arr[2] = {c , '\0'};
    strcat(str, arr);
}

int main(int argc, char **argv) {
    char acronym[BUFFER_SIZE];

    validate_args(argc, argv[0]);

    // Concatenating arguments to full_word with a space (to separate them.)
    for (int i = 1; i < argc; i++) {
        append_char(acronym, argv[i][0]);
        strcat(acronym, ".");
    }

    fprintf(stdout, "Its acronym is: %s\n", acronym);

    return EXIT_SUCCESS;
}
