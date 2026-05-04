/*Problem: Given weighted graph with non-negative edges, compute shortest path
from source using priority queue.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

// 1. Structure for Adjacency List Node
struct Node {
    int target, weight;
    struct Node* next;
};

// 2. Structure for Min-Heap Node
struct HeapNode {
    int v, dist;
};

// 3. Min-Heap Functions
void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode t = *a; *a = *b; *b = t;
}

void minHeapify(struct HeapNode heap[], int i, int size) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left].dist < heap[smallest].dist) smallest = left;
    if (right < size && heap[right].dist < heap[smallest].dist) smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, smallest, size);
    }
}

// 4. Dijkstra's Algorithm
void dijkstra(int n, struct Node* adj[], int src) {
    int dist[n];
    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[src] = 0;

    // Allocate heap (Worst case size: number of edges)
    struct HeapNode* heap = malloc(10000 * sizeof(struct HeapNode)); 
    int heapSize = 0;

    // Push source to heap
    heap[heapSize++] = (struct HeapNode){src, 0};

    while (heapSize > 0) {
        // Pop min
        struct HeapNode root = heap[0];
        heap[0] = heap[--heapSize];
        minHeapify(heap, 0, heapSize);

        int u = root.v;
        int d = root.dist;

        // Skip if we already found a shorter path
        if (d > dist[u]) continue;

        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->target;
            int weight = temp->weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                heap[heapSize++] = (struct HeapNode){v, dist[v]};
                
                // Bubble up
                int curr = heapSize - 1;
                while (curr > 0 && heap[(curr - 1) / 2].dist > heap[curr].dist) {
                    swap(&heap[curr], &heap[(curr - 1) / 2]);
                    curr = (curr - 1) / 2;
                }
            }
            temp = temp->next;
        }
    }

    printf("\nVertex \t Distance from Source %d\n", src);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) printf("%d \t INF\n", i);
        else printf("%d \t %d\n", i, dist[i]);
    }
    free(heap);
}

// 5. Main function to handle input
int main() {
    int n, m, src;
    printf("Enter number of vertices and edges: ");
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        
        // Add edge u -> v
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->target = v;
        newNode->weight = w;
        newNode->next = adj[u];
        adj[u] = newNode;
        
        // If undirected, uncomment the lines below:
        /*
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->target = u;
        newNode->weight = w;
        newNode->next = adj[v];
        adj[v] = newNode;
        */
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(n, adj, src);

    return 0;
}