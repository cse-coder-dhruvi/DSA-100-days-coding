#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main() {
    int n, arr[MAX];
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int count = 0;
    int sum = 0;

    // hashmap using array (range limited for exam use)
    int freq[20001] = {0}; 
    int offset = 10000; // to handle negative sums

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(sum == 0)
            count++;

        if(freq[sum + offset] > 0)
            count += freq[sum + offset];

        freq[sum + offset]++;
    }

    printf("%d", count);
    return 0;
}
