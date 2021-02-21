/**
 * @file pattern_design.c
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief This program has the ability to draw different shapes.
 * @version 0.1
 * @date 2021-02-21
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REQ_ARGS 3

/**
 * @brief Verifies if the argument requirement is met.
 *
 * @param n Number of arguments
 */
void verify_args(int n) {
    if (n != REQ_ARGS) {
        fprintf(stderr, "Usage: ./program [option] [quantity]\n");
        exit(EXIT_FAILURE);
    }
}

/**
 * @brief Display the help manual for this program.
 */
void display_help(const char *arg) {
    fprintf(stdout,
            "Usage: %s [option] [quantity]\n\n"
            "OPTIONS:\n"
            "  -h --help         Show this help message\n"
            "  -s --square       Make a square shape\n"
            "  -t --triangle     Make a triangular shape\n"
            "  -d --diamond      Make a diamond-like shape\n\n"
            "NOTE:  The quantity must be an integer.\n\n",
            arg);
    exit(EXIT_SUCCESS);
}

/**
 * @brief All the important algorithm to create a pattern design.
 *
 * @param code Code number of the pattern
 */
void draw_shape(short int code, int arg) {
    switch (code) {
        // Square
        case 1: {
            for (int i = 0; i < arg; i++) {
                for (int j = 0; j < arg; j++)
                    fprintf(stdout, "* ");

                putchar('\n');
            }

            break;
        }
        // Triangle
        case 2: {
            for (int i = 0; i < arg; i++) {
                for (int j = 0; j <= i; j++)
                    fprintf(stdout, "* ");

                putchar('\n');
            }

            break;
        }
        // Diamond
        case 3: {
            int space = arg - 1;

            // Run loop (parent loop)
            // till number of rows
            for (int i = 0; i < arg; i++) {
                // Loop for initially space,
                // before star printing
                for (int j = 0; j < space; j++)
                    putchar(' ');

                // Print (i + 1) stars
                for (int j = 0; j <= i; j++)
                    fprintf(stdout, "* ");

                putchar('\n');

                space--;
            }

            // Repeat again in reverse order
            space = 0;

            // Run loop (parent loop)
            // till number of rows
            for (int i = arg; i > 0; i--) {
                // Loop for initially space,
                // before star printing
                for (int j = 0; j < space; j++)
                    putchar(' ');

                // Print N stars
                for (int j = 0; j < i; j++)
                    fprintf(stdout, "* ");

                putchar('\n');

                space++;
            }
            
            break;
        }
        default: {
            fprintf(stderr, "[error] Logically shape unknown.\n");
            exit(EXIT_FAILURE);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc == REQ_ARGS - 1 &&
        (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)) {
        display_help(argv[0]);
    }

    verify_args(argc);

    int num = atoi(argv[2]);

    if (strcmp(argv[1], "--square") == 0 || strcmp(argv[1], "-s") == 0)
        draw_shape(1, num);
    else if (strcmp(argv[1], "--triangle") == 0 || strcmp(argv[1], "-t") == 0)
        draw_shape(2, num);
    else if ((strcmp(argv[1], "--diamond") == 0 || strcmp(argv[1], "-d") == 0))
        draw_shape(3, num);
    else {
        fprintf(stderr,
                "[error] No such option '%s'.\n"
                "Try '-h' or '--help' to get help.\n",
                argv[1]);
        return EXIT_FAILURE;
    }

    return 0;
}