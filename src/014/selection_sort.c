/**
 * @file selection_sort.c
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief This program shows the implementation of the selection sort algorithm
 * to sort a static array efficiently. The time complexity for the worst, best
 * and average cases are O(n^2).
 *
 * @version 0.1
 * @date 2021-02-14
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <stdio.h>

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
 * @brief The selection sort algorithm implementation.
 *
 */
void selection_sort(int array[], int n) {
    for (int step = 0; step < n - 1; step++) {
        // Assuming minimum index is equal to the iteration step
        int min_index = step;

        // If the next step is less than n, compare with the array at
        // minimum index to the current index
        for (int i = step + 1; i < n; i++)
            if (array[i] < array[min_index])
                min_index = i;

        // Swapping the unsorted elements into their correct positions
        swap(&array[min_index], &array[step]);
    }
}

int main(void) {
    int arr_avg[] = {10, -5, 7, 4, -1};
    // // int arr_worst[] = {10, 7, 4, -5, -1};
    // int arr_best[] = {-1, -5, 4, 7, 10};

    // By default, average case is assumed
    int size = sizeof(arr_avg) / sizeof(arr_avg[0]);

    // Calling the selection sort algorithm
    selection_sort(arr_avg, size);

    // Displays the sorted array elements
    for (int i = 0; i < size; i++)
        fprintf(stdout, "%d ", arr_avg[i]);
    putchar('\n');

    return 0;
}