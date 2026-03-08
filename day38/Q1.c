#include <stdio.h>

#define MAX 100

int main() {
    int queue[MAX];
    int front = 0, rear = -1;
    int n, m, i, x;

    scanf("%d", &n);

    // Enqueue elements
    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        rear = (rear + 1) % MAX;
        queue[rear] = x;
    }

    // Number of dequeue operations
    scanf("%d", &m);

    for(i = 0; i < m; i++) {
        int temp = queue[front];   // remove front
        front = (front + 1) % MAX;

        rear = (rear + 1) % MAX;   // add at rear
        queue[rear] = temp;
    }

    // Print queue
    int count = n;
    int index = front;

    while(count--) {
        printf("%d ", queue[index]);
        index = (index + 1) % MAX;
    }

    return 0;
}
