#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int i, j, isPalindrome = 1;

    // Read string
    scanf("%s", s);

    i = 0;                      // left pointer
    j = strlen(s) - 1;          // right pointer

    // Two-pointer comparison
    while (i < j) {
        if (s[i] != s[j]) {
            isPalindrome = 0;   // not a palindrome
            break;
        }
        i++;
        j--;
    }

    if (isPalindrome)
        printf("YES");
    else
        printf("NO");

    return 0;
}
