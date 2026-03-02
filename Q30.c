#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, i;
    scanf("%d", &n);

    struct Node *head = NULL, *tail = NULL;

    for (i = 0; i < n; i++) {
        int c, e;
        scanf("%d %d", &c, &e);

        struct Node* temp = createNode(c, e);

        if (head == NULL) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    struct Node* curr = head;

    while (curr != NULL) {
        printf("%d", curr->coeff);

        if (curr->exp > 0) {
            printf("x");
            if (curr->exp > 1) {
                printf("^%d", curr->exp);
            }
        }

        if (curr->next != NULL) {
            printf(" + ");
        }

        curr = curr->next;
    }

    return 0;
}
