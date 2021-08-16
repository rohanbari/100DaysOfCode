/*
 * safemount.c: Mount filesystems in r-w-x permission without the need of the
 * superuser privileges. Any mounted filesystem(s) may be unmounted using a
 * non-sudo 'umount' command.
 *
 * @author rohanbari
 * @date 2021-08-16
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CMD_MAX_LENGTH 256

#ifdef __unix__
    #define IS_LINUX 1
#endif

#ifdef _WIN32
    #define IS_LINUX 0
#endif

/*
 * Validate whether the running operating system is Linux or not.
 */
void validate_os(short int id) {
    if (id == 0) {
        fprintf(stdout, "This program is only built for Linux systems.\n");
        exit(EXIT_SUCCESS);
    }
}

/*
 * Check if the passed arguments are sufficient.
 */
void validate_args(int argc, const char *p_name) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <device>\n", p_name);
        exit(EXIT_FAILURE);
    }
}

/*
 * Execute the filesystem mount command.
 */
void execute_command(char *fs) {
    char cmd[CMD_MAX_LENGTH] = "udisksctl mount -b ";
    strcat(cmd, fs);

    short int ret_code = system(cmd);

    switch (ret_code) {
        case 0:
            fprintf(stdout, "Use the command to unmount: umount %s\n", fs);
            break;
        case -1:
            fprintf(stderr, "error: Child process could not be created.\n");
            exit(EXIT_FAILURE);
            break;
        case 127:
            fprintf(stderr, "error: Shell execution failure.\n");
            exit(EXIT_FAILURE);
            break;
        default:
            break;
    }
}

int main(int argc, char **argv) {
    validate_os(IS_LINUX);
    validate_args(argc, argv[0]);

    execute_command(argv[1]);

    return EXIT_SUCCESS;
}
