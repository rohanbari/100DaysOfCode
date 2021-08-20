/*
 * union.c: Unions are similar to structures in C, except they have some
 * dissimilarities. Firstly, the size of the union is determined by the largest
 * data type that exists in the individual union collection.
 *
 * Lastly, only one variable can be used at a time, the rest declarations will
 * be invalidated since a union points to the same memory location.
 *
 * @author rohanbari
 * @date   2021-08-20
 */

#include <stdio.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

/*
 * The union's structure.
 */
union UseOnceEveryTime {
    int number;
    float temperature;
    double total;
};

int main(void) {
    union UseOnceEveryTime uoet;

    // OK.
    uoet.number = 101;
    fprintf(stdout, "%d\n", uoet.number);

    uoet.total = 5324.12;
    // Undefined behavior: uoet.number is uninitialized.
    fprintf(stdout, "%d %.2lf\n", uoet.number, uoet.total);

    uoet.temperature = 98.7;
    // Undefined behavior: uoet.total is uninitialized.
    fprintf(stdout, "%.2lf %.2f\n", uoet.total, uoet.temperature);

    return EXIT_SUCCESS;
}
