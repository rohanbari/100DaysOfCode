/*
 * quicksort.c: Implementation of the QuickSort sorting algorithm.
 *
 * CASE COMPLEXITIES:
 *   - best case: O(n * log(n))
 *   - average case: T(n * log(n))
 *   - worst case: O(n^2)
 * SPACE COMPLEXITY: O(log(n))
 *
 * @author rohanbari
 * @date   2021-08-22
 */

#include <stdio.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

/*
 * Display the containing values of an array on the screen.
 */
void display_coll(const int *seq, const int size) {
    for (int idx = 0; idx < size; idx++) {
        fprintf(stdout, "%d ", *(seq + idx));
    }
    fputc('\n', stdout);
}

/*
 * Swap between two integer (as pointers.)
 */
void swap(int *a, int *b) {
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}

/*
 * Evaluate the partition of a given problem.
 */
int partition_of(int *data, int lower, int upper) {
    // Assuming the pivot value to be the right-most one.
    int pivot_val = data[upper];
    // Pointing to the greater element.
    int ip = lower - 1;

    for (int it = lower; it < upper; it++) {
        if (data[it] <= pivot_val) {
            // Increment by one, since the element smaller than the pivot value
            // is found and instantly swapped.
            ip++;
            // Swapping between two integers.
            swap(&data[ip], &data[it]);
        }
    }

    // To swap the pivot element by the greater element.
    swap(&data[ip + 1], &data[upper]);
    // Returning the partition point.
    return (ip + 1);
}

/*
 * The QuickSort algorithm.
 */
void quick_sort(int *data, int lower, int upper) {
    if (lower < upper) {
        int part = partition_of(data, lower, upper);

        quick_sort(data, lower, part - 1); // Left to the pivot.
        quick_sort(data, part + 1, upper); // Right to the pivot.
    }
}

int main(void) {
    int sequence[] = {4, 7, 8, 1, 2};
    size_t len = sizeof(sequence) / sizeof(sequence[0]);

    fprintf(stdout, "Unsorted collection: ");
    display_coll(sequence, len);

    quick_sort(sequence, 0, len - 1);

    fprintf(stdout, "After sort: ");
    display_coll(sequence, len);

    return EXIT_SUCCESS;
}
