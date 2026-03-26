#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int data) {
    struct Node* newNode;

    if (data == -1)
        return NULL;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Queue structure
struct Queue {
    struct Node* arr[1000];
    int front;
    int rear;
};

// Queue functions
void initQueue(struct Queue* q) {
    q->front = 0;
    q->rear = 0;
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

void enqueue(struct Queue* q, struct Node* node) {
    q->arr[q->rear] = node;
    q->rear++;
}

struct Node* dequeue(struct Queue* q) {
    struct Node* temp = q->arr[q->front];
    q->front++;
    return temp;
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

    root = createNode(arr[0]);
    enqueue(&q, root);

    i = 1;

    while (!isEmpty(&q) && i < n) {
        curr = dequeue(&q);

        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(&q, curr->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(&q, curr->right);
        }
        i++;
    }

    return root;
}

// Zigzag traversal
void zigzagTraversal(struct Node* root) {
    struct Queue q;
    int leftToRight;
    int size;
    int level[1000];
    int i;
    struct Node* node;
    int index;

    if (root == NULL)
        return;

    initQueue(&q);
    enqueue(&q, root);

    leftToRight = 1;

    while (!isEmpty(&q)) {
        size = q.rear - q.front;

        for (i = 0; i < size; i++) {
            node = dequeue(&q);

            if (leftToRight)
                index = i;
            else
                index = size - 1 - i;

            level[index] = node->data;

            if (node->left != NULL)
                enqueue(&q, node->left);

            if (node->right != NULL)
                enqueue(&q, node->right);
        }

        for (i = 0; i < size; i++) {
            printf("%d ", level[i]);
        }

        leftToRight = !leftToRight;
    }
}

// Main
int main() {
    int n;
    int arr[1000];
    int i;
    struct Node* root;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    root = buildTree(arr, n);

    zigzagTraversal(root);

    return 0;
}
