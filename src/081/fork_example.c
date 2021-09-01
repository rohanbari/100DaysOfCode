/*
 * fork_example.c: This program deals with the creation of parent and child
 * processes using the fork() POSIX standard function.
 *
 * Author: Rohan Bari
 * Date:   2021-09-01
 */

#include <stdio.h>
#include <unistd.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main(int argc, char **argv) {
    int p_id = fork();

    if (p_id > EXIT_SUCCESS)
        fprintf(stdout, "Parent process creation successful.\n");
    else if (p_id == EXIT_SUCCESS)
        fprintf(stdout, "Child process creation successful.\n");
    else {
        fprintf(stderr, "Parent/child process creation failed.\n");
    }

    return EXIT_SUCCESS;
}
