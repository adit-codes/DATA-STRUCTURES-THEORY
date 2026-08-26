#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define Type (e.g., int)
typedef int Type;

// Define node structure
typedef struct node {
    Type data;
    struct node *link;
} node;

// Global pointer to the top of the stack
node *top = NULL;

// Algorithm Add(item) -> Push operation
bool Add(Type item) {
    // Get a new node
    node *temp = (node *)malloc(sizeof(node));
    
    if (temp != NULL) {
        temp->data = item;
        temp->link = top;
        top = temp;
        return true;
    } else {
        printf("Out of space!\n");
        return false;
    }
}

// Algorithm Delete(item) -> Pop operation
bool Delete(Type *item) {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return false;
    } else {
        node *temp = top;
        *item = top->data;
        top = top->link;
        free(temp); // delete temp
        return true;
    }
}
