/**
 * @file overflow.c
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief A program to demonstrate various possibilities of overflows
 * and how to tackle them efficiently, without having undefined behaviors.
 *
 * @version 0.1
 * @date 2021-02-02
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <float.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Subroutine to demonstrate the explicit overflow of a UL type integer
 * and the correct path to prevent it. High chances of happening in practical
 * usage if the user wants more storage capacity.
 *
 * Expands up to: unsigned 4294967295U
 *
 */
void overflow_ULi(void) {
    // Attempting to overflow the unsigned long int size
    size_t ULI = 99999999999999999999999999999;

    // Verification of overflow
    if (ULI > UINT32_MAX) {
        // Tends to display unpredictable garbage values
        fprintf(stdout, "%ld\nOverflowed unsigned long int.\n", ULI);
        // return;
    }
}

/**
 * @brief Subroutine to indicate the explicit overflow of a double floating-
 * point type (the capability of this datatype is too large, chances of an
 * overflow in this type is extremely low in its actual usage) and the
 * right path to prevent this.
 *
 * Expands up to: long 1.79769313486231570814527423731704357e+308L
 *
 */
void overflow_dbl_prec() {
    // Attempting to overflow the double type
    double doub = 1.8e+308L;

    // Verification of overflow
    if (doub > __DBL_MAX__) {
        // Will display 'inf' in most compilers
        fprintf(stdout, "%lf\nOuch, a big overflow just happened.\n", doub);

        exit(EXIT_FAILURE); // return EXIT_FAILURE could be used too,
                            // but the return type in this sub. is void
    }
}

int main(void) {
    overflow_ULi();      // These calls of subroutines will
    overflow_dbl_prec(); // execute the above definitions of them

    /* ... Similarly, other datatypes could be found out ... */
    /* ... if they've been overflowed.                   ... */

    return EXIT_SUCCESS;
}