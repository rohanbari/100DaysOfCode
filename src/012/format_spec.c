/**
 * @file format_spec.c
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief A program that demonstrate the extraction of variable dynamically
 * until the the input format is mismatched from the user input.
 * @version 0.1
 * @date 2021-02-12
 * 
 * @copyright Copyright (c) 2021 Rohan Bari
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 128

// Struct to be extracted
typedef struct {
    char name[MAX_LEN];
    int hr;
    int min;
} location;

int main(void) {
    // Allocating the memory to initialize for the first iteration later
    location *loc = (void *)malloc(sizeof(location) * 2);
    int count = 0;

    // fscanf() returns the number of correctly passed arguments
    while (fscanf(stdin, "The time in %s is %d:%d\n", loc[count].name,
                  &loc[count].hr, &loc[count].min) == 3)
        // Reallocating the memory, i.e. the usage of dynamic memory
        // re-allocation feature
        loc = (void *)realloc(loc, sizeof(loc) * ++count);

    // Displaying the contents
    for (int i = 0; i < count; i++)
        fprintf(stdout, "%s | %02d : %02d\n", loc[i].name, loc[i].hr,
                loc[i].min);

    return 0;
}