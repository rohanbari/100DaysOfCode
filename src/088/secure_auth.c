/*
 * secure_auth.c: An example program to store a sample username and password
 * securely by using Base64 cryptographic algorithm. Credit to <Brad Conte> for
 * his great contribution to this library.
 *
 * Author: Rohan Bari
 * Date:   2021-09-10
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

#include "base64.h"

#define CRED_FILE     "encrypted.dat"
#define BUFFER_SIZE   1024
#define BUFFER_CIPHER 40960

typedef enum {
    REGISTERED,
    UNREGISTERED
} mode;

/*
 * Initialize the database where the credentials are to be stored.
 */
mode init_database(const char *file_name) {
    FILE *fp = fopen(file_name, "r");

    if (!fp) {
        // Changing file access-mode to Write.
        fp = fopen(file_name, "w");
        fprintf(fp, "%s", "");

        fprintf(stdout, "info: New database initialized successfully.\n");
        return UNREGISTERED;
    }
    return REGISTERED;
}

/*
 * Get keypress signals.
 */
int keypress(unsigned char echo) {
    struct termios savedState, newState;
    int c;

    if (-1 == tcgetattr(STDIN_FILENO, &savedState))
        // Error in tcgetattr() function.
        return EOF;

    // The current state should be the saved state.
    newState = savedState;

    if ((echo = !echo))
        // Bit to disable echo.
        echo = ECHO;

    newState.c_lflag &= ~(echo | ICANON);
    newState.c_cc[VMIN] = 1;

    if (-1 == tcsetattr(STDIN_FILENO, TCSANOW, &newState))
        // Error in tcsetattr() function.
        return EOF;

    // Obtain a keypress.
    c = getchar();

    if (-1 == tcsetattr(STDIN_FILENO, TCSANOW, &savedState))
        return EOF;

    return c;
}

/*
 * Mask the password along with obtaining the user input.
 */
void get_password(char *password) {
    int point_to = 0;

    do {
        password[point_to] = keypress(0);
        if (password[point_to] != '\n')
            fputc('*', stdout);
        point_to++;

    } while (password[point_to - 1] != '\n');

    // Newline removal.
    password[point_to - 1] = 0;
    fputc('\n', stdout);
}

/*
 * Get user credentials and securely store them after encoding.
 */
void add_user(const char *file_name) {
    FILE *fp = fopen(file_name, "w");

    char username[BUFFER_SIZE];
    char password[BUFFER_SIZE];
    char plain_text[BUFFER_SIZE * 2];
    char cipher[BUFFER_CIPHER];

    fprintf(stdout, "Select a username: ");

    // Safely accept the username.
    if (fgets(username, sizeof username, stdin) == NULL) {
        fprintf(stderr, "error: The username is incorrectly accepted.\n");
        exit(EXIT_FAILURE);
    }
    // Newline removal.
    username[strlen(username) - 1] = 0;

    fprintf(stdout, "Select a password: ");

    // Mask the password from being displayed.
    get_password(password);

    strcat(plain_text, username);
    strcat(plain_text, "\n");
    strcat(plain_text, password);

    base64_encode((unsigned char *)plain_text,
                    (unsigned char *)cipher, strlen(plain_text), 0);

    fprintf(fp, "%s\n", cipher);
    fprintf(stdout, "info: Registration successful. Please come back soon.\n");

    fclose(fp);
}

/*
 * Asks for login.
 */
void get_user(const char *file_name) {
    FILE *fp = fopen(file_name, "r");

    char cipher[BUFFER_CIPHER];
    char plain_text[BUFFER_SIZE * 2];
    // To separately store username and password.
    char plain_creds[2][BUFFER_SIZE * 2];

    char username[BUFFER_SIZE];
    char password[BUFFER_SIZE];

    if (fscanf(fp, "%s", cipher) != 1) {
        fprintf(stderr, "error: The database file has been corrupted.\n");
        exit(EXIT_FAILURE);
    }

    base64_decode((unsigned char *)cipher, \
                    (unsigned char *)plain_text, strlen(cipher));

    char *str_ptr = strtok(plain_text, "\n");
    int point_to = 0;

    while (str_ptr != NULL) {
        strcat(plain_creds[point_to++], str_ptr);
        str_ptr = strtok(NULL, "\n");
    }

    fprintf(stdout, "Enter username: ");

    // Verification of username's input.
    if (fgets(username, sizeof username, stdin) == NULL) {
        fprintf(stderr, "error: Please provide the username correctly.\n");
        exit(EXIT_FAILURE);
    }
    username[strlen(username) - 1] = 0;

    if (strcmp(username, plain_creds[0]) != 0) {
        fprintf(stdout, "alert: Invalid username.\n");
        exit(EXIT_SUCCESS);
    }

    fprintf(stdout, "Enter password: ");
    get_password(password);

    if (strcmp(password, plain_creds[1]) != 0) {
        fprintf(stdout, "alert: Invalid password.\n");
        exit(EXIT_SUCCESS);
    }

    fprintf(stdout, "ACCESS GRANTED!\n");
}

int main(void) {
    mode user_type = init_database(CRED_FILE);

    if (user_type == UNREGISTERED) {
        add_user(CRED_FILE);
    } else {
        get_user(CRED_FILE);
    }

    return EXIT_SUCCESS;
}
