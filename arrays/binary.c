#include <stdio.h>

// Method 1: Iterative Binary Search (Most common for practical exams)
int binarySearchIterative(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        // Prevents integer overflow compared to (low + high) / 2
        int mid = low + (high - low) / 2;

        // Check if target is at mid
        if (arr[mid] == target) {
            return mid; // Return index where target is found
        }
        // If target is smaller, look in the left half
        else if (target < arr[mid]) {
            high = mid - 1;
        }
        // If target is larger, look in the right half
        else {
            low = mid + 1;
        }
    }

    return -1; // Target not found
}

// Method 2: Recursive Binary Search
int binarySearchRecursive(int arr[], int low, int high, int target) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        if (target < arr[mid]) {
            return binarySearchRecursive(arr, low, mid - 1, target);
        }
        return binarySearchRecursive(arr, mid + 1, high, target);
    }

    return -1; // Target not found
}

int main() {
    // Binary search REQUIRES the array to be sorted
    int arr[] = {12, 23, 34, 45, 56, 67, 78, 89, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n----------------------------------------\n");

    // Test Case 1: Existing element
    int target1 = 56;
    int result1 = binarySearchIterative(arr, n, target1);
    if (result1 != -1) {
        printf("Element %d found at index %d\n", target1, result1);
    } else {
        printf("Element %d not found in array\n", target1);
    }

    // Test Case 2: Non-existing element
    int target2 = 99;
    int result2 = binarySearchIterative(arr, n, target2);
    if (result2 != -1) {
        printf("Element %d found at index %d\n", target2, result2);
    } else {
        printf("Element %d not found in array\n", target2);
    }

    return 0;
}