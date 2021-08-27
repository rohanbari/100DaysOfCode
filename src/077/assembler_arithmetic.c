/*
 * assembler_arithmetic.c: Apply the arithmetic operations using inline assembly
 * feature in C programming. Quite an exhausting job.
 *
 * @author rohanbari
 * @date   2021-08-27
 */

#include <stdio.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

/*
 * Structural definition.
 */
struct Result {
    int addition;
    int subtraction;
    int multiplication;
};

int main(void) {
    int value1, value2;
    struct Result result;

    fprintf(stdout, "Enter any two integral values: ");

    // Examining the passage of values.
    if (fscanf(stdin, "%d%d", &value1, &value2) != 2) {
        fprintf(stderr, "error: The value is inappropriately given.\n");
        return EXIT_FAILURE;
    }

    __asm__ ("addl %%ebx, %%eax;" : "=a" (result.addition) : "a" \
                (value1) , "b" (value2));
    __asm__ ("subl %%ebx, %%eax;" : "=a" (result.subtraction) : "a" \
                (value1) , "b" (value2));
    __asm__ ("imull %%ebx, %%eax;" : "=a" (result.multiplication) : "a" \
                (value1) , "b" (value2));

    fprintf(stdout, "%d + %d = %d\n", value1, value2, result.addition);
    fprintf(stdout, "%d - %d = %d\n", value1, value2, result.subtraction);
    fprintf(stdout, "%d * %d = %d\n", value1, value2, result.multiplication);

    return EXIT_SUCCESS;
}
