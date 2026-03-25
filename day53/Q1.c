#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue Node (for BFS)
struct QNode {
    struct Node* node;
    int hd;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Queue implementation
struct QNode queue[MAX];
int front = -1, rear = -1;

void enqueue(struct Node* node, int hd) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    rear++;
    queue[rear].node = node;
    queue[rear].hd = hd;
}

struct QNode dequeue() {
    struct QNode temp = queue[front];
    front++;
    return temp;
}

int isEmpty() {
    return front > rear || front == -1;
}

// Vertical Order Function
void verticalOrder(struct Node* root) {
    if (root == NULL) return;

    int min = 0, max = 0;

    // Store values
    int result[200][MAX]; 
    int count[200] = {0};

    enqueue(root, 0);

    while (!isEmpty()) {
        struct QNode q = dequeue();
        struct Node* node = q.node;
        int hd = q.hd;

        int index = hd + 100; // shift for negative

        result[index][count[index]++] = node->data;

        if (hd < min) min = hd;
        if (hd > max) max = hd;

        if (node->left)
            enqueue(node->left, hd - 1);

        if (node->right)
            enqueue(node->right, hd + 1);
    }

    // Print result
    for (int i = min; i <= max; i++) {
        int index = i + 100;
        for (int j = 0; j < count[index]; j++) {
            printf("%d ", result[index][j]);
        }
        printf("\n");
    }
}
