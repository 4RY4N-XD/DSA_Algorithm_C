#include <stdio.h>
#include <string.h>
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
        printf("[ACTION] Pushed '%c' onto the stack.\n", value);
    }
}

// Pop operation
int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        int val = stack[top--];
        printf("[ACTION] Popped '%c' from the stack.\n", val);
        return val;
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

// Helper to flip any bracket and return default thing as it is
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
    printf("[PROCESS] Reversing and swapping brackets...\n");
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
    printf("[RESULT] After reverse and swap: %s\n", str);
}

// Precedence order of Operator
int precedence(int operator){
    switch (operator) {
        case '/': return 4;
        case '*': return 3;
        case '+': return 2;
        case '-': return 1;
        default: return -1;
    }
}

// Reversed expression to postfix
void postfix(char str[]){
    printf("[PROCESS] Converting to postfix...\n");
    create();
    push('(');
    int index = -1;
    char postfixExp[MAX];
    int len = strlen(str);
    str[len] = ')';
    str[len + 1] = '\0';

    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == '('){
            printf("[SCAN] Found '('\n");
            push(str[i]);
        }
        else if(str[i] == ')'){
            printf("[SCAN] Found ')'\n");
            while (peek() != '(') {
                postfixExp[++index] = pop();
            }
            pop(); // remove '('
        }
        else if(str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*'){
            printf("[SCAN] Found operator '%c'\n", str[i]);
            while (precedence(peek()) >= precedence(str[i])) {
                postfixExp[++index] = pop();
            }
            push(str[i]);
        }
        else {
            printf("[SCAN] Found operand '%c'\n", str[i]);
            postfixExp[++index] = str[i];
        }
    }

    while (peek() != -1 && peek() != '(') {
        postfixExp[++index] = pop();
    }
    postfixExp[++index] = '\0';

    strcpy(str, postfixExp);
    printf("[RESULT] Postfix expression: %s\n", str);
}

int main() {
    char exp[MAX];
    printf("=====================================\n");
    printf("   Infix to Prefix Converter\n");
    printf("=====================================\n");
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