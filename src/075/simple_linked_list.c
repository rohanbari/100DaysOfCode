/*
 * simple_linked_list.c: This is my very first attempt in learning and under-
 * standing the linked lists. In this program, a basic dynamic linked list is
 * constructed.
 *
 * @author rohanbari
 * @date   2021-08-25
 */

#include <stdio.h>
#include <stdlib.h>

// Change this to resize the size of the dynamic linked-list.
#define MAX_INSTANCES 5

/*
 * Structural definition of an elementary node.
 */
struct Node {
    int value;
    struct Node *next;
};

/*
 * Display the value containing in the linked-list on the screen.
 */
void display_list(struct Node *list) {
    while (list != NULL) {
        fprintf(stdout, "%d ", list->value);
        // Pointing to the next address.
        list = list->next;
    }
    fputc('\n', stdout);
}

int main(void) {
    struct Node *head;
    struct Node *instance[MAX_INSTANCES];

    // Memory allocation.
    for (int i = 0; i < MAX_INSTANCES; i++) {
        instance[i] = malloc(sizeof(struct Node));
    }

    for (int i = 0; i < MAX_INSTANCES; i++) {
        instance[i]->value = (i + 1) * 10;

        // When the iteration is the last one, it should be pointing to NULL.
        if (i == (MAX_INSTANCES - 1)) {
            instance[MAX_INSTANCES - 1]->next = NULL;
            break;
        }
        // Otherwise, the next instance's address is pointed.
        instance[i]->next = instance[i + 1];
    }

    // Assigning the head with the pointed address of 'instance1'.
    head = instance[0];
    // Display the list on the screen.
    display_list(head);

    return EXIT_SUCCESS;
}
