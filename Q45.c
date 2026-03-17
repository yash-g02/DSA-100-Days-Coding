#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Queue structure
struct Queue {
    struct Node* arr[1000];
    int front;
    int rear;
};

void initQueue(struct Queue* q) {
    q->front = 0;
    q->rear = 0;
}

void enqueue(struct Queue* q, struct Node* node) {
    q->arr[q->rear++] = node;
}

struct Node* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    struct Queue q;
    struct Node* root;
    struct Node* curr;
    int i;

    if (n == 0 || arr[0] == -1)
        return NULL;

    initQueue(&q);

    root = newNode(arr[0]);
    enqueue(&q, root);

    i = 1;

    while (i < n && !isEmpty(&q)) {
        curr = dequeue(&q);

        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(&q, curr->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(&q, curr->right);
        }
        i++;
    }

    return root;
}

// Height function
int height(struct Node* root) {
    int leftHeight, rightHeight;

    if (root == NULL)
        return 0;

    leftHeight = height(root->left);
    rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Main function
int main() {
    int n;
    int i;
    int arr[1000];
    struct Node* root;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    root = buildTree(arr, n);

    printf("%d\n", height(root));

    return 0;
}
