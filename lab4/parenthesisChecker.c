#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Creating a Stack 

void create(){
    top = -1;
    // printf("Stack is created");
}

// Push operation
void push(int value) {
    if (top >= MAX - 1)
        printf("Stack Overflow!\n");
    else {
        stack[++top] = value;
        // printf("Pushed %d onto the stack.\n", value);
    }
}

// Pop operation
int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        int val = stack[top--];
        // printf("Popped %d from the stack.\n", val);
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


// Function to check for balanced parentheses
int isBalanced(char exp[]) {
    create();
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1)
                return 0;
            char popped = pop();
            if ((exp[i] == ')' && popped != '(') ||
                (exp[i] == '}' && popped != '{') ||
                (exp[i] == ']' && popped != '['))
                return 0;
        }
    }
    return top == -1;
}

int main() {
    char exp[MAX];
    printf("Enter an expression: ");
    scanf("%s", exp);

    if (isBalanced(exp))
        printf("The expression is balanced.\n");
    else
        printf("The expression is not balanced.\n");

    return 0;
}