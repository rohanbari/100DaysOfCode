/*
 * vla_initialization.c: This program demonstrates a very specific feature of
 * C programming, which is rarely used in practice. It creates 100 zero-valued
 * rooms, except for the last one will store the integral value -5.
 * 
 * It is to be noted that the size of the array is not explicitly defined, thus,
 * it invokes variable-length array (VLA), which is solely available in C99
 * standard, attempting to compile with any other compiler might result in
 * unpredictable and/or unwanted output.
 *
 * @author rohanbari
 * @date 2021-08-16
 */

#include <stdio.h>

#define EXIT_SUCCESS 0
#define MAX_ELEMENTS 100

int main(void) {
    // Invoking variable-length array.
    int array[] = {[MAX_ELEMENTS - 1] = -5};
    // Obtaining the length of the array explicitly.
    short int len = sizeof array / sizeof array[0];

    for (int idx = 0; idx < len; idx++) {
        fprintf(stdout, "%4d index has %2d.\n", idx, array[idx]);
    }

    return EXIT_SUCCESS;
}
