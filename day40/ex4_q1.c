#include <stdio.h>
#define MAX 5

int q1[MAX], q2[MAX];
int f1 = -1, r1 = -1, f2 = -1, r2 = -1;

void enqueue(int q[], int *f, int *r, int x) {
    if (*r == MAX - 1) return;
    if (*f == -1) *f = 0;
    q[++(*r)] = x;
}

int dequeue(int q[], int *f, int *r) {
    if (*f == -1) return -1;
    int val = q[*f];
    if (*f == *r) *f = *r = -1;
    else (*f)++;
    return val;
}

void push(int x) {
    enqueue(q2, &f2, &r2, x);

    while (f1 != -1)
        enqueue(q2, &f2, &r2, dequeue(q1, &f1, &r1));

    // swap queues
    int i;
    for (i = 0; i <= r2; i++)
        q1[i] = q2[i];

    f1 = 0;
    r1 = r2;

    f2 = r2 = -1;
}

void pop() {
    if (f1 == -1)
        printf("Stack Empty\n");
    else
        printf("Popped: %d\n", dequeue(q1, &f1, &r1));
}

int main() {
    push(10);
    push(20);
    push(30);
    pop();
    pop();
    return 0;
}