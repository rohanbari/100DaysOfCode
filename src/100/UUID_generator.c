/*
 * UUID_generator.c: A program to generate Universally Unique Identifiers using
 *                   UUID's library (powered by Ubuntu Developers.)
 *
 *                   This program should be compiled with '-luuid' flag.
 *
 * Author: Rohan Bari
 * Date:   2021-09-23
 */

#include <uuid/uuid.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_UUID_SIZE 36

int main(void) {
    uuid_t binuuid;
    char *uuid = (char *)malloc(MAX_UUID_SIZE + 1); // +1 for a null-terminator.

    // Generates the binary UUID, yet it is to be unparsed.
    uuid_generate_random(binuuid);

    // Unparsing the UUID to be read in plain text.
    uuid_unparse(binuuid, uuid);

    fprintf(stdout, "%s\n", uuid);

    return EXIT_SUCCESS;
}
