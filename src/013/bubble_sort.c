/**
 * @file bubble_sort.c
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief This program is intended to demonstrate the implementation of the
 * bubble sort algorithm to sort an unsorted array efficiently.
 *
 * @version 0.1
 * @date 2021-02-13
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <stdio.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

void swap(int *x, int *y) {
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

void bubble_sort(int array[], int n) {
    for (int step = 0; step < n - 1; step++)
        for (int it = 0; it < n - step - 1; it++)
            if (array[it] > array[it + 1])
                swap(&array[it], &array[it + 1]);
}

int main(void) {
    int arr[] = {1, 4, -3, 7, 10, -5};
    int size = sizeof(arr) / sizeof(arr[0]);

    bubble_sort(arr, size);

    for (int i = 0; i < size; i++)
        fprintf(stdout, "%d ", arr[i]);
    putchar('\n');

    return EXIT_SUCCESS;
}