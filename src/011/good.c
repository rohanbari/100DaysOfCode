/**
 * @file good.c
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief This application is intended to personify the behavior of Linux
 * terminals, such as talking to the Linux and receiving its replies.
 *
 * @note Rename the output to 'good', paste it to /usr/bin to make the command
 * line more human-readable and realistic - like a talking Linux.
 *
 * @version 0.1
 * @date 2021-02-11
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRLEN 128
#define SQ_SUB_ARR 4

/**
 * @brief Subroutine to provide a helping guide for this program.
 *
 * @param arg The name of the executable
 */
void display_help(const char *arg) {
    fprintf(stdout,
            "Usage: %s [option]\n\n"
            "OPTIONS:\n"
            "  morning    Pick a morning time message\n"
            "  afternoon  Pick a noon time message\n"
            "  evening    Pick an evening time message\n"
            "  night      Pick a goodnight message\n\n",
            arg);
}

int main(int argc, char *argv[]) {
    // 4x4 collection of strings
    char messages[SQ_SUB_ARR][SQ_SUB_ARR][MAX_STRLEN] = {
        {"Good Morning!", "Hey there, welcome back!",
         "Voila! Did you sleep well?", "Hope your day goes fine..."},

        {"Good Afternoon!", "Hey! I'm good, how about you?",
         "Good to see you back!", "Eaten a lot... did you had a lunch?"},

        {"Good Evening!", "How was your day?", "Cheers! Let's get back to work",
         "Wow! I'm seeing the sunset..."},

        {"Good Night!", "Sweet dreams!", "Hope you sleep well.",
         "Thanks! You too, my friend!"}};
    int mode = 0;

    // Verification of arguments
    if (argc != 2) {
        fprintf(stdout,
                "Usage: %s [option]\n"
                "Try '--help' or '-h' to get extended information.\n",
                argv[0]);
        return EXIT_FAILURE;
    }

    if ((strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)) {
        // If the argument '--help' was provided, then display help
        display_help(argv[0]);
        return EXIT_SUCCESS;
    }

    // Generating a unique seed for pseudo-randomness
    srand(time(NULL));
    short int rand_code = rand() % SQ_SUB_ARR;

    // Setting different modes, later used for accessing the sub-arrays
    // to access randomly chosen strings from the sub-array
    if (strcmp(argv[1], "morning") == 0) {
        mode = 0;
    } else if (strcmp(argv[1], "afternoon") == 0) {
        mode = 1;
    } else if (strcmp(argv[1], "evening") == 0) {
        mode = 2;
    } else if (strcmp(argv[1], "night") == 0) {
        mode = 3;
    } else {
        fprintf(stderr, "Sad Linux: I don't recognize '%s' arg.\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Lastly displaying the string
    fprintf(stdout, "Linux: %s\n", messages[mode][rand_code]);

    return 0;
}