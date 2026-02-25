#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    int n, key, count = 0;
    int i;

    scanf("%d", &n);

    struct Node *head = NULL, *tail = NULL, *temp;

    // Create linked list
    for (i = 0; i < n; i++) {
        temp = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &temp->data);
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    scanf("%d", &key);

    // Count occurrences
    temp = head;
    while (temp != NULL) {
        if (temp->data == key)
            count++;
        temp = temp->next;
    }

    printf("%d", count);

    return 0;
}
