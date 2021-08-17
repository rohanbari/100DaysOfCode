/*
 * pthread_struct.c: This exercise program demonstrate the passage of a data
 * structure (as multiple arguments) into pthread_create in a single parameter.
 * All the safety measures are taken while coding the instructions.
 *
 * NOTE: The program must be compiled using '-pthread' compiler flag.
 *
 * @author rohanbari
 * @date 2021-08-17
 */

#include <stdio.h>   // fprintf
#include <pthread.h> // pthread_create, pthread_join, pthread_exit
#include <errno.h>   // errno
#include <string.h>  // strerror

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define MAX_THREADS 8

/*
 * Data structure to pass multiple arguments into pthread_create().
 */
struct data {
    int thread_id;
    int number;
};

/*
 * Display the contents of the data structure.
 */
void *display_data(void *args) {
    // Explicit type-casting from (void *) to (struct data *).
    struct data *recv = (struct data *)args;

    fprintf(stdout, "%s(): thread id %2d contains %2d.\n",
        __func__, recv->thread_id, recv->number);
    pthread_exit(NULL);
}

int main(void) {
    pthread_t thread[MAX_THREADS];
    struct data storage[MAX_THREADS];

    for (int idx = 0; idx < MAX_THREADS; idx++) {
        // Initializing the struct member variables.
        storage[idx].thread_id = idx;
        storage[idx].number = idx * 10;

        // pthread_create() returns any non-zero number indicating that the
        // function has not exited successfully.
        if (pthread_create(&thread[idx], NULL, display_data, &storage[idx])) {
            fprintf(stderr, "pthread_create exited with status %d.", errno);
            fprintf(stderr, "Description: %s\n", strerror(errno));

            return EXIT_FAILURE;
        }
    }

    for (int idx = 0; idx < MAX_THREADS; idx++) {
        // Waiting for each specified thread to terminate.
        if (pthread_join(thread[idx], NULL)) {
            fprintf(stderr, "pthread_join: Failed to join threads.\n");
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}
