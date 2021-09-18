/*
 * trigono.c: Program to establish the relationship between angles and the
 *            values of their corresponding trigonometric ratios.
 *            Represents graphically in TABULAR FORM.
 *
 *            Note: It should be compiled with '-lm' compiler flag.
 *
 * Author: Rohan Bari
 * Date:   2021-09-22
 */

#include <stdio.h>
#include <math.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define MAX_ANGLE    90.000

// Trigonometrical ratio enumeration.
typedef enum {
    SINE,
    COSINE,
    TANGENT
} RatioType;

/*
 * Covert the specified degrees into radians.
 */
double to_rad(const double degrees) {
    double expr = (degrees * M_PI) / 180.000;
    return expr;
}

/*
 * Generates the required trigonometric table.
 */
void form_table_of(const RatioType type, const double value, const double max) {
    static int counter = 0;

    fprintf(stdout, "%4d | %6.4f\n", counter, value);

    if (counter == max) {
        counter = 0;
        fprintf(stdout, "=============\n");
        return;
    }
    counter++;

    switch (type) {
        case SINE:
            form_table_of(SINE, sin(to_rad(counter)), max);
            break;
        case COSINE:
            form_table_of(COSINE, cos(to_rad(counter)), max);
            break;
        case TANGENT:
            form_table_of(TANGENT, tan(to_rad(counter)), max);
            break;
        default:
            break;
    }
}

int main(void) {
    double angle = 0.0;

    form_table_of(SINE, sin(to_rad(angle)), MAX_ANGLE);
    form_table_of(COSINE, cos(to_rad(angle)), MAX_ANGLE);
    // Note: The tangent has indefinite value at (M_PI / 2), hence reduced by 1.
    form_table_of(TANGENT, tan(to_rad(angle)), MAX_ANGLE - 1.00);

    return EXIT_SUCCESS;
}
