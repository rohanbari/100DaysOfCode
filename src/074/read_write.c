/*
 * write_read.c: This program demonstrates how to use write() and read(), which
 * are the core functions of POSIX standards.
 *
 * @author rohanbari
 * @date   2021-08-24
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define REQ_ARGS   2
#define MAX_LENGTH 1024

/*
 * Validate the number of passed arguments.
 */
void validate_args(const int argc, const char *p_name) {
    if (argc != REQ_ARGS) {
        fprintf(stderr, "Usage: %s <filename>", p_name);
        exit(EXIT_FAILURE);
    }
}

/*
 * Validate whether the file exists or not. If not, create one.
 */
void locate_file(int *fd, const char *name) {
    *fd = open(name, O_RDWR);

    if (*fd != -EXIT_FAILURE) {
        return;
    }

    perror("open");
    *fd = creat(name, O_RDWR | O_CREAT);

    if (*fd != -EXIT_FAILURE) {
        fprintf(stdout, "File creation successful.\n");
    } else {
        fprintf(stderr, "Sorry, the file creation was unsuccessful.\n"
                        "Description: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    if (close(*fd) != EXIT_SUCCESS) {
        fprintf(stderr, "error: File closure failure.\n");
        exit(EXIT_FAILURE);
    }
}

/*
 * Write variable number of bytes to the file.
 */
void write_into(int *fd) {
    char buffer[MAX_LENGTH];

    fprintf(stdout, "Enter data to insert...\n");

    if (fgets(buffer, sizeof buffer, stdin) == NULL) {
        fprintf(stderr, "error: Data was inappropriately given.\n");
        exit(EXIT_FAILURE);
    }
    buffer[strlen(buffer) - 1] = 0;

    if (write(*fd, buffer, strlen(buffer)) == -EXIT_FAILURE) {
        fprintf(stderr, "File write failure.\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv) {
    int file_descriptor;
    char *buffer = (char *)calloc(MAX_LENGTH, sizeof(char));
    ssize_t file_content_size = 0;

    validate_args(argc, argv[0]);
    locate_file(&file_descriptor, argv[1]);

    file_descriptor = open(argv[1], O_RDWR);
    write_into(&file_descriptor);

    file_content_size = read(file_descriptor, buffer, MAX_LENGTH);
    buffer[MAX_LENGTH - 1] = 0;

    fprintf(stdout, "%s\n", buffer);
    fprintf(stdout, "%lu bytes written.\n", file_content_size);

    close(file_descriptor);

    return EXIT_SUCCESS;
}
