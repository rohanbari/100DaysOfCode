/*
 * self_source.c: Read the source file of itself after program compilation.
 *
 * Author: Rohan Bari
 * Date:   2021-09-18
 */

#include <stdio.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define BUFFER_SIZE  512

int main(void) {
    char line_buffer[BUFFER_SIZE];
    // With the help of __FILE__ macro, which points to the source file and
    // fopen() function, we can read the source file, even after compilation.
    FILE *fp = fopen(__FILE__, "r");

    // Validate whether the file was opened or not.
    if (!fp) {
        fprintf(stderr, "error: Failed to open the source file.\n");
        return EXIT_FAILURE;
    }

    // Read each line and store temporarily into line_buffer.
    while (fgets(line_buffer, sizeof line_buffer, fp) != NULL)
        fprintf(stdout, "%s", line_buffer);

    return EXIT_SUCCESS;
}
