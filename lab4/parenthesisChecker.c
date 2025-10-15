#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Creating a Stack 
void create(){
    top = -1;
    printf("[INFO] Stack created.\n");
}

// Push operation
void push(int value) {
    if (top >= MAX - 1)
        printf("Stack Overflow!\n");
    else {
        stack[++top] = value;
        printf("[ACTION] Pushed %c onto the stack.\n", value);
    }
}

// Pop operation
int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        int val = stack[top--];
        printf("[ACTION] Popped %c from the stack.\n", val);
        return val;
    }
}

// Peek operation
int peek() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return -1;
    } else {
        printf("[INFO] Top element is %d\n", stack[top]);
        return stack[top];
    }
}

// Display operation
void display() {
    if (top == -1)
        printf("Stack is empty.\n");
    else {
        printf("[STACK CONTENTS]\n");
        for (int i = top; i >= 0; i--)
            printf("  %d\n", stack[i]);
    }
}

// Function to check for balanced parentheses
int isBalanced(char exp[]) {
    create();
    printf("[PROCESS] Checking expression: %s\n", exp);
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            printf("[SCAN] Found opening bracket: %c\n", exp[i]);
            push(exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            printf("[SCAN] Found closing bracket: %c\n", exp[i]);
            if (top == -1)
                return 0;
            char popped = pop();
            if ((exp[i] == ')' && popped != '(') ||
                (exp[i] == '}' && popped != '{') ||
                (exp[i] == ']' && popped != '[')) {
                printf("[ERROR] Mismatch: expected match for %c, got %c\n", exp[i], popped);
                return 0;
            }
        }
    }
    if (top == -1)
        printf("[RESULT] Expression is balanced.\n");
    else
        printf("[ERROR] Unmatched opening brackets remain.\n");
    return top == -1;
}

int main() {
    char exp[MAX];
    printf("=====================================\n");
    printf("   Parentheses Balance Checker\n");
    printf("=====================================\n");
    printf("Enter an expression: ");
    scanf("%s", exp);

    printf("\n-------------------------------------\n");
    if (isBalanced(exp))
        printf("[FINAL RESULT] The expression is balanced.\n");
    else
        printf("[FINAL RESULT] The expression is not balanced.\n");
    printf("-------------------------------------\n");

    return 0;
}