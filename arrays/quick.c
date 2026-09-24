#include <stdio.h>

// Helper function to swap two array values
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function exactly as structured in your notebook
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // pivot = arr[low]
    int i = low;          // i = low
    int j = high;         // j = high

    while (i < j) {
        // Find first element greater than pivot from left
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        // Find first element smaller than pivot from right
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }

        // If pointers have not crossed, swap elements
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }

    // When i and j cross, swap pivot with arr[j]
    swap(&arr[low], &arr[j]);

    return j; // return j as the partition index
}

// Recursive QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);

        // Recursively sort left and right partitions
        quickSort(arr, low, pIndex - 1);
        quickSort(arr, pIndex + 1, high);
    }
}

// Helper function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Array from your practical question paper: 72, 45, 91, 23, 67, 38, 84, 56
    int arr[] = {72, 45, 91, 23, 67, 38, 84, 56};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("\nSorted Array (Ascending):\n");
    printArray(arr, n);

    return 0;
}