#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Create new node
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Search element in inorder
int search(int inorder[], int start, int end, int value) {
    int i;
    for (i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree
Node* buildTree(int preorder[], int inorder[], int start, int end, int* preIndex) {
    if (start > end)
        return NULL;

    int rootVal = preorder[*preIndex];
    (*preIndex)++;

    Node* root = newNode(rootVal);

    if (start == end)
        return root;

    int inIndex = search(inorder, start, end, rootVal);

    root->left = buildTree(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, end, preIndex);

    return root;
}

// Postorder traversal
void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[100], inorder[100];
    int i;

    for (i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;

    Node* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    postorder(root);

    return 0;
}
