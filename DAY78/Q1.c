#include <stdio.h>
#include <limits.h>

#define MAX 1000

int graph[MAX][MAX];
int visited[MAX];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize graph
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = 0;

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // undirected
    }

    int minEdge[n + 1];

    // Initialize
    for (int i = 1; i <= n; i++) {
        minEdge[i] = INT_MAX;
        visited[i] = 0;
    }

    minEdge[1] = 0; // start from node 1
    int totalWeight = 0;

    for (int count = 1; count <= n; count++) {
        int u = -1;

        // Find minimum edge vertex
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && (u == -1 || minEdge[i] < minEdge[u])) {
                u = i;
            }
        }

        visited[u] = 1;
        totalWeight += minEdge[u];

        // Update neighbors
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < minEdge[v]) {
                minEdge[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", totalWeight);

    return 0;
}
