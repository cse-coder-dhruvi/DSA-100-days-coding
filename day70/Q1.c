#include <stdio.h>

#define INF 1000000000

struct Edge {
    int u, v, w;
};

int main() {
    int n, m, source;
    
    // Input
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);
    
    struct Edge edges[m];
    
    printf("Enter edges (u v w):\n");
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    
    printf("Enter source vertex: ");
    scanf("%d", &source);

    int dist[n+1];

    // Initialize distances
    for(int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[source] = 0;

    // Relax edges (n-1 times)
    for(int i = 1; i <= n-1; i++) {
        for(int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if(dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check negative cycle
    for(int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if(dist[u] != INF && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            return 0;
        }
    }

    // Output shortest distances
    printf("Shortest distances from source:\n");
    for(int i = 1; i <= n; i++) {
        printf("%d -> %d\n", i, dist[i]);
    }

    return 0;
}
