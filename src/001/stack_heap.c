/**
 * @file stack_heaps.c
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief A program demonstrating the declaration that signifies the
 * difference between Stacks and Heaps.
 *
 * @version 0.1
 * @date 2021-02-01
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#define EXAMPLE_STACK_SIZE 16

/**
 * @brief Subroutine to demonstrate a few
 * styles of declaring variables that loads on stack.
 *
 */
void stack_decls(void) {
    int max = EXAMPLE_STACK_SIZE;

    int var[EXAMPLE_STACK_SIZE]; // Example 1: Good for both C/C++
    int vla_good[max];           // Example 2: Only valid for C99
}

/**
 * @brief Every line of the code inside this subroutine
 * that signifies declaration on heap portion.
 *
 */
void heap_decls(void) {
    // Example 1: ptr is a type of int* here, since it's dynamically allocated
    //            into memory, it belongs to HEAP.
    int *ptr = malloc(sizeof(int) * EXAMPLE_STACK_SIZE);

    /* ... Some usage of *ptr ... */

    free(ptr); // Deallocation of used memory
}

int main(void) {
    stack_decls(); // Calling these subroutines have
    heap_decls();  // no effects in output

    return 0;
}