/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int vertex;
    struct Node* next;
};

// Standard Adjacency List edge insertion (Directed: u -> v)
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Recursive DFS helper
void topologicalSortUtil(int u, struct Node* adj[], bool visited[], int stack[], int* top) {
    visited[u] = true;

    struct Node* temp = adj[u];
    while (temp != NULL) {
        int v = temp->vertex;
        if (!visited[v]) {
            topologicalSortUtil(v, adj, visited, stack, top);
        }
        temp = temp->next;
    }

    // Push current vertex to stack after all neighbors are visited
    stack[(*top)++] = u;
}

void topologicalSort(int n, struct Node* adj[]) {
    bool visited[n];
    int stack[n];
    int top = 0;

    for (int i = 0; i < n; i++) visited[i] = false;

    // Call the recursive helper for all unvisited vertices
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, adj, visited, stack, &top);
        }
    }

    // Print contents of stack in reverse order
    printf("Topological Sort: ");
    while (top > 0) {
        printf("%d ", stack[--top]);
    }
    printf("\n");
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    topologicalSort(n, adj);

    return 0;
}