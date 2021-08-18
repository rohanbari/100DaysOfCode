#include <stdio.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main(void) {
    int count;
    int sum = 0;

    fprintf(stdout, "Number of digits to be summed up: ");

    if (!fscanf(stdin, "%d", &count)) {
        fprintf(stderr, "error: Please enter the value carefully.\n");
        return EXIT_FAILURE;
    }

    for (int i = 1; i <= count; sum += i++);

    fprintf(stdout, "The accumulation results %d.\n", sum);

    return EXIT_SUCCESS;
}
