/*
 * caesar.c: The Caesar-cipher cryptographic program.
 *
 * Author: Rohan Bari
 * Date:   2021-09-12
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REQ_ARGS 3

typedef enum {
    ENCRYPT,
    DECRYPT,
    UNKNOWN
} ActionType;

/*
 * Validate the number of passed arguments for main().
 */
void validate_arguments(const int argc, const char *p_name) {
    if (REQ_ARGS != argc) {
        fprintf(stderr, "Usage: %s --<encrypt/decrypt> <plain text>\n", p_name);
        exit(EXIT_FAILURE);
    }
}

/*
 * Validate whether the string contains non-alphabetic characters.
 */
void validate_string(const char *str) {
    // The condition is equivalent to: str[i] != '\0'
    for (int i = 0; str[i]; i++)
        if (str[i] < 'A' || str[i] > 'z') {
            fprintf(stderr, "%s: Only alphabets are supported.\n", __func__);
            exit(EXIT_FAILURE);
        }
}

/*
 * Recognize the valid operations.
 */
ActionType validate_option(const char *type) {
    if (strcmp(type, "--encrypt") == 0 || strcmp(type, "-e") == 0)
        return ENCRYPT;
    else if (strcmp(type, "--decrypt") == 0 || strcmp(type, "-d") == 0)
        return DECRYPT;
    else
        return UNKNOWN;
}

/*
 * The encryption algorithm. (Overrides original data)
 */
void caesar_encrypt(char *plain_text) {
    // Equivalent expression: plain_text[i] != '\0'
    for (int i = 0; plain_text[i]; i++)
        if (plain_text[i] >= 'X' && plain_text[i] <= 'Z')
            plain_text[i] = (char)(plain_text[i] - 23);
        else
            plain_text[i] = (char)(plain_text[i] + 3);
}

/*
 * The decryption algorithm. (Overrides original data)
 */
void caesar_decrypt(char *cipher_text) {
    // Equivalent expression: cipher_text[i] != '\0'
    for (int i = 0; cipher_text[i]; i++)
        if (cipher_text[i] > 65 && cipher_text[i] < 67)
            cipher_text[i] = (char)(cipher_text[i] + 23);
        else
            cipher_text[i] = (char)(cipher_text[i] - 3);
}

int main(int argc, char **argv) {
    ActionType a_type;

    validate_arguments(argc, argv[0]);
    validate_string(argv[2]);
    a_type = validate_option(argv[1]);

    switch (a_type) {
        case ENCRYPT: caesar_encrypt(argv[2]); break;
        case DECRYPT: caesar_decrypt(argv[2]); break;
        case UNKNOWN:
            fprintf(stderr, "error: Unrecognized command '%s'.\n"
                            "Usage: %s --<encrypt/decrypt> <plain text>\n",
                            argv[1], argv[0]);
            return EXIT_FAILURE;
            break;
    }
    fprintf(stdout, "%s\n", argv[2]);

    return EXIT_SUCCESS;
}
