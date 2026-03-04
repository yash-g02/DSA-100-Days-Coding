#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        return;
    }
    stack[++top] = value;
}

void pop() {
    if (top == -1) {
        return;
    }
    top--;
}

int main() {
    int n, m, value;
    int i;   // Declare here (important for C90)

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        pop();
    }

    for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}
