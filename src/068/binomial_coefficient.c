/*
 * binomial_coefficient.c: The binomial coefficients are the positive integers
 * that occur as coefficients in the binomial theorem. This program elucidate
 * the behind-the-scene of it.
 *
 * @author rohanbari
 * @date   2021-08-17
 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define REQ_ARGS 3
#define BASE_LOG 10

/*
 * Examine the number of the passed arguments.
 */
void examine_args(int argc, const char *p_name) {
    if (argc != REQ_ARGS) {
        fprintf(stderr, "Usage: %s <lower> <upper>\n", p_name);
        exit(EXIT_FAILURE);
    }
}

/*
 * Evaluate the factorial of a given integer.
 */
long long factorial_of(int val) {
    long long result = 1;

    for (int idx = 1; idx <= val; idx++) {
        result *= idx;
    }
    return result;
}

/*
 * This function evaluates the binomial coefficient.
 */
long long binomial_coefficient(int lower, int upper) {
    // If the value of N is lesser than K.
    if (upper < 0 || lower < 0) {
        fprintf(stderr, "error: The values must be positive integers.\n");
        exit(EXIT_FAILURE);
    }

    if (upper < lower) {
        fprintf(stderr, "error: The upper value must be greater than or equal "
                        "to the lower value.\n");
        exit(EXIT_FAILURE);
    }

    long long upper_fact = factorial_of(upper);
    long long lower_fact = factorial_of(lower);

    if (upper_fact > LLONG_MAX || upper_fact < INT_MIN) {
        fprintf(stderr, "warn: The upper limit is overflowed/underflowed.\n");
        exit(EXIT_FAILURE);
    }

    if (lower_fact > LLONG_MAX || lower_fact < INT_MIN) {
        fprintf(stderr, "warn: The lower limit is overflowed/underflowed.\n");
        exit(EXIT_FAILURE);
    }

    // (N_K) = N! / (K! * (N - K)!)
    long long expr = factorial_of(upper) / (factorial_of(lower) * \
        factorial_of(upper - lower));
    return expr;
}

int main(int argc, char **argv) {
    examine_args(argc, argv[0]);
    long long res = binomial_coefficient(strtoll(argv[1], NULL, BASE_LOG),
        strtoll(argv[2], NULL, BASE_LOG));

    fprintf(stdout, "Binomial coefficient is %lld.\n", res);

    return EXIT_SUCCESS;
}
