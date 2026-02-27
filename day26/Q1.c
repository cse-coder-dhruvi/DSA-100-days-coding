#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int x;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;
        
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Function to find length of list
int getLength(struct Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

// Function to find intersection value
int findIntersection(struct Node* h1, struct Node* h2) {
    int len1 = getLength(h1);
    int len2 = getLength(h2);

    int diff = abs(len1 - len2);

    // Move pointer of longer list ahead
    if (len1 > len2) {
        while (diff--) h1 = h1->next;
    } else {
        while (diff--) h2 = h2->next;
    }

    // Traverse together
    while (h1 && h2) {
        if (h1->data == h2->data)
            return h1->data;
        h1 = h1->next;
        h2 = h2->next;
    }

    return -1; // no intersection
}

int main() {
    int n, m;
    
    scanf("%d", &n);
    struct Node* list1 = createList(n);
    
    scanf("%d", &m);
    struct Node* list2 = createList(m);

    int result = findIntersection(list1, list2);

    if (result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}
