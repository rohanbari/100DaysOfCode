/**
 * @file manip_pointers.c
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief A program demonstrating various experiments on pointers, such as
 * arithmetic operations, referencing variables, dereferencing pointers, etc.
 *
 * @version 0.1
 * @date 2021-02-04
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief The core structure of the 'Type' datatype.
 */
typedef struct {
    int x;
    int y;
} Type;

/**
 * @brief Function to initialize the passed pointer and return it to the same
 * pointer where the function was called.
 *
 * @param t The passed pointer parameter
 * @return  Initialized Type* parameter
 */
Type *init(Type *t) {
    t = (Type *)malloc(sizeof(Type));

    t->x = 0; // Initializing the struct members
    t->y = 0; // with a zero

    return t;
}

/**
 * @brief Function that performs the most basic arithmetic operations used in
 * Mathematics that takes an argument of type Type structure.
 *
 * @param t    The initialized structure as argument
 * @param op   Operation to perform, '+', '-', '*', '/'
 * @return     Result of X (op) Y
 */
int operation(Type *t, char op) {
    int result = 0;

    // Deciding operations depends upon the passed 'op' here
    switch (op) {
        case '+': {
            result = t->x + t->y; // Addition
            break;
        }
        case '-': {
            result = t->x - t->y; // Subtraction
            break;
        }
        case '*': {
            result = t->x * t->y; // Multiplication
            break;
        }
        case '/': {
            // In case the denominator is zero
            if (t->y == 0) {
                fprintf(stdout, "Denominator must not be zero for division.\n");
                return -1;
            }

            result = t->x / t->y; // Division
            break;
        }
        default: {
            return -1;
        }
    }

    return result; // The produced results are returned
}

int main(void) {
    Type *ret_var = NULL;
    ret_var = init(ret_var);

    fprintf(stdout, "\nThe initialized values are: %d %d.\n", ret_var->x,
            ret_var->y);

    fprintf(stdout, "Please enter the values of t->x and t->y respectively: ");

    if (fscanf(stdin, "%d%d", &ret_var->x, &ret_var->y) != 2) {
        fprintf(stdout, "The values must be integers.\n");
        return EXIT_FAILURE;
    }

    fputs("", stdout);

    int add = operation(ret_var, '+');
    int subtract = operation(ret_var, '-');
    int multiply = operation(ret_var, '*');
    int divide = operation(ret_var, '/');

    fprintf(stdout,
            "\nAddition of t->x and t->y is: %d\nSubtraction of t->x from t-> "
            "is: %d\nMultiplication of t-> and t->y is: %d\nDivision of t->x "
            "from t->y is: %d\n\n",
            add, subtract, multiply, divide);

    return EXIT_SUCCESS;
}