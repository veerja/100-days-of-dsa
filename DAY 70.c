/*Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

Input:
- n vertices
- m edges (u,v,w)

Output:
- Shortest distances OR NEGATIVE CYCLE*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 1e9 // Use a large value, but not INT_MAX to avoid overflow during addition

struct Edge {
    int u, v, w;
};

void bellmanFord(int n, int m, struct Edge edges[], int src) {
    int dist[n];
    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[src] = 0;

    // 1. Relax edges n-1 times
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // 2. Check for negative weight cycles
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE DETECTED\n");
            return;
        }
    }

    // 3. Print result if no cycle
    printf("Vertex \t Distance from Source %d\n", src);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) printf("%d \t INF\n", i);
        else printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    int n, m, src;
    printf("Enter number of vertices and edges: ");
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Edge* edges = malloc(m * sizeof(struct Edge));
    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    bellmanFord(n, m, edges, src);

    free(edges);
    return 0;
}