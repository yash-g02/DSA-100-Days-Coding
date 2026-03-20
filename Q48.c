#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create tree using preorder input (-1 for NULL)
struct Node* createTree() {
    int val;
    scanf("%d", &val);

    if (val == -1)
        return NULL;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    newNode->left = createTree();
    newNode->right = createTree();

    return newNode;
}

// Count leaf nodes
int countLeafNodes(struct Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    struct Node* root = createTree();
    printf("%d\n", countLeafNodes(root));
    return 0;
}
