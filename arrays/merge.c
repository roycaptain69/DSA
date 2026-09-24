#include <stdio.h>

// Function matching your merge(arr, low, mid, high)
void merge(int arr[], int low, int mid, int high) {
    int temp[100];           // temp[] array from your notes
    int left = low;          // left = low;
    int right = mid + 1;     // right = mid + 1;
    int k = 0;               // index for temp[] array

    // while (left <= mid && right <= high)
    while (left <= mid && right <= high) {
        // if (arr[left] <= arr[right])
        if (arr[left] <= arr[right]) {
            temp[k] = arr[left];  // temp.add(arr[left]);
            left++;               // left++;
            k++;
        } else {
            temp[k] = arr[right]; // temp.add(arr[right]);
            right++;              // right++;
            k++;
        }
    }

    // If any elements remain in left half:
    while (left <= mid) {
        temp[k] = arr[left];
        left++;
        k++;
    }

    // If any elements remain in right half:
    while (right <= high) {
        temp[k] = arr[right];
        right++;
        k++;
    }

    // for (i = low -> high) { arr[i] = temp[i - low]; }
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

// Function matching your mergeSort(arr, low, high)
void mergeSort(int arr[], int low, int high) {
    // if (low >= high) return; (base condition)
    if (low >= high) {
        return;
    }

    // Step 2: mid = (low + high) / 2;
    int mid = (low + high) / 2;

    // Step 4: mergeSort(arr, low, mid);
    mergeSort(arr, low, mid);

    // Step 5: mergeSort(arr, mid + 1, high);
    mergeSort(arr, mid + 1, high);

    // Step 6: merge(arr, low, mid, high);
    merge(arr, low, mid, high);
}

// Helper function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Array from your notebook dry run: 3, 1, 2, 4, 1, 5, 2, 6, 4
    int arr[] = {3, 1, 2, 4, 1, 5, 2, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    printArray(arr, n);

    // Call mergeSort with low = 0, high = n - 1
    mergeSort(arr, 0, n - 1);

    printf("\nSorted Array:\n");
    printArray(arr, n);

    return 0;
}