/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int vertex;
    struct Node* next;
};

// Function to add a directed edge (u -> v)
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

bool hasCycleDFS(int u, struct Node* adj[], bool visited[], bool recStack[]) {
    visited[u] = true;
    recStack[u] = true;

    struct Node* temp = adj[u];
    while (temp != NULL) {
        int v = temp->vertex;

        // If not visited, recurse
        if (!visited[v]) {
            if (hasCycleDFS(v, adj, visited, recStack))
                return true;
        } 
        // If already in the current recursion path, cycle found
        else if (recStack[v]) {
            return true;
        }
        temp = temp->next;
    }

    // Backtrack: remove from recursion stack
    recStack[u] = false;
    return false;
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

    bool visited[n];
    bool recStack[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    bool cycleFound = false;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (hasCycleDFS(i, adj, visited, recStack)) {
                cycleFound = true;
                break;
            }
        }
    }

    if (cycleFound) printf("YES\n");
    else printf("NO\n");

    return 0;
}