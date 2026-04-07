#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];
bool visited[MAX];
bool recStack[MAX];
int n;

// DFS function
bool dfs(int node) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < n; i++) {
        if (graph[node][i]) {
            if (!visited[i] && dfs(i))
                return true;
            else if (recStack[i])
                return true;
        }
    }

    recStack[node] = false;
    return false;
}

// Function to check cycle
bool hasCycle() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return true;
        }
    }
    return false;
}

int main() {
    scanf("%d", &n);

    // Input adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize arrays
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
