/**
 * @file tokenization.c
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief This program describes the tokenization of strings using strtok().
 * @version 0.1
 * @date 2021-02-15
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX_LEN 128

int main(void) {
    // The required 2-D string
    char str[][MAX_LEN] = {"FirstVal : Value1", "Sec : 4", "ThirdValue : X"};
    int size = sizeof(str) / sizeof(str[0]);

    // Applying Variable-Length Array (valid in C)
    char elements[size][MAX_LEN];

    for (int i = 0; i < size; i++) {
        // Declaring a temporary pointer variable to obtain the required
        // substring from each string
        char *sub_str = NULL;
        sub_str = strtok(str[i], ": ");
        sub_str = strtok(NULL, ": ");

        // Copying the 'sub_str' into each array element of 'store_cared_ones'
        strcpy(elements[i], sub_str);
    }

    // Displaying each of 'store_cared_ones'
    for (int i = 0; i < size; i++)
        fprintf(stdout, "%s\n", elements[i]);

    return 0;
}