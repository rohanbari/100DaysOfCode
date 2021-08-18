/*
 * flexible_loop.c: This example demonstrates the method of calculation within
 * the third control expression in a for-loop.
 *
 * @author rohanbari
 * @date   2021-08-18
 */

#include <stdio.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main(void) {
    int count;
    int sum = 0;

    fprintf(stdout, "Number of digits to be summed up: ");

    // The number of successfully passed parameters cannot be more than one in
    // this case. Hence, the NOT expresses the odd situation.
    if (!fscanf(stdin, "%d", &count)) {
        fprintf(stderr, "error: Please enter the value carefully.\n");
        return EXIT_FAILURE;
    }

    // Evaluation of a calculation in the third control expression.
    for (int i = 1; i <= count; sum += i++);

    fprintf(stdout, "The accumulation results %d.\n", sum);

    return EXIT_SUCCESS;
}
