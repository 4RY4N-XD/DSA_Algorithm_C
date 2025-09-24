#include <stdio.h>
#include <string.h>
#define MAX 100

int stack[MAX];
int top = -1;

//Create 
void create(){
    top = -1;
    printf("Stack created successfully!!\n");
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

//evaluating expression
int evalution(char str[]) {
    create();
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*') {
            int element1 = pop();
            int element2 = pop();
            int output;
            switch (str[i]) {
                case '+': output = element1 + element2; break;
                case '-': output = element1 - element2; break;
                case '*': output = element1 * element2; break;
                case '/': output = element1 / element2; break;
            }
            push(output);
        } else if (str[i] >= '0' && str[i] <= '9') {
            push(str[i] - '0');
        }
    }
    return pop();
}


int main(){
    char exp[MAX];
    printf("Enter an expression: ");
    scanf("%s", exp);

    int final_answer = evalution(exp);
    printf("Evaluated answer of this expression is: %d", final_answer);
    return 0;
}