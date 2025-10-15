#include <stdio.h>
#include <string.h>
#define MAX 100

int stack[MAX];
int top = -1;

//Create 
void create(){
    top = -1;
    printf("[INFO] Stack created successfully!!\n");
}

// Push operation
void push(int value) {
    if (top >= MAX - 1)
        printf("Stack Overflow!\n");
    else {
        stack[++top] = value;
        printf("[ACTION] Pushed %d onto the stack.\n", value);
    }
}

// Pop operation
int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        int val = stack[top--];
        printf("[ACTION] Popped %d from the stack.\n", val);
        return val;
    }
}

//evaluating expression
int evalution(char str[]) {
    printf("\n[PROCESS] Evaluating prefix expression: %s\n", str);
    create();
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*') {
            printf("[SCAN] Found operator '%c'\n", str[i]);
            int element1 = pop();
            int element2 = pop();
            int output;
            switch (str[i]) {
                case '+': output = element1 + element2; break;
                case '-': output = element1 - element2; break;
                case '*': output = element1 * element2; break;
                case '/': output = element1 / element2; break;
            }
            printf("[COMPUTE] %d %c %d = %d\n", element1, str[i], element2, output);
            push(output);
        } else if (str[i] >= '0' && str[i] <= '9') {
            int operand = str[i] - '0';
            printf("[SCAN] Found operand '%c' pushing %d\n", str[i], operand);
            push(operand);
        }
    }
    int result = pop();
    printf("[RESULT] Final evaluated result: %d\n", result);
    return result;
}

int main(){
    char exp[MAX];
    printf("=====================================\n");
    printf("   Prefix Expression Evaluator\n");
    printf("=====================================\n");
    printf("Enter an expression: ");
    scanf("%s", exp);

    int final_answer = evalution(exp);
    printf("\n[FINAL OUTPUT] Evaluated answer of this expression is: %d\n", final_answer);
    return 0;
}