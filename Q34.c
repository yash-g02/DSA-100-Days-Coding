#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }

    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);

    return value;
}

// Check if operator
int isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/');
}

// Evaluate postfix
int evaluatePostfix(char exp[]) {
    int i = 0;

    while (exp[i] != '\0') {

        if (exp[i] == ' ') {
            i++;
            continue;
        }

        // If number
        if (isdigit(exp[i])) {
            int num = 0;

            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            push(num);
        }

        // If operator
        else if (isOperator(exp[i])) {

            int op2 = pop();
            int op1 = pop();
            int result;

            switch(exp[i]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
            }

            push(result);
            i++;
        }
    }

    return pop();
}

int main() {

    char exp[100];

    printf("Enter postfix expression:\n");
    fgets(exp, sizeof(exp), stdin);

    int result = evaluatePostfix(exp);

    printf("%d\n", result);

    return 0;
}
