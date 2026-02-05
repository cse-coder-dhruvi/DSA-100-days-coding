#include <stdio.h>

int main() {
    int p, q;

    // Input size of first log
    scanf("%d", &p);
    int a[p];
    for(int i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    // Input size of second log
    scanf("%d", &q);
    int b[q];
    for(int i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }

    int i = 0, j = 0;

    // Merge both sorted logs
    while(i < p && j < q) {
        if(a[i] <= b[j]) {
            printf("%d ", a[i]);
            i++;
        } else {
            printf("%d ", b[j]);
            j++;
        }
    }

    // Print remaining elements of first log
    while(i < p) {
        printf("%d ", a[i]);
        i++;
    }

    // Print remaining elements of second log
    while(j < q) {
        printf("%d ", b[j]);
        j++;
    }

    return 0;
}
