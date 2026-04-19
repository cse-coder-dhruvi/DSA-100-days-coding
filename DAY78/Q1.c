#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

// Adjacency matrix representation
int graph[MAX][MAX];
int visited[MAX];
int n, m;

int primMST() {
    int totalWeight = 0;
    int minEdge[n];   // store minimum edge weight to connect each vertex
    int parent[n];    // store parent of each vertex

    // Initialize arrays
    for (int i = 0; i < n; i++) {
        minEdge[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    // Start from vertex 0
    minEdge[0] = 0;

    for (int count = 0; count < n; count++) {
        // Pick the minimum edge vertex not yet visited
        int u = -1;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && (u == -1 || minEdge[v] < minEdge[u])) {
                u = v;
            }
        }

        visited[u] = 1;
        totalWeight += minEdge[u];

        // Update adjacent vertices
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < minEdge[v]) {
                minEdge[v] = graph[u][v];
