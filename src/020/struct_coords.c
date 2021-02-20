/**
 * @file struct_coords.c
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief This program describes the usage of low-level system calls for various
 * I/O file operations and its significance on performance.
 *
 * @version 0.1
 * @date 2021-02-20
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 128

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

/**
 * @brief Structure for the coordinate (x, y) format.
 */
struct coordinate {
    double x;
    double y;
};

/**
 * @brief Finds the minimum value between two numbers.
 *
 * @param a First number
 * @param b Second number
 * @return Minimum value between two numbers
 */
double min(double a, double b) { return (a < b) ? a : b; }

/**
 * @brief Finds the maximum value between two numbers.
 *
 * @param a First number
 * @param b Second number
 * @return Maximum value between two numbers
 */
double max(double a, double b) { return (a > b) ? a : b; }

/**
 * @brief Calculates the square root of a number
 *
 * @param n Number to be squared root
 * @return Square root of the number
 *
 * @ref Courtesy: https://stackoverflow.com/a/39712957/11471113
 */
double sqrt(double n) {
    double lo = min(1, n), hi = max(1, n), mid;

    while (100 * lo * lo < n)
        lo *= 10;
    while (100 * hi * hi > n)
        hi *= 0.1;

    for (int i = 0; i < 100; i++) {
        mid = (lo + hi) / 2;

        if (mid * mid == n)
            return mid;
        if (mid * mid > n)
            hi = mid;
        else
            lo = mid;
    }

    return mid;
}

/**
 * @brief Subroutine to verify if the required arguments are passed.
 *
 * @param nums Number of arguments
 */
void verify_args(int nums) {
    if (nums != 3) {
        fprintf(stderr, "Usage: ./program [x] [y]\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    struct coordinate *coord = NULL;
    coord = (struct coordinate *)malloc(sizeof(struct coordinate));

    // Verify if the arguments are satisfied
    verify_args(argc);

    // Note that atof() returns zero when the argument is not an integer.
    coord->x = atof(argv[1]);
    coord->y = atof(argv[2]);

    // Calculate with the formula: res = sqrt(x^2 + y^2)
    double diff = sqrt(coord->x * coord->x + coord->y * coord->y);

    // Display the output
    fprintf(stdout,
            "The coordinates are given: (%.2lf, %.2lf)\n"
            "Their difference is: %.2lf\n",
            coord->x, coord->y, diff);

    return 0;
}