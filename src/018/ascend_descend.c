/**
 * @file ascend_descend.c
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief A program that sorts an array with two types. Left-half is sorted
 * in ascending order, the opposite with the right-half.
 *
 * @version 0.1
 * @date 2021-02-18
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Performs swap between two integer variables using pointers.
 *
 * @param x First value
 * @param y Value to be swapped with the first value
 */
void swap(int *x, int *y) {
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

/**
 * @brief The sorting subroutine.
 *
 * @param arr Array to be manipulated
 * @param len Constant length of the array
 */
void sort(int *arr, const int len) {
    // Sorting the left-half in ascending order
    for (int i = len / 2; i < len; i++)
        for (int j = i + 1; j < len; j++)
            if (arr[i] < arr[j])
                swap(&arr[i], &arr[j]);

    // Sorting the left-half in descending order
    for (int i = 0; i < len / 2; i++)
        for (int j = i + 1; j < len / 2; j++)
            if (arr[i] > arr[j])
                swap(&arr[i], &arr[j]);

    // Displaying the manipulated sorted array
    for (int i = 0; i < len; i++)
        fprintf(stdout, "%d ", arr[i]);

    putchar('\n');
}

int main(void) {
    int *arr;
    int len;

    fprintf(stdout, "Size of the pointer: ");

    if (fscanf(stdin, "%d", &len) != 1) {
        fprintf(stderr, "The length must be an integer.\n");
        return EXIT_FAILURE;
    }

    if (len < 0 || len % 2 != 0) {
        fprintf(stderr, "The length must be a positive even integer.\n");
        return EXIT_FAILURE;
    }

    // Initializing the array pointer
    arr = malloc(sizeof(int) * len);

    fprintf(stdout, "Enter the elements: ");

    // Asking for the user input till N (given by the user)
    for (int i = 0; i < len; i++) {
        if (fscanf(stdin, "%d", &arr[i]) != 1) {
            fprintf(stderr, "Input must be an integer.\n");
            return EXIT_FAILURE;
        }
    }

    // Calling the sort() subroutine - the main part of the program
    sort(arr, len);

    return 0;
}