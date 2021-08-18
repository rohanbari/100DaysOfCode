/*
 * macalloc.c: This program compares the implementation of calloc() and malloc()
 * functions that are slightly different from each other, and are widely used in
 * dynamic memory allocation.
 *
 * @author rohanbari
 * @date   2021-08-18
 */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#define REQ_ELEMS 16

/*
 * Display the array collection.
 */
void display_coll(int *data, const int len) {
    for (int idx = 0; idx < REQ_ELEMS; idx++) {
        fprintf(stdout, "%d ", data[idx]);
    }
    fputc('\n', stdout);
}

/*
 * This subroutine represents malloc()'s implementation.
 */
void malloc_example(void) {
    int *ptr = (int *)malloc(sizeof(int) * REQ_ELEMS);

    if (ptr == NULL) {
        fprintf(stderr, "%s(): Error while allocating memory.\n", __func__);
        exit(EXIT_FAILURE);
    }

    display_coll(ptr, REQ_ELEMS);
}

/*
 * This subroutine represents calloc()'s implementation.
 */
void calloc_example(void) {
    // Total size after evaluation is: REQ_ELEMS * sizeof(double)
    // Note that the sizeof() of various primitive types are different depending
    // upon the architecture and the processor.
    int *ptr = calloc(REQ_ELEMS, sizeof(int));

    if (ptr == NULL) {
        fprintf(stderr, "%s(): Error while allocating memory.\n", __func__);
        exit(EXIT_FAILURE);
    }

    display_coll(ptr, REQ_ELEMS);
}

int main(void) {
    malloc_example();
    calloc_example();

    return EXIT_SUCCESS;
}
