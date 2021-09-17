/*
 * cpu_usage.c: Get your device's CPU usage percentage.
 *
 * Author: Rohan Bari
 * Date:   2021-09-20
 */

#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>

#ifdef __unix__
    #define FLAG_OK 1
#endif

#define BUFFER_SIZE  1024
#define CPU_FILE     "/proc/loadavg"

typedef double Usage;

/*
 * Validate the Operating System and restrict to Unix systems.
 */
void validate_os(void) {
    if (!FLAG_OK) {
        fprintf(stderr, "This program is meant to be only run in Linux.\n");
        exit(EXIT_FAILURE);
    }
}

/*
 * Get the CPU usage in percentage.
 */
Usage get_cpu_load(void) {
    char buffer[BUFFER_SIZE];
    int file_handler_fd;
    Usage usage;

    file_handler_fd = open(CPU_FILE, O_RDONLY);

    if (file_handler_fd < 0)
        return (Usage)EXIT_FAILURE;

    // Read the target file and store it to the buffer.
    if (read(file_handler_fd, buffer, sizeof buffer - 1) == -1)
        return (Usage)EXIT_FAILURE;

    sscanf(buffer, "%lf", &usage);
    close(file_handler_fd);

    return usage * 100.0;
}

int main(void) {
    Usage usage;

    validate_os();
    usage = get_cpu_load();

    fprintf(stdout, "Current CPU usage percentage: %.2lf\n", usage);

    return EXIT_SUCCESS;
}
