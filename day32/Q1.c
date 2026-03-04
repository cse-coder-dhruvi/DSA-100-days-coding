#include <stdio.h>

#define MAX 100

int main() {
    int stack[MAX];
    int top = -1;
    int n, m;

    // Number of elements to push
    scanf("%d", &n);

    // Push elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &stack[++top]);
    }

    // Number of pops
    scanf("%d", &m);

    // Pop elements
    for(int i = 0; i < m; i++) {
        if(top >= 0) {
            top--;   // remove top element
        }
    }

    // Print remaining elements (top to bottom)
    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}
