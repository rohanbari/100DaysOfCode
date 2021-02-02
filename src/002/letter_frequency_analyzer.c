/**
 * @file letter_frequency_analyzer.c
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief A program that measures the frequency of each alphabetic letter
 * and display on the screen with its overall usage percentage.
 * @version 0.1
 * @date 2021-02-02
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX_LEN 512
#define ALPHABETS 26
#define EXIT_FAILURE 1

int main() {
    char string[MAX_LEN];       // To get user input string
    int count[ALPHABETS] = {0}; // To keep the data organized alphabetically
    int len = 0;                // To measure the length of the string

    fprintf(stdout, "Enter a string: ");

    // Input verification, note that fgets() returns 's'c on success
    if (fgets(string, MAX_LEN, stdin) == NULL) {
        fprintf(stdout, "Oops, something's wrong.\n");
        return EXIT_FAILURE;
    }

    while (string[len++]) // Count 'len' till it reaches NULL terminator seq.
        ;

    string[len - 1] = 0; // Overriding the generated newline with NULL term.

    int ct = 0;

    // Verifying if each input is an alphabetical letter
    do
        if ((string[ct] <= 'A' && string[ct] >= 'Z') ||
            (string[ct] <= 'a' && string[ct] >= 'z')) {
            fprintf(stdout, "The string must contain only alphabet chars.\n");
            return EXIT_FAILURE;
        }
    while (string[ct++]);

    ct = 0;

    // If the string contains capital A-Z, then convert it to lowercase

    do
        if (string[ct] >= 'A' && string[ct] <= 'Z')
            string[ct] += ALPHABETS + 6; // = +32
    while (string[ct++]);

    ct = 0;

    // equivalent to string[ct] != '\0'
    while (string[ct]) {
        // If the 'ct'th element of 'string' is larger than 97 but lesser than
        // 122, then get the char to count its frequency later
        if (string[ct] == ' ')
            memmove(&string[ct], &string[ct + 1], len - ct);

        if (string[ct] >= 'a' && string[ct] <= 'z') {
            int temp = string[ct] - 'a';
            count[temp]++;
        }
        ct++;
    }

    len = 0;
    while (string[len++]);
    len -= 2; // Removing excessive invalid lengths

    fprintf(stdout, "=== String length (no spaces): %d ===\n", len);

    // Calculation process of each alphabet letter's usage
    for (ct = 0; ct < ALPHABETS; ct++) {
        int letter = ct + 'a';
        // (len - 1) -> To truncate NULL terminator count as a string char
        double freq_per = (double)count[ct] / len * 100.00;

        // Format: letter ==> ___ times (___ %)
        printf("%c ==> %3d times (%6.2lf %%)\n", letter, count[ct], freq_per);
    }

    return 0;
}