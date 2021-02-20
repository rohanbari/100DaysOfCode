/**
 * @file variscope.c
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief This program is to represent the effects and helpful cases to use
 * the storage class and its scope.
 *
 * @version 0.1
 * @date 2021-02-19
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <stdio.h>

/**
 * @brief A subroutine that holds the 1st example.
 */
void var_scope_example_1(void) {
    double var = 4.32;

    { // Scope 1
        double var = 7.0;
        fprintf(stdout, "The shadowed variable carried: %.2lf\n", var);

        { // Sub-scope
            var = 0.0; // Altering the shadowed variable's value
            fprintf(stdout, "Now it carries: %.2lf\n", var);
        }
    }

    fprintf(stdout, "The unshadowed value is: %.2lf\n", var);
}

/**
 * @brief Subroutine that describes the storage class alternation
 * and its effect in loops.
 */
void var_scope_loop_example_2() {
    // The iteration will not be affected due to the shadow variable. This
    // code will print '25' five times.
    for (int i = 1; i <= 5; i++) {
        int i = 25; // Shadow variable
        fprintf(stdout, "%d ", i);
    }
    putchar('\n');
}

int main(void) {
    // Calling the subroutines to execute and display the results
    var_scope_example_1();
    var_scope_loop_example_2();

    return 0;
}
