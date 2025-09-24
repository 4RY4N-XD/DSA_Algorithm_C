#include <stdio.h>
#include <string.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Creating a Stack 
void create(){
    top = -1;
}

// Push operation
void push(int value) {
    if (top >= MAX - 1)
        printf("Stack Overflow!\n");
    else {
        stack[++top] = value;
    }
}

// Pop operation
int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// Peek operation
int peek() {
    if (top == -1) {
        return -1;
    } else {
        return stack[top];
    }
}

// Helper to flip any bracket
char flip_bracket(char c) {
    switch (c) {
        case '(': return ')';
        case ')': return '(';
        case '{': return '}';
        case '}': return '{';
        case '[': return ']';
        case ']': return '[';
        default:  return c;
    }
}

// Reverse string AND swap all brackets
void reverse_and_swap(char str[]) {
    int start = 0, end = strlen(str) - 1;
    while (start < end) {
        char a = str[start];
        char b = str[end];
        str[start] = flip_bracket(b);
        str[end]   = flip_bracket(a);
        start++;
        end--;
    }
    if (start == end) {
        str[start] = flip_bracket(str[start]);
    }
}

// Precedence order of Operator
int precedence(int operator){
    switch (operator) {
        case '^': return 5;
        case '/': return 4;
        case '*': return 3;
        case '+': return 2;
        case '-': return 1;
        default: return -1;
    }
}

// Reversed expression to postfix
void postfix(char str[]){
    create();
    push('(');
    int index = -1;
    char postfixExp[MAX];
    int len = strlen(str);
    str[len] = ')';
    str[len + 1] = '\0';

    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == '('){
            push(str[i]);
        }
        else if(str[i] == ')'){
            while (peek() != '(') {
                postfixExp[++index] = pop();
            }
            pop(); // remove '('
        }
        else if(str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*' || str[i] == '^'){
            while (precedence(peek()) >= precedence(str[i])) {
                postfixExp[++index] = pop();
            }
            push(str[i]);
        }
        else {
            postfixExp[++index] = str[i];
        }
    }

    while (peek() != -1 && peek() != '(') {
        postfixExp[++index] = pop();
    }
    postfixExp[++index] = '\0';

    strcpy(str, postfixExp);
}

int main() {
    char exp[MAX];
    printf("Enter an expression: ");
    scanf("%s", exp);

    reverse_and_swap(exp);
    printf("Reversed expression: %s\n", exp);

    postfix(exp);
    printf("Postfix expression of reversed expression: %s\n", exp);

    reverse_and_swap(exp);
    printf("Final Prefix expression: %s\n", exp);

    return 0;
}