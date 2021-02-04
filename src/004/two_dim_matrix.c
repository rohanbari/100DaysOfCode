/**
 * @file two_dim_matrix.c
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief The Matrix is an elementary concept developed in Mathematics where
 * the word 'array' was firstly coined. In this program, I've demo-ed a simple
 * concept and essence of matrices programmatically.
 *
 * @version 0.1
 * @date 2021-02-04
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main(void) {
    int size = 0;

    fprintf(stdout, "Number of rows or columns for square matrix: ");

    if (!fscanf(stdin, "%d", &size)) {
        fprintf(stdout, "The input must be a valid integer.\n");
        return EXIT_FAILURE;
    }

    // Constructing a variable length array
    int matrix[size][size];

    // Filling each room of the matrix[][] with zeroes
    memset(matrix, 0, sizeof(matrix[0][0]) * size * size);

    fprintf(stdout, "Fill up the numbers up to %dx%d:\n", size, size);

    // Acquiring user input to fill up each room of the matrix[][]
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (!fscanf(stdin, "%d", &matrix[j][i])) {
                fprintf(stdout, "The input must be a valid integer.");
                return EXIT_FAILURE;
            }

    fprintf(stdout, "The stored rooms are as follows:\n\n");

    // Outputting the matrix in vertical order
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            fprintf(stdout, "  %d", matrix[i][j]);

        fputs("\n", stdout);
    }
    fputs("\n", stdout);

    return EXIT_SUCCESS;
}