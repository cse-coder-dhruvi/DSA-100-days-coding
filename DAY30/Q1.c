#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial term
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Create new node
struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int c, int e) {
    struct Node* temp = createNode(c, e);
    
    if (head == NULL)
        return temp;
    
    struct Node* p = head;
    while (p->next != NULL)
        p = p->next;
    
    p->next = temp;
    return head;
}

// Print polynomial
void printPoly(struct Node* head) {
    struct Node* p = head;
    
    while (p != NULL) {
        if (p->exp == 0)
            printf("%d", p->coeff);
        else if (p->exp == 1)
            printf("%dx", p->coeff);
        else
            printf("%dx^%d", p->coeff, p->exp);
        
        if (p->next != NULL)
            printf(" + ");
        
        p = p->next;
    }
    printf("\n");
}

int main() {
    int n, c, e;
    struct Node* head = NULL;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        head = insertEnd(head, c, e);
    }
    
    printPoly(head);
    return 0;
}
