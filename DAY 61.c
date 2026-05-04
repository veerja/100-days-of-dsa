/*Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.

Input:
- n (vertices)
- m (edges)
- m pairs (u, v)

Output:
- n x n adjacency matrix*/
#include <stdio.h>
#include <stdlib.h>

void printMatrix(int n, int matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m, isDirected;
    
    // Read number of vertices and edges
    if (scanf("%d %d", &n, &m) != 2) return 0;
    
    // Toggle: 1 for Directed, 0 for Undirected
    // For this example, let's assume undirected as per standard problems
    isDirected = 0; 

    // Initialize n x n matrix with 0
    int matrix[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }

    // Read m edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        
        // Adjust indices if input is 1-indexed (e.g., vertices 1 to n)
        // matrix[u-1][v-1] = 1;
        
        matrix[u][v] = 1;
        if (!isDirected) {
            matrix[v][u] = 1;
        }
    }

    printMatrix(n, matrix);

    return 0;
}