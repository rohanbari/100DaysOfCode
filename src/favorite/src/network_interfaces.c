/*
 * network_interfaces.c: Display the IP address of your device.
 *
 * @author rohanbari
 * @date   2021-08-28
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LENGTH 256

/*
 * Verify if the hostname of the system is valid.
 */
void examine_hostname(const int host_status) {
    if (host_status == EOF) {
        fprintf(stdout, "%s: %s\n", __func__, strerror(errno));
        exit(EXIT_FAILURE);
    }
}

/*
 * Validates the host information.
 */
void examine_host_by_name(const struct hostent *host_entry) {
    if (host_entry == NULL) {
        fprintf(stdout, "%s: %s\n", __func__, strerror(errno));
        exit(EXIT_FAILURE);
    }
}

/*
 * Validates the char pointed buffer of the IP address.
 */
void examine_IP_buffer(const char *buffer) {
    if (buffer == NULL) {
        fprintf(stdout, "%s: %s\n", __func__, strerror(errno));
        exit(EXIT_FAILURE);
    }
}

int main(void) {
    char buffer[MAX_LENGTH];
    int hostname;
    struct hostent *host_entry;
    char *IP;

    hostname = gethostname(buffer, sizeof buffer);
    examine_hostname(hostname);

    host_entry = gethostbyname(buffer);
    examine_host_by_name(host_entry);

    IP = inet_ntoa(*((struct in_addr*) host_entry->h_addr_list[0]));
    examine_IP_buffer(IP);

    fprintf(stdout, "IP address of the machine is %s\n"
                    "The hostname: %s\n", IP, buffer);

    return EXIT_SUCCESS;
}
