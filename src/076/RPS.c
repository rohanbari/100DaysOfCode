/*
 * RPS.c: The Rock-Paper-Scissors Game.
 *
 * @author rohanbari
 * @date   2021-08-26
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROUNDS  3
#define MAX_MATCHES 5

#define GAME_WIN  1
#define GAME_LOSE 0
#define GAME_DRAW 9


#define NOCOLOR  "\033[0m"
#define RED      "\033[1;31m"
#define GREEN    "\033[1;32m"
#define YELLOW   "\033[1;33m"
#define BLUE     "\033[1;34m"

const char options[] = {'r', 'p', 's'};

struct Pair {
    int user;
    int computer;
};

struct Score {
    int games_played;
    int games_won;
    int round;
};

/*
 * Display the game's banner on the screen.
 */
void display_banner(void) {
    const char *banner =
        "o==========================================================o\n" \
        "| THE ROCK-PAPER-SCISSORS GAME                  v1.0-alpha |\n" \
        "o==========================================================o\n" \
        "| The Rock Paper Scissors is a hand game which is commonly |\n" \
        "| played between two people, in which each forms one of    |\n" \
        "| three shapes with an outstretched hand simultaneously.   |\n" \
        "| These shapes are the Rock, Paper, and Scissors.          |\n" \
        "|                                                          |\n" \
        "| There are 5 matches in each round. You must win at least |\n" \
        "| three of them to qualify for the next round. If you win  |\n" \
        "| all the rounds, then you win the game!                   |\n" \
        "|                                                          |\n" \
        "| TEST YOURSELF AND SEE HOW LUCKY YOU ARE. GOOD LUCK!      |\n" \
        "|----------------------------------------------------------|\n" \
        "|         This program is created and maintained by        |\n" \
        "|             Rohan Bari (rohanbari4@gmail.com)            |\n" \
        "o==========================================================o\n";
    if (system("@cls||clear") != EXIT_SUCCESS) {
        fprintf(stderr, RED "%s: Failed to clear screen.\n" NOCOLOR, __func__);
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, BLUE "%s\n" NOCOLOR, banner);
}

/*
 * Display the score on the screen.
 */
void display_score(const struct Score score) {
    fprintf(stdout,
        GREEN "               [Round %d of %d] [Match %d of %d]\n\n" NOCOLOR,
        score.round + 1, MAX_ROUNDS, score.games_played + 1, MAX_MATCHES);
}

/*
 * Discard all the trailing newlines in the buffer.
 */
void discard_newlines(void) {
    int n;
    while ((n = getchar()) != '\n' && n != EOF)
        ;
}

/*
 * Calculate the result of the game.
 */
int game_result(int user, int computer) {
    if (user == computer)
        return GAME_DRAW;

    if (user == 'r' && computer == 'p')
        return GAME_LOSE;
    else if (user == 'p' && computer == 'r')
        return GAME_WIN;
    
    if (user == 'r' && computer == 's')
        return GAME_WIN;
    else if (user == 's' && computer == 'r')
        return GAME_LOSE;

    if (user == 'p' && computer == 's')
        return GAME_LOSE;
    else if (user == 's' && computer == 'p')
        return GAME_WIN;

    return GAME_LOSE;
}

/*
 * Instructs the manner in which the game is to be played.
 */
void run_game(void) {
    struct Pair pair;
    struct Score score = {0, 0, 0};

    while (score.round < MAX_ROUNDS) {
        while (score.games_played < MAX_MATCHES) {
            display_banner();
            display_score(score);

            pair.computer = options[rand() % 3];
            fprintf(stdout, "(R)ock (P)aper or (S)cissors: ");

            if (fscanf(stdin, "%lc", &pair.user) != 1) {
                fprintf(stderr, RED "%s: Invalid input." NOCOLOR, __func__);
                exit(EXIT_FAILURE);
            }
            discard_newlines();

            int result = game_result(pair.user, pair.computer);

            if (result == GAME_WIN) {
                fprintf(stdout, GREEN "You won the match!\n" NOCOLOR);
                score.games_won++;
            } else if (result == GAME_LOSE) {
                fprintf(stdout, RED "You lost the match.\n" NOCOLOR);
            } else {
                fprintf(stdout, YELLOW "The game was a draw.\n" NOCOLOR);
                getchar();
                continue;
            }
//            fprintf(stdout, "The computer chose %s.\n",);
            getchar();

            if (score.games_played == (MAX_ROUNDS - 1) && score.games_won > 2) {
                score.games_won = 0;
                score.games_played = 0;
                score.round++;
                break;
            }
            score.games_played++;
        }
    }
}

int main(void) {
    // Generating new seed for unique sequences of pseudo-random integers.
    srand(time(NULL));
    run_game();

    fprintf(stdout, YELLOW "\n== THANK YOU FOR PLAYING THE GAME! ==\n\n");
    
    return EXIT_SUCCESS;
}
