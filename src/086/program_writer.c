/*
 * program_writer.c: Program that writes itself and executes to write it into
 * other new files, then execute it in a recursion.
 *
 * Author: Rohan Bari
 * Date:   2021-09-07
 */

#include <stdio.h>
#include <string.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define PROG_FILE "rewritable.c"

char program[2073] =
    "#include <stdio.h>"     \
    "#include <string.h>"    \
    ""                       \
    "#define EXIT_SUCCESS 0" \
    "#define EXIT_FAILURE 1" \
    ""                       \
    "int main(void) {"       \
    "" \
    "" \
    "" \
    "" \
    "" \
    "" \
    "" \
    "" \
    "" \
    "";

int main(void) {
    FILE *fp = fopen(PROG_FILE, "w+");
    size_t len = strlen(program);

    if (len > fprintf(fp, "%s", program)) {
        fprintf(stderr, "error: The child program file has been damaged.\n");
        return EXIT_FAILURE;
    }

    // Closes the file and also checks if it has been properly closed.
    if (fclose(fp) != EXIT_SUCCESS) {
        fprintf(stderr, "error: File closure failed.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
