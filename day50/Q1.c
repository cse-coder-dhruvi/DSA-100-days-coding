#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// BST Search function
int bstSearch(struct Node* root, int key) {
    // Base case
    if (root == NULL)
        return 0;

    // If key found
    if (root->data == key)
        return 1;

    // Go left
    if (key < root->data)
        return bstSearch(root->left, key);
    
    // Go right
    return bstSearch(root->right, key);
}

// Main function
int main() {
    struct Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(2);
    root->left->right = createNode(7);

    int key = 7;

    if (bstSearch(root, key))
        printf("Found");
    else
        printf("Not Found");

    return 0;
}
