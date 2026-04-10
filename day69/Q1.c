#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for adjacency list
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// Min Heap Node
struct MinHeapNode {
    int vertex;
    int distance;
};

// Min Heap
struct MinHeap {
    int size;
    struct MinHeapNode* array[MAX];
};

// Create new adjacency list node
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(struct Node* adj[], int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Swap heap nodes
void swap(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify
void heapify(struct MinHeap* heap, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < heap->size && heap->array[left]->distance < heap->array[smallest]->distance)
        smallest = left;

    if (right < heap->size && heap->array[right]->distance < heap->array[smallest]->distance)
        smallest = right;

    if (smallest != i) {
        swap(&heap->array[i], &heap->array[smallest]);
        heapify(heap, smallest);
    }
}

// Extract min
struct MinHeapNode* extractMin(struct MinHeap* heap) {
    if (heap->size == 0)
        return NULL;

    struct MinHeapNode* root = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapify(heap, 0);

    return root;
}

// Insert into heap
void insertHeap(struct MinHeap* heap, int v, int dist) {
    struct MinHeapNode* node = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    node->vertex = v;
    node->distance = dist;

    int i = heap->size++;
    heap->array[i] = node;

    while (i && heap->array[(i-1)/2]->distance > heap->array[i]->distance) {
        swap(&heap->array[i], &heap->array[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Dijkstra function
void dijkstra(struct Node* adj[], int V, int src) {
    int dist[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->size = 0;

    dist[src] = 0;
    insertHeap(heap, src, 0);

    while (heap->size > 0) {
        struct MinHeapNode* minNode = extractMin(heap);
        int u = minNode->vertex;

        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                insertHeap(heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

// Main function
int main() {
    int V = 5;
    struct Node* adj[MAX] = {NULL};

    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 4, 5);
    addEdge(adj, 1, 2, 1);
    addEdge(adj, 4, 1, 3);
    addEdge(adj, 4, 2, 9);
    addEdge(adj, 2, 3, 4);

    dijkstra(adj, V, 0);

    return 0;
}
