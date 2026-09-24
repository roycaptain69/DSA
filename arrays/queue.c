#include <stdio.h>

#define MAX 5  // Maximum capacity of the ticket line

int queue[MAX];
int front = -1;
int rear = -1;

// 1. Add Customer (Enqueue)
void addCustomer(int customer) {
    // Check if the ticket line is full
    if (rear == MAX - 1) {
        printf("Housefull! Cannot add customer %d\n", customer);
        return;
    }

    // If queue is initially empty
    if (front == -1) {
        front = 0;
    }

    rear++;
    queue[rear] = customer;
    printf("Customer %d added to queue.\n", customer);
}

// 2. Serve Customer (Dequeue)
void serveCustomer() {
    // Check if the queue is empty
    if (front == -1 || front > rear) {
        printf("No customers in queue to serve!\n");
        return;
    }

    int served = queue[front];
    printf("Served ticket to Customer %d\n", served);
    front++;

    // Reset queue pointers if all customers have been served
    if (front > rear) {
        front = -1;
        rear = -1;
    }
}

// 3. Check / Show Housefull
void showHousefull() {
    if (rear == MAX - 1) {
        printf("Status: Housefull! (Queue is at maximum capacity of %d)\n", MAX);
    } else {
        printf("Status: Seats available. Current queue length: %d\n", (front == -1) ? 0 : (rear - front + 1));
    }
}

// 4. Display all customers currently in line
void display() {
    if (front == -1 || front > rear) {
        printf("No customers in queue.\n");
        return;
    }

    printf("Customers currently in queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    // Simulating ticket counter operations
    printf("--- Cinema Ticket Counter Simulation ---\n\n");

    // Adding customers
    addCustomer(101);
    addCustomer(102);
    addCustomer(103);
    addCustomer(104);
    addCustomer(105);

    // Trying to add another customer when line is full
    addCustomer(106); // Triggers Housefull message

    showHousefull();
    display();

    printf("\n--- Serving Customers ---\n");
    serveCustomer(); // Serves 101 (FIFO)
    serveCustomer(); // Serves 102

    display();

    return 0;
}