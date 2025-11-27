#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Helper Functions (Static for internal use) ---

/**
 * @brief Merges two sorted sub-arrays into a single sorted array.
 *
 * It uses the 'temp' array as an auxiliary buffer to hold the merged elements
 * before copying the result back to the 'arr' array.
 *
 * @param arr The main array of doubles.
 * @param temp The auxiliary array used for merging.
 * @param left The starting index of the first sub-array.
 * @param mid The ending index of the first sub-array.
 * @param right The ending index of the second sub-array.
 */
static void merge(double arr[], double temp[], int left, int mid, int right) {
    int i = left;      // Index for the first sub-array (arr[left..mid])
    int j = mid + 1;   // Index for the second sub-array (arr[mid+1..right])
    int k = left;      // Index for the temporary array (temp[left..right])

    // Copy the smaller element from either sub-array to the temporary array
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // Copy the remaining elements of the first sub-array, if any
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy the remaining elements of the second sub-array, if any
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy the sorted elements from the temporary array back to the original array
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

/**
 * @brief The recursive function to implement Merge Sort.
 *
 * Divides the array segment into two halves, recursively sorts them,
 * and then merges the sorted halves.
 *
 * @param arr The array of doubles to be sorted.
 * @param temp The auxiliary array (passed down through recursion).
 * @param left The starting index of the segment.
 * @param right The ending index of the segment.
 */
static void merge_sort_recursive(double arr[], double temp[], int left, int right) {
    if (left < right) {
        // Calculate the middle point to divide the array into two halves
        int mid = left + (right - left) / 2;

        // Recursively sort the first and second halves
        merge_sort_recursive(arr, temp, left, mid);
        merge_sort_recursive(arr, temp, mid + 1, right);

        // Merge the two sorted halves
        merge(arr, temp, left, mid, right);
    }
}

// --- Required Function ---

/**
 * @brief Sorts the source array using Merge Sort and writes the result to the destination array.
 *
 * This function handles the initial copy and the necessary memory allocation
 * for the auxiliary array required by Merge Sort.
 *
 * @param dest A pointer to the destination array of doubles.
 * @param src A constant pointer to the source array of doubles.
 * @param length The number of elements in the arrays.
 */
void merge_sort_doubles(double *dest, const double *src, int length) {
    if (length <= 0 || dest == NULL || src == NULL) {
        return;
    }

    // 1. Copy the source array to the destination array.
    memcpy(dest, src, length * sizeof(double));

    // 2. Allocate the auxiliary (temporary) array for merging.
    double *temp = (double *)malloc(length * sizeof(double));
    if (temp == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for Merge Sort temporary buffer. Cannot sort.\n");
        return;
    }

    // 3. Perform the recursive Merge Sort on the destination array.
    merge_sort_recursive(dest, temp, 0, length - 1);

    // 4. Free the dynamically allocated auxiliary array.
    free(temp);
}

// --- Utility and Demonstration ---

/**
 * @brief Utility function to print an array of doubles.
 */
static void print_array(const char* label, const double arr[], int size) {
    printf("%s: [", label);
    for (int i = 0; i < size; i++) {
        printf("%.2f%s", arr[i], (i == size - 1) ? "" : ", ");
    }
    printf("]\n");
}

int main() {
    // 1. Define the source array (unsorted data)
    double source_array[] = {9.7, 3.1, 4.2, 8.5, 1.9, 7.3, 2.6, 5.8, 6.4};
    int length = sizeof(source_array) / sizeof(source_array[0]);

    // 2. Define the destination array
    double destination_array[length];

    printf("--- Merge Sort Demonstration (Guaranteed O(N log N)) ---\n");
    print_array("Source Array (Unsorted)", source_array, length);

    // 3. Call the merge sort function
    merge_sort_doubles(destination_array, source_array, length);

    // 4. Print the result
    print_array("Destination Array (Sorted)", destination_array, length);

    // Demonstration with duplicate elements (tests stability)
    double source_duplicates[] = {5.5, 2.2, 8.8, 2.2, 5.5};
    int len_dup = sizeof(source_duplicates) / sizeof(source_duplicates[0]);
    double dest_dup[len_dup];

    printf("\n--- Test with duplicates (demonstrating stability) ---\n");
    print_array("Source Array", source_duplicates, len_dup);
    merge_sort_doubles(dest_dup, source_duplicates, len_dup);
    print_array("Destination Array (Sorted)", dest_dup, len_dup);

    return 0;
}
