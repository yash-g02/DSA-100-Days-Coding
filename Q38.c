#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

int isFull() {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
        return 1;
    return 0;
}

int isEmpty() {
    if (front == -1)
        return 1;
    return 0;
}

void push_front(int x) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    }
    else if (front == 0) {
        front = MAX - 1;
    }
    else {
        front--;
    }

    deque[front] = x;
}

void push_back(int x) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    }
    else if (rear == MAX - 1) {
        rear = 0;
    }
    else {
        rear++;
    }

    deque[rear] = x;
}

void pop_front() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed: %d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    }
    else if (front == MAX - 1) {
        front = 0;
    }
    else {
        front++;
    }
}

void pop_back() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed: %d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    }
    else if (rear == 0) {
        rear = MAX - 1;
    }
    else {
        rear--;
    }
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    int i = front;
    printf("Deque elements: ");

    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {

    push_back(10);
    push_back(20);
    push_front(5);
    push_front(2);

    display();

    pop_front();
    pop_back();

    display();

    return 0;
}
