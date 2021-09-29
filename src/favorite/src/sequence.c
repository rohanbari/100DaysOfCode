/*
 * sequence.c: This beautiful program has the ability to form three types of
 *             mathematical sequences: Arithmetic, Geometric, and Harmonic
 *             progressions.
 *
 *             Check out <https://en.wikipedia.org/wiki/Sequence> obtain a
 *             detailed explanation about the mathematical sequences.
 *
 *             Note: Must be compiled with  -lm  compiler flag.
 *
 * Author: Rohan Bari
 * Date:   2021-09-14
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define NOCOLOR  "\033[0m"
#define RED      "\033[1;31m"
#define GREEN    "\033[1;32m"
#define YELLOW   "\033[1;33m"
#define BLUE     "\033[1;34m"

// Basic Boolean type.
typedef enum {
    false,
    true
} bool;

// Sequence type.
typedef enum {
    ARITHMETIC = 1,
    GEOMETRIC  = 2,
    HARMONIC   = 3
} Sequence;

/*
 * Discards the standard input values.
 */
void flush_stdin(void) {
    int n = 0;
    while ((n = getchar()) != '\n' && n != EOF)
        ;
}

/*
 * Display the program's banner on the screen.
 */
void display_banner(void) {
    const char *content =
        "o==========================================================o\n" \
        "| MATHEMATICAL SEQUENCE GENERATOR              v1.0-stable |\n" \
        "o==========================================================o\n" \
        "| In Mathematics, a sequence is an enumerated collection of|\n" \
        "| objects in which repetitions are allowed and the order   |\n" \
        "| matters.                                                 |\n" \
        "|                                                          |\n" \
        "| Using this program, one can evaluate the following:      |\n" \
        "|          <ARITHMETIC>  <GEOMETRIC>  <HARMONIC>           |\n" \
        "o----------------------------------------------------------o\n" \
        "|        This program is created and maintained by         |\n" \
        "|            Rohan Bari <rohanbari4@gmail.com>             |\n" \
        "o==========================================================o\n";

    // Portable method to clear the standard output.
    if (system("@cls||clear") != EXIT_SUCCESS) {
        fprintf(stderr, RED "%s: Failed to clear screen.\n" NOCOLOR, __func__);
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, BLUE "%s\n" NOCOLOR, content);
}

/*
 * Arithmetic progression.
 */
void arithmetic_sequence(void) {
    double first_term = 0.0;
    double cd = 0.0;
    int terms = 0;
    
    fprintf(stdout, "First Term, Common Difference, and Total No. of Terms: ");
    
    if (fscanf(stdin, "%lf%lf%d", &first_term, &cd, &terms) != 3) {
        fprintf(stderr, RED "error: Bad input.\n" NOCOLOR);
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "o==============o=============================o\n"
                    "| Nth Term     | Value                       |\n"
                    "o==============o=============================o\n");

    for (int i = 1; i <= terms; i++) {
        double g_term = first_term + (i - 1) * cd;
        fprintf(stdout, "| %-12d | %-27.2lf |\n", i, g_term);
    }
    // Calculating the sum of the A.P.
    long double sum = (terms / 2.0) * (2 * first_term + (terms - 1) * cd);

    fprintf(stdout, "o==============o=============================o\n");
    fprintf(stdout, "| Total Sum    | %-27.2Lf |\n", sum);
    fprintf(stdout, "o============================================o\n\n");
}

/*
 * Geometric progression.
 */
void geometric_sequence(void) {
    double first_term = 0.0;
    double cr = 0.0;
    int terms = 0;

    fprintf(stdout, "First Term, Common Ratio, and Total No. of Terms: ");

    if (fscanf(stdin, "%lf%lf%d", &first_term, &cr, &terms) != 3) {
        fprintf(stderr, RED "error: Bad input.\n" NOCOLOR);
        exit(EXIT_FAILURE);
    }
    
    fprintf(stdout, "o==============o=============================o\n"
                    "| Nth Term     | Value                       |\n"
                    "o==============o=============================o\n");
    
    for (int i = 1; i <= terms; i++) {
        double g_term = first_term * pow(cr, i - 1);
        fprintf(stdout, "| %-12d | %-27.2lf |\n", i, g_term);
    }

    long double sum = 0.0;

    // Calculating the sum of the G.P.
    if (cr != 1.0)
        sum = first_term * (1.0 - pow(cr, terms)) / (1 - cr);
    else
        sum = terms * first_term;

    fprintf(stdout, "o==============o=============================o\n");
    fprintf(stdout, "| Total Sum    | %-27.2Lf |\n", sum);
    fprintf(stdout, "o============================================o\n\n");
}

/*
 * Harmonic sequence.
 */
void harmonic_sequence(void) {
    double first_term = 0.0;
    double cd = 0.0;
    int terms = 0;

    fprintf(stdout, "First Term, Common Difference, and Total No. of Terms: ");

    if (fscanf(stdin, "%lf%lf%d", &first_term, &cd, &terms) != 3) {
        fprintf(stderr, RED "error: Bad input.\n" NOCOLOR);
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "o==============o=============================o\n"
                    "| Nth Term     | Value                       |\n"
                    "o==============o=============================o\n");

    long double sum = 0.0;

    for (int i = 1; i <= terms; i++) {
        double g_term = 1.0 / ((first_term + (i - 1) * cd));
        fprintf(stdout, "| %-12d | %-27.4lf |\n", i, g_term);

        sum += g_term;
    }
    // Calculating the sum of the H.P.

    fprintf(stdout, "o==============o=============================o\n");
    fprintf(stdout, "| Total Sum    | %-27.6Lf |\n", sum);
    fprintf(stdout, "o============================================o\n\n");
}

/*
 * Display the available options.
 */
void display_options(void) {
    Sequence input = 0;

rewind:
    fprintf(stdout, "  [1] Arithmetic Progression\n"
                    "  [2] Geometric Progression\n"
                    "  [3] Harmonic Progression\n\n"
                    "Please choose an option: ");

    if (fscanf(stdin, "%u", &input) != 1) {
        fprintf(stderr, RED "\nerror: Value incorrectly entered.\n" NOCOLOR);
        flush_stdin();

        getchar();
        display_banner();

        // Best demand for a goto statement is here.
        goto rewind;
    }

    fputc('\n', stdout);

    // Based on the provided input, actions are chosen.
    switch (input) {
        case ARITHMETIC: arithmetic_sequence(); break;
        case GEOMETRIC:  geometric_sequence();  break;
        case HARMONIC:   harmonic_sequence();   break;
        default:
            fprintf(stderr,
                    RED "error: Only <1> <2> <3> are valid inputs.\n" NOCOLOR);
            flush_stdin();

            getchar();
            display_banner();

            goto rewind;
            break;
    }
}

int main(void) {
    char request;

    do {
        display_banner();
        display_options();

        fprintf(stdout, "Do you wish to start over? (Y/N) ");

        if (fscanf(stdin, " %c", &request) != 1) {
            fprintf(stderr, RED "error: Bad input.\n" NOCOLOR);
            return EXIT_FAILURE;
        }
        flush_stdin();
    } while (request == 'y' || request == 'Y');

    fprintf(stdout, GREEN "\n == THANK YOU FOR TESTING M.S.G.! ==\n\n" NOCOLOR);

    return EXIT_SUCCESS;
}
