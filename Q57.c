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
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Queue for level order
struct Queue {
    struct Node* arr[100];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, struct Node* node) {
    if (q->rear == 99) return;
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = node;
}

struct Node* dequeue(struct Queue* q) {
    struct Node* temp;
    if (isEmpty(q)) return NULL;

    temp = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;

    return temp;
}

// Build tree
struct Node* buildTree(int arr[], int n) {
    struct Queue q;
    struct Node* root;
    struct Node* curr;
    int i = 1;

    if (n == 0 || arr[0] == -1) return NULL;

    initQueue(&q);
    root = createNode(arr[0]);
    enqueue(&q, root);

    while (i < n) {
        curr = dequeue(&q);

        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(&q, curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(&q, curr->right);
        }
        i++;
    }

    return root;
}

// Mirror tree
void mirror(struct Node* root) {
    struct Node* temp;
    if (root == NULL) return;

    temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;
    int arr[100];
    int i;  // ? Declare here (outside loop)

    scanf("%d", &n);

    for (i = 0; i < n; i++) {  // ? Now valid
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    mirror(root);
    inorder(root);

    return 0;
}
