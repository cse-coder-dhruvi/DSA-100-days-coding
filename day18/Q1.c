#include <stdio.h>

int main() {
    int n, k;
    
    // Read array size
    scanf("%d", &n);
    
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Read k
    scanf("%d", &k);
    
    // Handle cases where k > n
    k = k % n;
    
    int rotated[n];
    
    // Copy last k elements to start
    for(int i = 0; i < k; i++) {
        rotated[i] = arr[n - k + i];
    }
    
    // Copy first n-k elements after that
    for(int i = k; i < n; i++) {
        rotated[i] = arr[i - k];
    }
    
    // Print rotated array
    for(int i = 0; i < n; i++) {
        printf("%d ", rotated[i]);
    }
    
    return 0;
}
