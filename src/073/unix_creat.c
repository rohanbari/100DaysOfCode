/*
 * unix_creat.c: This program shows the implementation of creat() function. It
 * also manifests how to assign multiple file permissions simultaneously by
 * using the bitwise-OR operator.
 *
 * @author rohanbari
 * @date   2021-08-23
 */

#include <stdio.h>  // fprintf
#include <stdlib.h> // exit, EXIT_SUCCESS, EXIT_FAILURE
#include <string.h> // strerror
#include <fcntl.h>  // creat
#include <errno.h>  // errno

#define REQ_ARGS 2

/*
 * Validate the no. of arguments passed.
 */
void validate_args(const int argc, const char *p_name) {
    if (argc != REQ_ARGS) {
        fprintf(stderr, "Usage: %s <filename>\n", p_name);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv) {
    const char *file_name = argv[1];
    int file_descriptor;

    validate_args(argc, argv[0]);
    file_descriptor = creat(file_name, O_RDWR | O_CREAT);

    if (file_descriptor != -EXIT_FAILURE) {
        fprintf(stdout, "File creation successful.\n");
    } else {
        fprintf(stderr, "File creation unsuccessful!\n"
                        "Description: %s\n", strerror(errno));
    }

    return EXIT_SUCCESS;
}
