/*
 * histogram.c: Program to represent a given data in Histogram format.
 *
 * Author: Rohan Bari <rohanbari4@gmail.com>
 * Date:   2021-09-05
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REQ_ARGS 2

typedef enum {
    false,
    true
} bool;

/*
 * Validate the number of passed arguments.
 */
void validate_args(const int argc, const char *p_name) {
    if (REQ_ARGS != argc) {
        fprintf(stderr, "Usage: %s <number of rooms>\n", p_name);
        exit(EXIT_FAILURE);
    }
}

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
 * Display the histogram data visually.
 */
void display_histogram(const int data_len, const char symbol) {
    for (int i = 0; i < data_len; i++) {
        fprintf(stdout, "%c", symbol);
    }
    fputc('\n', stdout);
}

int main(int argc, char **argv) {
    int *data = NULL;
    int total_rooms = 0;

    validate_args(argc, argv[0]);

    // Validate whether the argument was a valid integer.
    if (!is_digit(argv[1])) {
        fprintf(stderr, "error: The number of rooms must be an integer.\n");
        return EXIT_FAILURE;
    }

    // Conversion from string to an integer.
    total_rooms = atoi(argv[1]);
    // Initializing the pointer with all the rooms assigned to zero.
    data = (int *)calloc(total_rooms, sizeof(int));

    for (int i = 0; i < total_rooms; i++) {
        fprintf(stdout, "Value for room %d: ", (i + 1));

        if (!fscanf(stdin, "%d", &data[i])) {
            fprintf(stderr, "error: The value must be an integer.\n");
            return EXIT_FAILURE;
        }
    }
    fputc('\n', stdout);

    fprintf(stdout, "ID  Data\n");

    // Display the graphical representation.
    for (int i = 0; i < total_rooms; i++) {
        fprintf(stdout, "%-4d", (i + 1));
        display_histogram(data[i], '@');
    }

    return EXIT_SUCCESS;
}
