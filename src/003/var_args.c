/**
 * @file var_args.c
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief A program demonstrating the fundamental application of variable
 * number of arguments theory. It's not a very essential feature, but it's
 * worth keeping some knowledge about it.
 *
 * @version 0.1
 * @date 2021-02-03
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

/**
 * @brief Function that makes an attempt to concatenate all the given
 * variable number of strings into one, and return it.
 *
 * @param argc Total number of arguments for prior information
 * @param ...  Variable number of arguments
 * @return     The processed concatenated string
 */
char *dynamic_concat(int argc, ...) {
    va_list dyn_list;
    char *str = (void *)malloc(sizeof(char) * MAX_LEN);

    va_start(dyn_list, argc);

    for (int i = 0; i < argc - 1; i++) {
        // Acquiring singly passed parameter on each iteration
        char *temp = va_arg(dyn_list, char *);

        // Concatenates the parameter char* string
        strcat(str, temp);
        // Adds a whitespace character at the end of 'str' on each iteration
        strcat(str, " ");
    }

    va_end(dyn_list); // va_start() for 'dyn_list' must be paired with va_end()

    return str;
}

int main(void) {
    // All the returned concatenation results will be stored in *ret string
    char *ret = dynamic_concat(5, "Hello", "world,", "what's", "up?");
    // Displays the result in stdout file, i.e. the terminal console
    fprintf(stdout, "After concatenation: \n\n \t%s\n \n", ret);

    return 0;
}