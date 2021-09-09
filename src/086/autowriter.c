/*
 * autowriter.c: Program that creates and writes its copy and executes it. While
 * execution, the same process is done recursively.
 * Not a funny program.
 *
 * Author: Rohan Bari
 * Date:   2021-09-08, 2021-09-09
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define COUNTER_FILE_NAME "counter.dat"
#define SRC_BUFFER_SIZE   8192
#define BUFFER_SIZE       64

/*
 * Initialize/obtain information for the counter file.
 */
int init_counter(const char *file) {
    FILE *fp = fopen(file, "r");
    int number = 0;

    // If the file does not exist, create one with the value of 0.
    if (!fp) {
        // Change the file access-mode to write.
        fp = fopen(file, "w");

        fprintf(stdout, "info: The file does not exist. Created one.\n");
        fprintf(fp, "%d", number);

        goto exit_body;
    }

    // Change the file access-mode to read again.
    fp = fopen(file, "r");

    // Safe verification of the data format.
    if (fscanf(fp, "%d", &number) != 1) {
        fprintf(stderr, "error: The counter file has been corrupted.\n");
        exit(EXIT_FAILURE);
    }

    // Change the file access-mode to write.
    fp = fopen(file, "w");

    fprintf(fp, "%d", ++number);

exit_body:
    fclose(fp);
    return number;
}

int main(void) {
    int counter_value = init_counter(COUNTER_FILE_NAME);
    char program_file[BUFFER_SIZE];
    char source[SRC_BUFFER_SIZE];
    char command[BUFFER_SIZE];
    char value[BUFFER_SIZE];

    fprintf(stdout, "Execution from Program [%d]\n", counter_value);
    sprintf(value, "%d", counter_value);

    // Constructs the char-array as fileN.c, where N >= 0.
    strcat(program_file, "file");
    strcat(program_file, value);
    strcat(program_file, ".c");

    strcat(command, "gcc -std=gnu99 -g ");
    strcat(command, program_file);
    strcat(command, " && ./a.out");

    FILE *fp = fopen("autowriter.c", "r");

    char line[BUFFER_SIZE * 4];
    while (fgets(line, sizeof line * 4, fp) != NULL)
        strcat(source, line);

    fp = fopen(program_file, "w");
    fprintf(fp, "%s", source);

    // Executes the command: gcc -std=gnu99 -g fileN.c; ./a.out
    // TODO: Bugfix required here.
    if (system(command) != EXIT_SUCCESS) {
        fprintf(stderr, "The system() function failed to execute.\n"
                        "Additional information: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
