#include <stdio.h>

int main() {
    int n, pos, x;
    int i;

    // Input size
    scanf("%d", &n);

    // Declare array with extra space
    int arr[n + 1];

    // Input array elements
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input position (1-based)
    scanf("%d", &pos);

    // Input element to insert
    scanf("%d", &x);

    // Shift elements to the right
    for (i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert element at position
    arr[pos - 1] = x;

    // Print updated array
    for (i = 0; i < n + 1; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
