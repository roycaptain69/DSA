#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Function to add a book by accession number
void push(int acc_no) {
    if (top >= MAX - 1) {
        printf("Stack Overflow! Cannot place book %d\n", acc_no);
        return;
    }
    top++;
    stack[top] = acc_no;
    printf("Pushed book: %d\n", acc_no);
}

// Function to remove a book from the top
int pop() {
    if (top < 0) {
        printf("Stack Underflow! No books to remove.\n");
        return -1;
    }
    int popped = stack[top];
    top--;
    printf("Popped book: %d\n", popped);
    return popped;
}

// Function to view current books in rack (from top to bottom)
void display() {
    if (top < 0) {
        printf("The book rack is empty.\n");
        return;
    }

    printf("\n--- Current Book Rack (Top to Bottom) ---\n");
    for (int i = top; i >= 0; i--) {
        printf("| Book Acc No: %d |\n", stack[i]);
    }
    printf("-----------------------------------------\n");
}

int main() {
    // Operations specified in notebook:
    // PUSH(1), PUSH(2), PUSH(3), PUSH(4), PUSH(5)
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    // POP() - Note: POP takes no parameter; it always removes the top item (5)
    pop();

    // Display final position of the stack
    display();

    return 0;
}