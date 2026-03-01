#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp;

    if (head == NULL) return newNode;

    temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;

    return head;
}

struct Node* rotateRight(struct Node* head, int k) {
    struct Node* curr;
    int len = 1, steps;

    if (!head || !head->next || k == 0) return head;

    curr = head;
    while (curr->next) {
        curr = curr->next;
        len++;
    }

    k = k % len;
    if (k == 0) return head;

    curr->next = head;

    steps = len - k;
    while (steps--) curr = curr->next;

    head = curr->next;
    curr->next = NULL;

    return head;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, k, x, i;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    scanf("%d", &k);

    head = rotateRight(head, k);
    printList(head);

    return 0;
}
