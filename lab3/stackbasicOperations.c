#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Function to initialize the stack
void create() {
    top = -1;
    printf("Stack created successfully.\n");
}

// Push operation
void push(int value) {
    if (top >= MAX - 1)
        printf("Stack Overflow!\n");
    else {
        stack[++top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

// Pop operation
int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        int val = stack[top--];
        printf("Popped %d from the stack.\n", val);
        return val;
    }
}

// Peek operation
int peek() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return -1;
    } else {
        printf("Top element is %d\n", stack[top]);
        return stack[top];
    }
}

// Display operation
void display() {
    if (top == -1)
        printf("Stack is empty.\n");
    else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

// Main menu
int main() {
    int choice, value;
    printf("Stack Operations Menu\n");

    do {
        printf("\n1. Create Stack\n2. Push\n3. Pop\n4. Peek\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 3:
                pop();
                break;
            case 4:
                peek();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}