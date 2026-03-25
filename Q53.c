#include <stdio.h>
#include <stdlib.h>

// Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue node
struct QNode {
    struct Node* node;
    int hd;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Queue
struct QNode queue[1000];
int front = 0, rear = 0;

void enqueue(struct Node* node, int hd) {
    queue[rear].node = node;
    queue[rear].hd = hd;
    rear++;
}

struct QNode dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

#define OFFSET 500

struct {
    int values[100];
    int size;
} map[1000];

// Vertical order
void verticalOrder(struct Node* root) {
    int i, j;

    if (!root) return;

    enqueue(root, 0);

    while (!isEmpty()) {
        struct QNode temp = dequeue();
        struct Node* curr = temp.node;
        int hd = temp.hd;

        map[hd + OFFSET].values[map[hd + OFFSET].size++] = curr->data;

        if (curr->left)
            enqueue(curr->left, hd - 1);

        if (curr->right)
            enqueue(curr->right, hd + 1);
    }

    // Print result
    for (i = 0; i < 1000; i++) {
        if (map[i].size > 0) {
            for (j = 0; j < map[i].size; j++) {
                printf("%d ", map[i].values[j]);
            }
            printf("\n");
        }
    }
}

// Build tree
struct Node* buildTree(int arr[], int n) {
    struct Node* root;
    struct Node* queue2[1000];
    int f = 0, r = 0;
    int i = 1;

    if (n == 0 || arr[0] == -1) return NULL;

    root = newNode(arr[0]);
    queue2[r++] = root;

    while (i < n) {
        struct Node* curr = queue2[f++];

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue2[r++] = curr->left;
        }
        i++;

        if (i >= n) break;

        if (arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue2[r++] = curr->right;
        }
        i++;
    }

    return root;
}

// Main
int main() {
    int n, i;
    int arr[1000];

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Initialize map sizes
    for (i = 0; i < 1000; i++)
        map[i].size = 0;

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}
