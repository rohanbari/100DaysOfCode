/**
 * @file guess_number.c
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief This program is a game of guessing numbers. You need to guess the
 * right hidden number - this is continued until the correct number is found.
 *
 * @version 0.1
 * @date 2021-03-05
 * 
 * @note Finished on 2021-03-07
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  char input;
  int rangeX, rangeY;
  int random_num;
  int guess_input;
  int chances = 3;

  // Seeding pseudorandomness with a unique time token
  srand(time(NULL));

  fprintf(stdout, "Enter the ranges <X> <Y>: ");

  if (fscanf(stdin, "%d %d", &rangeX, &rangeY) != 2) {
    fprintf(stdout, "error: Please input the range correctly.\n");
    return EXIT_FAILURE;
  }

  do {
    // Generating a random number between rangeX -> rangeY
    random_num = (rand() % rangeY) + rangeX;

    do {
      if (fscanf(stdin, "%d", &guess_input) != 1) {
        fprintf(stdout, "error: Input must be a valid integer.\n");
        return EXIT_FAILURE;
      }

      if (random_num == guess_input) {
        fprintf(stdout, "Congrats! You guessed the number.\n");
        chances = 3;
        break;

      } else if (random_num > guess_input)
        fprintf(stdout, "hint: The number is greater than you guessed.\n");
      else if (random_num < guess_input)
        fprintf(stdout, "hint: The number is lesser than you guessed.\n");
      else
        break;

      chances--;

      // Discarding any possible newline
      int c;
      while ((c = getchar()) != '\n' && c != EOF)
        ;

    } while (random_num != guess_input && chances != 0);

    if (chances == 0) {
      fprintf(stdout, "Sorry, you are out of chances.\n");
      chances = 3;
    }

    fprintf(stdout, "Wanna try again? (Y/N) ");

    if (fscanf(stdin, " %c", &input) != 1) {
      fprintf(stdout, "error: Input must be a valid character.\n");
      return EXIT_FAILURE;
    }
  } while (input == 'Y' || input == 'y');

  return EXIT_SUCCESS;
}
