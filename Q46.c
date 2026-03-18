#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue Node
struct QueueNode {
    struct Node* treeNode;
    struct QueueNode* next;
};

// Queue
struct Queue {
    struct QueueNode *front, *rear;
};

// Create new tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Create queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue
void enqueue(struct Queue* q, struct Node* node) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->treeNode = node;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

// Dequeue
struct Node* dequeue(struct Queue* q) {
    if (q->front == NULL)
        return NULL;

    struct QueueNode* temp = q->front;
    struct Node* node = temp->treeNode;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return node;
}

// Check if queue is empty
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Level Order Traversal
void levelOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        struct Node* current = dequeue(q);
        printf("%d ", current->data);

        if (current->left != NULL)
            enqueue(q, current->left);

        if (current->right != NULL)
            enqueue(q, current->right);
    }
}

// Example usage
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    printf("Level Order Traversal:\n");
    levelOrder(root);

    return 0;
}
