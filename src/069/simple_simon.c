/*
 * simple_simon.c: A game program where the user has to memorize a randomly
 * generated sequence of numbers within a limited time. The numbers are then
 * disappeared as soon as it reaches the time limit. After that, the user has
 * to recall the sequence and write exactly as it was. When the entered sequence
 * is matched, the game continues with one more term in the sequence, otherwise,
 * the game is lost.
 *
 * @author rohanbari
 * @date   2021-08-18
 */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

#define USER_RESP_MIN_LEN 256

/*
 * Generate seed for a new sequence of pseudo-random integers.
 */
void generate_random_seed(void) {
    srand(time(NULL));
}

/*
 * Initialize the sequence up to a given length.
 */
char *init_sequence(char *seq, int len) {
    long long number = 0;
    char buffer[USER_RESP_MIN_LEN];

    for (int i = 0; i < len; i++) {
        number += 10 * (long long)(rand() % 9);
    }

    sprintf(buffer, "%lld", number);
    fprintf(stdout, "%lld\n", number);

/*
    if (snprintf(seq, len + 1, "%lld", number) != (len + 1)) {
        fprintf(stderr, "error: Integer to string conversion failed.\n");
        exit(EXIT_FAILURE);
    } */

    return buffer;
}

int main(void) {
    int peak_score = 1;
    char *seq = (char *)malloc(peak_score);
    char *user_resp = (char *)malloc(peak_score + USER_RESP_MIN_LEN);

    generate_random_seed();

    for (; ;) {
        seq = realloc(seq, sizeof(char) * peak_score);
        seq = init_sequence(seq, peak_score);

        fprintf(stdout, "%s\n", seq);

        sleep(peak_score);
        system("clear");

        fprintf(stdout, "Write the sequence: ");

        // Data assignment verification.
        if (fgets(user_resp, peak_score + USER_RESP_MIN_LEN, stdin) == NULL) {
            fprintf(stderr, "error: Invalid input format.\n");
            exit(EXIT_FAILURE);
        }
        // Replacement of the newline with null-terminator.
        *(user_resp + strlen(user_resp) - 1) = 0;

        if (!strcmp(user_resp, seq)) {
            continue;
        } else {
            fprintf(stdout, "control: Sorry, but you are eliminated.\n");
            break;
        }

        // Increment score when the answer is correct.
        peak_score++;
    }

    fprintf(stdout, "Thank you for playing the Simple Simon game!\n");

    return EXIT_SUCCESS;
}
