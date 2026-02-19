#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Step 1: Sort array
    qsort(arr, n, sizeof(int), compare);

    // Step 2: Two pointer approach
    int left = 0;
    int right = n - 1;

    int min_sum = 1000000000;
    int num1 = arr[left], num2 = arr[right];

    while (left < right) {
        int sum = arr[left] + arr[right];

        // Update closest sum
        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            num1 = arr[left];
            num2 = arr[right];
        }

        // Move pointers
        if (sum < 0)
            left++;
        else
            right--;
    }

    // Output result
    printf("%d %d", num1, num2);

    return 0;
}
