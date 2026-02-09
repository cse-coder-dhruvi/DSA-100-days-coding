#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];

    // Read the input string
    scanf("%s", s);

    int n = strlen(s);

    // Reverse the string using two pointers
    for (int i = 0; i < n / 2; i++) {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }

    // Print the reversed string
    printf("%s", s);

    return 0;
}
