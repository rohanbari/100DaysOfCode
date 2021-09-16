/*
 * popen_cmdline.c: Program to copy the standard output (after the command being
 *                  executed) and stores it in a character array.
 *
 * Author: Rohan Bari
 * Date:   2021-09-17
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

// Boolean definition.
typedef enum {
    false,
    true
} bool;

// Required number of arguments.
#define REQ_ARGS     2
// Maximum allowance to store the character-array data.
#define BUFFER_SIZE  1024
// Output file.
#define OUTPUT_FILE  "cmd_output.dat"

volatile sig_atomic_t flag = false;

void is_interrupted(int sig) {
    flag = true;
}

/*
 * Validate the number of passed arguments.
 */
void validate_args(const int argc, const char *p_name) {
    if (REQ_ARGS > argc) {
        fprintf(stderr, "Usage: %s <command> <command-args>\n", p_name);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv) {
    FILE *fp = NULL;

    char command[BUFFER_SIZE];
    char output[BUFFER_SIZE];

    validate_args(argc, argv[0]);
    // Handling Ctrl+C key-combination interruption signal.
    signal(SIGINT, is_interrupted);

    for (int i = 1; i < argc; i++) {
        strcat(command, argv[i]);
        strcat(command, " ");
    }

    // Pipe-streaming to the process 'command'.
    fp = popen(command, "r");

    if (!fp) {
        fprintf(stderr, "error: Failed to run the command.\n");
        return EXIT_FAILURE;
    }

    // Each line is being assigned to standard input 'output' from 'fp'.
    while (fgets(output, sizeof output, fp) != NULL) {
        fprintf(stdout, "%s", output);

        if (flag) {
            fprintf(stdout, "SIGINT: Forced-exit requested.\n");
            return EXIT_FAILURE;
        }
    }
    
    // Closure of pipe-stream.
    pclose(fp);

    return EXIT_SUCCESS;
}
