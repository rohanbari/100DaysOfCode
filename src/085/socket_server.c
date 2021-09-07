/*
 * socket_server.c: The server program for the Socket application.
 * REQUIRES LINUX ENVIRONMENT.
 *
 * Author: Rohan Bari
 * Date:   2021-09-06
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define INFINITE 1
#define PORT 5000
#define SLEEP_TIME 1

const char *MESSAGE = "Welcome to the Linux server!\n";

int main(void) {
    // File descriptor to initialize the socket.
    int listenfd = 0;
    int connfd = 0;
    struct sockaddr_in serv_addr;
    char sendBuff[BUFFER_SIZE];

    // Initializing the socket descriptor.
    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    fprintf(stdout, "Socket successfully received.\n"
        "Hit <Ctrl>+<C> to terminate the process.\n");

    // Filling each room with Zero-ASCII code character.
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(sendBuff, '0', sizeof(sendBuff));

    // Necessary configurations regarding the server address.
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);

    bind(listenfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

    if (listen(listenfd, 10) == EOF) {
        perror("listen");
        return EXIT_FAILURE;
    }

    while (INFINITE) {
        // Accept the awaiting request.
        connfd = accept(listenfd, (struct sockaddr *)NULL, NULL);

        strcpy(sendBuff, MESSAGE);
        if (strlen(sendBuff) != write(connfd, sendBuff, strlen(sendBuff))) {
            fprintf(stderr, "warn: Buffer byte data lost.\n");
        }

        close(connfd);
        sleep(SLEEP_TIME);
    }

    return EXIT_SUCCESS;
}
