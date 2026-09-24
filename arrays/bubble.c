#include <stdio.h>

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble Sort function
void bubbleSort(int arr[], int n) {
    int i, j, temp;

    // Outer loop: tracks the number of passes (from 0 to n - 2)
    for (i = 0; i < n - 1; i++) {

        // Inner loop: compares adjacent elements
        // -1 prevents arr[j + 1] out of bounds
        // -i skips elements already sorted at the end
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swapping arr[j] and arr[j + 1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

        // Print array state after every pass (great for exam evaluation)
        printf("After Pass %d: ", i + 1);
        printArray(arr, n);
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    printArray(arr, n);
    printf("----------------------------------------\n");

    bubbleSort(arr, n);

    printf("----------------------------------------\n");
    printf("Final Sorted Array:\n");
    printArray(arr, n);

    return 0;
}