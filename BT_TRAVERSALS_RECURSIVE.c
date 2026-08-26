#include <stdio.h>
#include <stdlib.h>

// Define binary tree node structure
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Utility function to create a new tree node
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 1. Inorder Traversal: Left -> Root -> Right
void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// 2. Preorder Traversal: Root -> Left -> Right
void preorder(Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// 3. Postorder Traversal: Left -> Right -> Root
void postorder(Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    /* Constructing the following Binary Tree:
             1
            / \
           2   3
          / \
         4   5
    */
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Preorder traversal : ");
    preorder(root);
    printf("\n");

    printf("Inorder traversal  : ");
    inorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
