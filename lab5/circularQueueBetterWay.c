#include <stdio.h>
#define MAX 4

int circularQueue[MAX];
int front = -1;
int rear = -1;

// Enqueue: Insert element
void enqueue(int num) {
    // Check for overflow: next rear would overwrite front
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow\n");
        return;
    }

    // First insertion
    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX; 
        //this is working such that rear max go till max so if we divide smthg from smthg and 
        // take remainder it goes max till the number 1 less than that, like if it got reached to that
        //  number it automatically get back to 0
    }

    circularQueue[rear] = num;
    printf("Inserted %d\n", num);
}

// Dequeue: Remove front element
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    int val = circularQueue[front];
    printf("Dequeued element: %d\n", val);

    // Last element removed
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Display: Show all elements
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue contents: ");
    int i = front;
    while (1) {
        printf("%d ", circularQueue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Peek: Show front element
void peek() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Peek element: %d\n", circularQueue[front]);
    }
}

// Main menu
int main() {
    int choice, value;
    printf("Circular Queue Operations Menu\n");

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}