#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    Node* nodes[n];
    int i, j;

    for (i = 0; i < n; i++) {
        if (arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    j = 1;
    for (i = 0; j < n; i++) {
        if (nodes[i] != NULL) {
            if (j < n)
                nodes[i]->left = nodes[j++];
            if (j < n)
                nodes[i]->right = nodes[j++];
        }
    }

    return nodes[0];
}

void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n, i;
    scanf("%d", &n);

    int arr[n];
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);

    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);
    printf("\n");

    return 0;
}
