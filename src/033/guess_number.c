/**
 * @file guess_number.c
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief This program is a game of guessing numbers. You need to guess the
 * right hidden number - this is continued until the correct number is found.
 *
 * @version 0.1
 * @date 2021-03-05
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

  srand(time(NULL));

  fprintf(stdout, "Enter the ranges <X> <Y>: ");

  if (fscanf(stdin, "%d %d", &rangeX, &rangeY) != 2) {
    fprintf(stdout, "error: Please input the range correctly.\n");
    return EXIT_FAILURE;
  }

  do {
    random_num = (rand() % rangeY) + rangeX;

    if (fscanf(stdin, "%d", &guess_input) != 1) {
      fprintf(stdout, "error: Input must be a valid integer.\n");
      return EXIT_FAILURE;
    }

    if (random_num == guess_input)
      fprintf(stdout, "Congrats! You guessed the number.\n");
    else if (random_num > guess_input)
      fprintf(stdout, "hint: The number is greater than you guessed.\n");
    else if (random_num < guess_input)
      fprintf(stdout, "hint: The number is lesser than you guessed.\n");
    else
      break;

    fprintf(stdout, "Wanna try again? (Y/N) ");

    if ((input = getchar()) == NULL) {
      fprintf(stderr, "error: Input must be valid.\n");
      return EXIT_FAILURE;
    }
  } while (input == 'Y' && input == 'y');

  return EXIT_SUCCESS;
}
