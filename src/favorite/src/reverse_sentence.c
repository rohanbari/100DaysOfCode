/*
 * reverse_sentence.c: A program to reverse the words of a given sentence.
 *
 * Author: Rohan Bari
 * Date:   2021-09-01
 */

#include <stdio.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define REQ_ARGS   2
#define MAX_LENGTH 4096
 
/*
 * Reverses the sequence of the passed word.
 */
void reverse(char* begin, char* end) {
    char temp;

    while (begin < end) {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

/*
 * Obtain the length of the string.
 */
size_t get_strlen(const char *p) {
    const char *start = p;
    while(*p) p++;

    return (size_t) (p - start);
}

/*
 * Concatenate two strings with its destination of length N.
 */
void concat(char *dest, const char *src, size_t n) {
    size_t dest_len = get_strlen(dest);
    size_t i = 0;

    for (; i < n && src[i]; i++)
        dest[dest_len + i] = src[i];

    dest[dest_len + i] = 0;
}
 
/*
 * Reverses the sequence of words of the passed string.
 */
void reverse_words(char* str) {
    char* word_begin = str; // Points to the beginning of the word
    char* temp = str;       // Temporary string to point to the word boundary
 
    // Iterate until temp++ expression reaches NULL.
    while (*temp) {
        temp++;

        if (*temp == '\0')
            reverse(word_begin, temp - 1);
        else if (*temp == ' ') {
            reverse(word_begin, temp - 1);
            word_begin = temp + 1;
        }
    }
 
    // Reverse the entire string
    reverse(str, temp - 1);
}
 
// Driver Code
int main(int argc, char *argv[]) {
    // This string is capable to store 4 KB of data in the stack.
    char buffer[MAX_LENGTH];

    // Examining the number of arguments.
    if (argc < REQ_ARGS) {
        fprintf(stderr, "Usage: %s <sentence>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Concatenating the arguments (words) into a single string.
    for (int i = 1; i < argc; i++) {
        concat(buffer, argv[i], sizeof argv[i]);
        concat(buffer, " ", sizeof " ");
    }

    // Reversing the word sequence (by pointer, pass by reference).
    reverse_words(buffer);

    fprintf(stdout, "%s\n", buffer);

    return EXIT_SUCCESS;
}
