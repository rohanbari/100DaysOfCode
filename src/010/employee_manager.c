/**
 * @file employee_manager.c
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief This is an application intended to demonstrate several practical
 * usages of file operations - especially in business-related programs. Assuming
 * an environment where a lot of employees are currently working and they all
 * need to be registered in the system.
 *
 * @version 0.1
 * @date 2021-02-10
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 256
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

// The default structure of the database
typedef struct {
    char full_name[MAX_LENGTH - 128];
    char address[MAX_LENGTH];
    int age;
    char gender;
    double salary;
} employee;

/*
 * @brief This subroutine will display an extended version of help messsage.
 */
void display_help(const char *arg) {
    fprintf(stdout,
            "Usage: %s [option] [file]\n\n"
            "OPTIONS:\n"
            "  --help        View this help message\n"
            "  --build-db    Construct a new database\n"
            "  --add         Add a new entry to the database\n"
            "  --list        View all the entries\n"
            "  --delete      Delete the specified database\n\n"
            "NOTES:  1. Option abbvrs. available, e.g. -b, -a, -s, -l, -d\n"
            "        2. A new database need to be created with '-b'.\n",
            arg);
}

int main(int argc, char *argv[]) {
    FILE *fp = NULL;
    int mode = 0;
    employee em;

    if (argc == 2 &&
        (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)) {

        display_help(argv[0]);
        return EXIT_SUCCESS;
    }

    if (argc != 3) {
        fprintf(stderr,
                "Usage: %s [option] [file]\n"
                "Try '--help' or '-h' to get extended help.\n",
                argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "--build-db") == 0 || strcmp(argv[1], "-b") == 0)
        mode = 0;
    else if (strcmp(argv[1], "--add") == 0 || strcmp(argv[1], "-a") == 0)
        mode = 1;
    else if (strcmp(argv[1], "--list") == 0 || strcmp(argv[1], "-l") == 0)
        mode = 2;
    else if (strcmp(argv[1], "--delete") == 0 || strcmp(argv[1], "-d") == 0)
        mode = 3;
    else {
        fprintf(stderr, "[error] Invalid argument '%s'.\n", argv[1]);
        return EXIT_FAILURE;
    }

    if (mode > 0) {
        fp = fopen(argv[2], "r");

        if (fp == NULL) {
            fprintf(stderr,
                    "[error] The database does not exist.\n"
                    "Use the command '--build-db' or '-b' to create one.\n");
            return EXIT_FAILURE;
        }
    }

    switch (mode) {
        // Database creation
        case 0: {
            fp = fopen(argv[2], "r");

            if (fp != NULL) {
                fprintf(
                    stdout,
                    "[warn] The same file already exists. Override? (Y/n) ");
                int c = getchar();
                int ch_clear_buffer;

                while ((ch_clear_buffer = getchar()) != '\n' &&
                       ch_clear_buffer != EOF)
                    ;

                if (c != 'Y' && c != 'y') {
                    fprintf(stdout, "[info] Database creation aborted.\n");
                    return EXIT_SUCCESS;
                }
            }

            fp = fopen(argv[2], "w");
            fprintf(stdout, "[info] Database creation was successful.\n");

            break;
        }
        // Adds an entry
        case 1: {
            fp = fopen(argv[2], "a");

            fprintf(stdout, "Employee Name:  ");
            if (fgets(em.full_name, sizeof(em.full_name), stdin) == NULL) {
                fprintf(stderr, "[error] Please provide the name correctly!\n");
                return EXIT_FAILURE;
            }

            // Removing the trailing newline character
            em.full_name[strlen(em.full_name) - 1] = 0;

            fprintf(stdout, "Enter their address:  ");
            if (fgets(em.address, sizeof(em.address), stdin) == NULL) {
                fprintf(stderr, "[error] Address is non-acceptable.\n");
                return EXIT_FAILURE;
            }

            // Removing the trailing ...
            em.address[strlen(em.address) - 1] = 0;

            fprintf(stdout, "Enter their age:  ");
            if (fscanf(stdin, "%d", &em.age) != 1) {
                fprintf(stderr, "[error] Age is improperly entered.\n");
                return EXIT_FAILURE;
            }

            fprintf(stdout, "Enter their gender - [m]ale | [f]emale:  ");
            if (fscanf(stdin, " %c", &em.gender) != 1) {
                fprintf(stderr, "[error] Gender was incorrectly entered.\n");
                return EXIT_FAILURE;
            }

            switch (em.gender) {
                case 'm':
                case 'M':
                case 'f':
                case 'F':
                    break;
                default: {
                    fprintf(stderr, "[error] Gender must be F or M.\n");
                    return EXIT_FAILURE;

                    break;
                }
            }

            fprintf(stdout, "Enter the employee's salary:  ");

            if (fscanf(stdin, "%lf", &em.salary) != 1) {
                fprintf(stderr, "[error] Salary was improperly entered.\n");
                return EXIT_FAILURE;
            }

            fprintf(fp, "Name: %s, Addr: %s, Age: %d, Gender: %c, Sal: %.2lf\n",
                    em.full_name, em.address, em.age, em.gender, em.salary);

            fprintf(stdout, "[success] Data insertion complete.\n");

            break;
        }
        // Display the entries
        case 2: {
            int c;
            fp = fopen(argv[2], "r");

            while ((c = fgetc(fp)) != EOF)
                putchar(c);
            fprintf(stdout, "[info] All the entries are now on the screen.\n");

            break;
        }
        // Delete the database
        case 3: {
            fp = fopen(argv[2], "r");

            if (!fp) {
                perror(argv[2]);
                return EXIT_FAILURE;
            }

            if (remove(argv[2]) != 0) {
                perror(argv[2]);
                return EXIT_FAILURE;
            }

            return EXIT_SUCCESS; // Must not reach fclose() or this will hit a
                                 // segfault and exit unexpectedly
            break;
        }
        default: {
            break;
        }
    }

    // Closing the file stream
    fclose(fp);

    return EXIT_SUCCESS;
}
