#include <stdio.h>

#define MAX 50

// Global variables so functions can modify them without pointers
int a[MAX];
int size = 0;

void display() {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void insertElement() {
    if (size >= MAX) {
        printf("Error: Array Overflow!\n");
        return;
    }

    int pos, num;
    printf("Enter position to insert (1 to %d): ", size + 1);
    scanf("%d", &pos);

    if (pos < 1 || pos > size + 1) {
        printf("Invalid position!\n");
        return;
    }

    printf("Enter the element to insert: ");
    scanf("%d", &num);

    // Shift elements right
    for (int i = size - 1; i >= pos - 1; i--) {
        a[i + 1] = a[i];
    }

    a[pos - 1] = num;
    size++;

    printf("Inserted %d at position %d.\n", num, pos);
}

void deleteElement() {
    if (size <= 0) {
        printf("Error: Array Underflow!\n");
        return;
    }

    int pos;
    printf("Enter position to delete (1 to %d): ", size);
    scanf("%d", &pos);

    if (pos < 1 || pos > size) {
        printf("Invalid position!\n");
        return;
    }

    int deleted = a[pos - 1];

    // Shift elements left
    for (int i = pos - 1; i < size - 1; i++) {
        a[i] = a[i + 1];
    }

    size--;

    printf("Deleted %d from position %d.\n", deleted, pos);
}

int main() {
    // 1. Initial array input
    printf("Enter initial size of array: ");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }

    printf("\nInitial Array:\n");
    display();

    // 2. Perform Insertion
    printf("\n--- Insertion ---\n");
    insertElement();
    display();

    // 3. Perform Deletion
    printf("\n--- Deletion ---\n");
    deleteElement();
    display();

    return 0;
}