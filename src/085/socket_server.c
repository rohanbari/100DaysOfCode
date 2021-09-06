/*
 * socket_server.c: The server-side program of Socket application demonstration.
 * This program is still under development and available only in Alpha channel.
 *
 * Author: Rohan Bari
 * Date:   2021-09-06
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define PORT        8080

const char *message = "Welcome to the Linux server!";

int main(void) {
    char buffer[BUFFER_SIZE];

    int server_fd;
    int new_sock;
    int value;

    int opt = 1;

    struct sockaddr_in address;

    // Construction of the socket file descriptor.
    if (!(server_fd = socket(AF_INET, SOCK_STREAM, 0))) {
        perror("socket server_fd");
        return EXIT_FAILURE;
    }

    // Attaching the socket to the PORT.
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | \
        SO_REUSEPORT, &opt, sizeof opt)) {
        perror("setsockopt");
        return EXIT_FAILURE;
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    return EXIT_SUCCESS;
}
