/*Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning 
Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 1e9

typedef struct {
    int to;
    int weight;
} Edge;

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Adjacency Matrix used here for simplicity (suitable for n up to ~1000)
    // For larger n, use an Adjacency List with a Priority Queue
    int adj[n + 1][n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = (i == j) ? 0 : INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        if (w < adj[u][v]) { // Handle multiple edges between same nodes
            adj[u][v] = adj[v][u] = w;
        }
    }

    int key[n + 1];
    bool visited[n + 1];
    for (int i = 1; i <= n; i++) {
        key[i] = INF;
        visited[i] = false;
    }

    key[1] = 0;
    int totalWeight = 0;

    for (int count = 0; count < n; count++) {
        int u = -1;

        // Find the minimum key vertex from the set of vertices not yet included in MST
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        if (key[u] == INF) break; // Graph is disconnected

        visited[u] = true;
        totalWeight += key[u];

        // Update key values of the adjacent vertices of the picked vertex
        for (int v = 1; v <= n; v++) {
            if (adj[u][v] != INF && !visited[v] && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
            }
        }
    }

    printf("%d\n", totalWeight);

    return 0;
}