#include <stdio.h>

#define MAX 100

int main() {
    int n, i;

    int queue[MAX], front = 0, rear = -1;
    int stack[MAX], top = -1;

    // input
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        queue[++rear] = x;
    }

    // Step 1: Queue -> Stack
    while(front <= rear) {
        stack[++top] = queue[front++];
    }

    // reset queue
    front = 0;
    rear = -1;

    // Step 2: Stack -> Queue
    while(top >= 0) {
        queue[++rear] = stack[top--];
    }

    // output
    for(i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}
