/*Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Function to add an edge (undirected)
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

// Recursive DFS Function
void DFS(int u, struct Node* adj[], bool visited[]) {
    // 1. Mark the current node as visited and print it
    visited[u] = true;
    printf("%d ", u);

    // 2. Traverse all neighbors of the current vertex
    struct Node* temp = adj[u];
    while (temp != NULL) {
        int v = temp->vertex;
        if (!visited[v]) {
            DFS(v, adj, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m, s;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    // Input starting vertex
    scanf("%d", &s);

    bool visited[n];
    for (int i = 0; i < n; i++) visited[i] = false;

    printf("DFS Traversal starting from %d: ", s);
    DFS(s, adj, visited);
    printf("\n");

    return 0;
}