/*
 * who_todo.c: Enter several names (for example: your friends, colleagues, or
 * relatives, etc.) to decide who is going to do something. It is intended to be
 * a prank program.
 *
 * Author: Rohan Bari
 * Date:   2021-09-02
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define MIN_REQ_ARGS 3

/*
 * Validate the number of passed arguments.
 */
void validate_arguments(const int argc, const char *p_name) {
    if (argc < MIN_REQ_ARGS) {
        fprintf(stderr, "Usage: %s <name1> <name2> ...\n", p_name);
        exit(EXIT_FAILURE);
    }
}

/*
 * Contains script that needs to be executed at the very first.
 */
void initiate(void) {
    srand(time(NULL));
}

/*
 * Execution code.
 */
void begin(const int total, const char **names) {
    const int choice = (int)(rand() % (total - 1));
    const char *name = names[choice + 1];

    fprintf(stdout, "%s is lucky for the work!\n", name);
}

int main(int argc, char **argv) {
    validate_arguments(argc, argv[0]);
    initiate();

    begin(argc, (const char **)argv);

    return EXIT_SUCCESS;
}
