/**
 * @file math_library.c
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief This program illustrates the usage of various elementary mathematical
 * functions defined in math.h library, such as exponential notations, finding
 * trigonometrical ratios, etc. and their essence in programming.
 * 
 * NOTE: To avoid unused variable warnings, use '-Wno-unused-variable' flag
 *
 * @version 0.1
 * @date 2021-02-06
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief This subroutine contains: Various mathematical constants
 */
void math_constants(void) {
    const double pi = M_PI;
    const double log_2e = M_LOG2E;
    const double pi_4 = M_PI_4;
    const double sqrt_2 = M_SQRT2;
}

/**
 * @brief This subroutine contains: Fundamental trigonometrical functions
 */
void math_trigonometry(void) {
    const double THETA = M_PI_4;

    double sin_theta = sin(THETA);
    double cos_theta = cos(THETA);
    double tan_theta = tan(THETA);
}

/**
 * @brief This subroutine contains: Inverse circular functions
 */
void math_inverse_trig(void) {
    const double ALPHA = 0.5;

    double arc_sin = asin(ALPHA);
    double arc_cos = acos(ALPHA);
    double arc_tan = atan(ALPHA);
}

/**
 * @brief This subroutine contains: Exponential and logarithmic functions
 */
void math_expo_logs(void) {
    const double X = 4;

    double power_2_x = exp2(X); // equivalent to exp (x * log (2))
    double log_2 = log(2); // natural logarithm (i.e. to the base e)
    double three_power_4 = pow(3, X);
    double sqrt_4 = sqrt(4); // results 2
    double log_1_p = log1p(X); // log (1 + 4) = log5

    // --- similar syntaxes are used for exotic mathematics --- //
}

/**
 * @brief This subroutine contains: Special mathematical functions
 */
void math_special(void) {
    // returns the natural logarithm of the absolute value of the gamma
    // function of x, note that gamma() is undefined for prior to C99 versions
    double g_p = 0.15;
    double gamma_n = tgamma(g_p);

    // Not that when err_val is too large, 1.0 is returned to the assignee
    const double err_val = 4.4;
    const double error_func = erf(err_val);
}

/**
 * @brief This subroutine contains: Hyperbolic trigonometrical functions
 */
void math_hyperbolic(void) {
    const double X = 1.1;

    // Hyperbolic Sine is equivalent to (exp (x) - exp (-x)) / 2
    double hyp_sine = sinh(X);
    // Hyperbolic Cosine is equivalent to (exp (x) + exp (-x)) / 2
    double hyp_cosine = cosh(X);
    // Hyperbolic Tangent is equivalent to sinh(X) / cosh(X)
    double hyp_tangent = tanh(X);
}

/**
 * @brief This subroutine contains: Pseudorandom number generators
 */
void math_pseudo_random(void) {
    // Generating new seed with the current timestamp
    srand(time(NULL));

    int random_between_1_100 = (rand() % 100) + 1;
}

int main(void) {
    // --- These subroutines have no effects on output --- //

    // Mathematical Constants
    math_constants();
    // Trigonometrical Functions
    math_trigonometry();
    // Inverse Trigonometrical Functions
    math_inverse_trig();
    // Exponents and Logarithms
    math_expo_logs();
    // Hyperbolic Functions
    math_hyperbolic();
    // Special Functions
    math_special();
    // Pseudo-Random Numbers
    math_pseudo_random();

    return 0;
}