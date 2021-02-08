/**
 * @file recursion.c
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief This program is intended to describe the implementation and usage
 * of recursion method.
 * @version 0.1
 * @date 2021-02-08
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <stdio.h>

/**
 * @brief The recursive function (implementation of the first method)
 */
void recursive_function_sample1() {
    // Using static statements are kept remembered even after reaching
    // the end of the function
    static int counter;
    counter++;

    // As soon as the counter++ hits 10, return nothing and quit
    if (counter == 10)
        return;
    else
        // Calling the recursive function (itself)
        recursive_function_sample1();

    fprintf(stdout, "recursive_function_sample1()!\n");
}

/**
 * @brief The recursive function (implementation of the second method)
 */
void recursive_function_sample2(int counter) {
    counter++;

    if (counter == 10) {
        fprintf(stdout, "---\n");
        return;
    } else
        // Calling the recursive function (itself)
        recursive_function_sample2(counter);

    fprintf(stdout, "recursive_function_sample2()!\n");
}

/**
 * @brief Finds the summation till N using recursion.
 *
 * @param counter Value of N in Summation
 * @return        The sum till N is zero
 */
int sum_till(int counter) {
    if (counter > 0)
        // (N - 1) + N
        return sum_till(counter - 1) + counter;
    else
        return counter;
}

/**
 * @brief Finds the factorial of a given number using recursion
 *
 * @param counter Upper limit of the factorial
 * @return        Factorial till N
 */
int factorial_till(int counter) {
    if (counter > 1)
        // (N - 1) * N
        return factorial_till(counter - 1) * counter;
    else
        return counter;
}

int main(void) {
    recursive_function_sample1();
    recursive_function_sample2(0);

    fprintf(stdout, "---\n");

    int sum = sum_till(10);       // 10 + 9 + ... + 1  = 55
    int fact = factorial_till(5); // 5 * 4 * 3 * 2 * 1 = 120

    fprintf(stdout, "Total sum till N = 10 is %d.\n", sum);
    fprintf(stdout, "Factorial if N = 5 is %d.\n", fact);

    return 0;
}