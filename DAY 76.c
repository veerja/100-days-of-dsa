/*Problem Statement
Using DFS or BFS, count number of connected components.

Input Format
n m
edges

Output Format
Number of connected components.

Sample Input
6 3
1 2
2 3
5 6

Sample Output
3

Explanation
Components: {1,2,3}, {4}, {5,6}*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int vertex;
    struct Node* next;
};

// Function to add an undirected edge
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

void dfs(int u, struct Node* adj[], bool visited[]) {
    visited[u] = true;
    struct Node* temp = adj[u];
    while (temp) {
        if (!visited[temp->vertex]) {
            dfs(temp->vertex, adj, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Initialize adjacency list
    struct Node** adj = (struct Node**)calloc(n + 1, sizeof(struct Node*));
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    bool* visited = (bool*)calloc(n + 1, sizeof(bool));
    int componentCount = 0;

    // Traverse all nodes
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            componentCount++;
            dfs(i, adj, visited);
        }
    }

    printf("%d\n", componentCount);

    // Cleanup
    free(visited);
    return 0;
}