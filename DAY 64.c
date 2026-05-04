/*Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// BFS Function
void BFS(int startNode, struct Node* adj[], int n) {
    bool visited[n];
    for (int i = 0; i < n; i++) visited[i] = false;

    // Queue implementation using array
    int queue[n];
    int front = 0, rear = 0;

    // Initialize source
    visited[startNode] = true;
    queue[rear++] = startNode;

    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);

        // Traverse neighbors
        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->vertex;
            if (!visited[v]) {
                visited[v] = true;
                queue[rear++] = v;
            }
            temp = temp->next;
        }
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

    scanf("%d", &s); // Starting vertex

    printf("BFS Traversal: ");
    BFS(s, adj, n);
    printf("\n");

    return 0;
}