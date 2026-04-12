#include <stdio.h>
#include <string.h>

#define EMPTY -1

int main() {
    int m, q;
    
    // Input size of hash table
    scanf("%d", &m);
    
    int table[m];
    
    // Initialize table
    for(int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    // Number of queries
    scanf("%d", &q);

    char operation[10];
    int key;

    while(q--) {
        scanf("%s %d", operation, &key);

        if(strcmp(operation, "INSERT") == 0) {
            int i = 0;
            int index;

            // Quadratic probing
            while(i < m) {
                index = (key % m + i*i) % m;

                if(table[index] == EMPTY) {
                    table[index] = key;
                    break;
                }
                i++;
            }
        }

        else if(strcmp(operation, "SEARCH") == 0) {
            int i = 0;
            int index;
            int found = 0;

            while(i < m) {
                index = (key % m + i*i) % m;

                if(table[index] == EMPTY) {
                    break;
                }

                if(table[index] == key) {
                    found = 1;
                    break;
                }
                i++;
            }

            if(found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}
