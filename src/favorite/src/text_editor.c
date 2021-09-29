/**
 * @file text_editor.c
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief This is a simple program to describe the logic behind developing an
 * efficient text-based text-editor.
 * @version 0.1
 * @date 2021-02-09
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1048576 // 1 MB text maximally could be inserted
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main(int argc, char *argv[]) {
    int is_help_req = 0;

    // In case only a single argument '--help' or '-h' is passed
    if (argc == 2 &&
        (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0))
        is_help_req = 1;

    if (argc != 3 && !is_help_req) {
        fprintf(stderr,
                "Usage: %s [option] [file_name]\n"
                "Use '-h' or '--help' to get extended help.\n",
                argv[0]);
        return EXIT_FAILURE;
    }

    char input[MAX_LENGTH] = {0};
    short int mode = 0;
    FILE *fp = NULL;

    // Setting different modes based on different conditions
    if (strcmp(argv[1], "--create") == 0 || strcmp(argv[1], "-c") == 0)
        mode = 1;
    else if (strcmp(argv[1], "--append") == 0 || strcmp(argv[1], "-a") == 0)
        mode = 2;
    else if (strcmp(argv[1], "--delete") == 0 || strcmp(argv[1], "-d") == 0)
        mode = 3;
    else if (strcmp(argv[1], "--read") == 0 || strcmp(argv[1], "-r") == 0)
        mode = 4;
    else if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)
        ;
    else {
        fprintf(stderr, "[error] Unrecognized command '%s'.\n", argv[1]);
        return EXIT_FAILURE;
    }

    switch (mode) {
        // Help
        case 0: {
            fprintf(stdout,
                    "Usage: %s [option] [file_name]\n\n"
                    "OPTIONS:\n"
                    "  --help      Prints this help message\n"
                    "  --create    Create a new file, ask override if exists\n"
                    "  --read      Read an existing file\n"
                    "  --append    Insert text to an existing file\n"
                    "  --delete    Delete an existing file\n\n"
                    "NOTE:  1. Use Ctrl+D to stop writing to a file.\n"
                    "       2. Short commands are supported too, e.g. -c, -r\n",
                    argv[0]);
            return EXIT_SUCCESS;
            break; // Never executable statement
        }

        // File Creation
        case 1: {
            fp = fopen(argv[2], "r");
            int ch_clear_buffer;

            if (fp == NULL)
                fprintf(stdout, "[info] File did not exist. Created.\n");
            else {
                fprintf(stdout, "[ask] File already exists. Override? (Y/n) ");
                char c = getchar();

                while ((ch_clear_buffer = getchar()) != '\n' &&
                       ch_clear_buffer != EOF)
                    ;

                if (c != 'y' && c != 'Y') {
                    fprintf(stdout, "[info] File write aborted.\n");
                    return EXIT_SUCCESS;
                }
            }

            fp = fopen(argv[2], "w");

            while (fgets(input, sizeof(input), stdin) != NULL)
                fprintf(fp, "%s", input);

            fprintf(stdout, "[success] Data write successful.\n");

            break;
        }
        // File Append
        case 2: {
            fp = fopen(argv[2], "r");

            if (fp == NULL) {
                perror(argv[2]);
                return EXIT_FAILURE;
            }
            
            // Redefining the file pointer with append mode
            fp = fopen(argv[2], "a");

            while (fgets(input, sizeof(input), stdin) != NULL)
                fprintf(fp, "%s", input);

            fprintf(stdout,
                    "[success] The data has been appended to the file.\n");

            break;
        }
        // File Deletion
        case 3: {
            fp = fopen(argv[2], "r");

            if (remove(argv[2]) == 0)
                fprintf(stdout, "[success] The file was deleted.\n");
            else {
                perror(argv[2]);
                return EXIT_SUCCESS;
            }

            break;
        }
        // File Read
        case 4: {
            fp = fopen(argv[2], "r");

            // Alternative way to verify if a file is existing/granted
            // to read/write its content
            if (!fp) {
                perror(argv[2]);
                return EXIT_FAILURE;
            }

            char c;

            // Reading file till EOF destination
            while ((c = fgetc(fp)) != EOF)
                putchar(c);

            break;
        }
        default: {
            break;
        }
    }

    // Closing the file pointer
    fclose(fp);

    return EXIT_SUCCESS;
}
