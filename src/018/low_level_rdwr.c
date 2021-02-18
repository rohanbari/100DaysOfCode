/**
 * @file low_level_rdwr.c
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief This program demonstrate the read/write in and from the fundamental
 * file descriptors attached with the program in a Unix-like system.
 *
 * @note _fd 0, 1 and 2 is equivalent to - stdin, stdout and stderr
 *
 * @version 0.1
 * @date 2021-02-18
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

// stdio.h wasn't required if BUFSIZ was replaced with another macro
#include <stdio.h>
// Defining the UNIX standard syscalls
#include <unistd.h>

int main(void) {
    // The BUFSIZ macro is implementation-defined, in current machine
    // the BUFSIZ expands up to unsigned 8192
    char buf[BUFSIZ];
    int n = 0;

    // If the read() function returns a zero after reading the BUFSIZ number
    // of bytes from the standard input, the loop breaks
    while ((n = read(0, buf, BUFSIZ)) > 0)
        // Till the read is valid, calling write()
        if (write(1, buf, n) != n)
            _exit(1);

    // NOTE: The relation between the performance and the number of system calls
    // is reciprocal. That is, lesser the syscalls, more the performance is.

    return 0;
}
