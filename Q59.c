#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
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
struct Node* buildTree(int inorder[], int postorder[], int start, int end, int* postIndex) {
    int current, inIndex;
    
    if (start > end)
        return NULL;

    current = postorder[*postIndex];
    (*postIndex)--;

    struct Node* node = newNode(current);

    if (start == end)
        return node;

    inIndex = search(inorder, start, end, current);

    node->right = buildTree(inorder, postorder, inIndex + 1, end, postIndex);
    node->left  = buildTree(inorder, postorder, start, inIndex - 1, postIndex);

    return node;
}

// Preorder traversal
void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n, i;
    scanf("%d", &n);

    int inorder[100], postorder[100];

    for (i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    preorder(root);

    return 0;
}
