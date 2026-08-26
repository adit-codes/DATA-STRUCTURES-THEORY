#include <stdio.h>
#include <math.h>

#define MAX_SIZE 100

// Structure to represent the Array-Based Binary Tree
typedef struct {
    int data[MAX_SIZE];
    int size; // Total number of nodes (n)
} BinaryTree;

// Initialize the tree
void initTree(BinaryTree* tree) {
    tree->size = 0;
}

// Insert a node (Maintains Complete Binary Tree property)
void insert(BinaryTree* tree, int val) {
    if (tree->size >= MAX_SIZE - 1) {
        printf("Tree is full!\n");
        return;
    }
    tree->size++;
    tree->data[tree->size] = val; // 1-indexed storage
}

// Get Parent value of node at index i
void getParent(BinaryTree* tree, int i) {
    if (i <= 1 || i > tree->size) {
        printf("Node %d has no parent (Root or Invalid Index).\n", i);
        return;
    }
    int parentIndex = i / 2; // Floor division using integer arithmetic
    printf("Parent of Node %d (value %d) is Node %d (value %d)\n", 
            i, tree->data[i], parentIndex, tree->data[parentIndex]);
}

// Get Left Child value of node at index i
void getLeftChild(BinaryTree* tree, int i) {
    int leftIndex = 2 * i;
    if (leftIndex > tree->size || i < 1) {
        printf("Node %d has no left child.\n", i);
        return;
    }
    printf("Left Child of Node %d (value %d) is Node %d (value %d)\n", 
            i, tree->data[i], leftIndex, tree->data[leftIndex]);
}

// Get Right Child value of node at index i
void getRightChild(BinaryTree* tree, int i) {
    int rightIndex = 2 * i + 1;
    if (rightIndex > tree->size || i < 1) {
        printf("Node %d has no right child.\n", i);
        return;
    }
    printf("Right Child of Node %d (value %d) is Node %d (value %d)\n", 
            i, tree->data[i], rightIndex, tree->data[rightIndex]);
}

// Print the array representation
void printTree(BinaryTree* tree) {
    printf("\nTree Array [1-indexed]: ");
    for (int i = 1; i <= tree->size; i++) {
        printf("%d ", tree->data[i]);
    }
    printf("\n\n");
}

int main() {
    BinaryTree tree;
    initTree(&tree);

    // Insert 6 nodes into the tree: 10, 20, 30, 40, 50, 60
    insert(&tree, 10); // Index 1 (Root)
    insert(&tree, 20); // Index 2
    insert(&tree, 30); // Index 3
    insert(&tree, 40); // Index 4
    insert(&tree, 50); // Index 5
    insert(&tree, 60); // Index 6

    printTree(&tree);

    // Query Node 3 (value 30)
    int targetIndex = 3;
    printf("--- Querying Node at Index %d ---\n", targetIndex);
    getParent(&tree, targetIndex);
    getLeftChild(&tree, targetIndex);
    getRightChild(&tree, targetIndex);

    return 0;
}
