/**
 * @file insertion_sort.c
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief This program describes the implementation of the Insertion Sort
 * algorithm to sort the array elements of an array.
 *
 * @note Best Case Complexity: O(n), Worst Case Complexity: O(n^2),
 * Average Case Complexity: O(n^2). To understand this better, I followed
 * the instructions of: https://www.programiz.com/dsa/insertion-sort
 *
 * @version 0.1
 * @date 2021-02-16
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <stdio.h>

/**
 * @brief Implementation of the Insertion Sort algorithm.
 *
 * @param array The array to be sorted
 * @param n     Size of the array
 */
void insertion_sort(int array[], int n) {
    for (int step = 1; step < n; step++) {
        // At step = 1, assuming the element is already sorted
        int key = array[step];
        int m_key = step - 1;

        // Comparing the 'key' with the (n - 1)th element
        while (key < array[m_key] && m_key > 0) {
            array[m_key + 1] = array[m_key];
            m_key--;
        }

        array[m_key + 1] = key;
    }
}

/**
 * @brief Displays an array on the screen.
 *
 * @param array Array to be displayed
 * @param size  Size of the array
 */
void display_array(int array[], int size) {
    // Displaying each element of the array until (i < size) is true
    for (int i = 0; i < size; i++)
        fprintf(stdout, "%d ", array[i]);

    putchar('\n');
}

int main(void) {
    int unsorted_list[] = {7, 4, -3, 2, 0, 9};
    int size = sizeof(unsorted_list) / sizeof(unsorted_list[0]);

    // Method (to be specific, subroutine) calls
    insertion_sort(unsorted_list, size);
    display_array(unsorted_list, size);

    return 0;
}