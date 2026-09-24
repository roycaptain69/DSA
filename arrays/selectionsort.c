#include <stdio.h>

// Helper function to print array elements
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Selection sort function with pass-by-pass printing
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;

    // Outer loop: moves the boundary of the unsorted subarray
    for (i = 0; i < n - 1; i++) {
        // Assume the first element of unsorted portion is the minimum
        min_idx = i;

        // Inner loop: find the index of the actual minimum element
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; // Update index of minimum element
            }
        }

        // SWAPPING: Swap the found minimum element with arr[i]
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;

        // Display array status after every pass
        printf("After Pass %d: ", i + 1);
        printArray(arr, n);
    }
}

int main() {
    // Array of 8 students' marks taken directly from your question paper
    int marks[] = {64, 23, 87, 12, 45, 31, 76, 18};
    int n = sizeof(marks) / sizeof(marks[0]);

    printf("Original Array:\n");
    printArray(marks, n);
    printf("\n");

    selectionSort(marks, n);

    printf("\n");
    printf("Final Sorted Array:\n");
    printArray(marks, n);

    return 0;
}