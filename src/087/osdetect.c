/*
 * osdetect.c: Program to detect the type of the OS running.
 *
 * Author: Rohan Bari
 * Date:   2021-09-09
 */

#include <stdio.h>

#define EXIT_SUCCESS 0

#ifdef __unix__
    #define OSTYPE "Linux/Unix-based/BSD Systems"
#endif

#ifdef __APPLE__
    #define OSTYPE "Apple macOS"
#endif

#ifdef __FreeBSD__
    #define OSTYPE "FreeBSD"
#endif

#ifdef __ANDROID__
    #define OSTYPE "Android"
#endif

int main(void) {
    fprintf(stdout, "You are currently running %s.\n", OSTYPE);

    return EXIT_SUCCESS;
}
