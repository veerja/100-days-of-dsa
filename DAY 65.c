/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int vertex;
    struct Node* next;
};

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

bool isCycleRecursive(int u, int parent, struct Node* adj[], bool visited[]) {
    visited[u] = true;

    struct Node* temp = adj[u];
    while (temp != NULL) {
        int v = temp->vertex;

        // If neighbor is not visited, recurse
        if (!visited[v]) {
            if (isCycleRecursive(v, u, adj, visited))
                return true;
        }
        // If neighbor is visited and NOT the parent, cycle found!
        else if (v != parent) {
            return true;
        }
        temp = temp->next;
    }
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
    for (int i = 0; i < n; i++) visited[i] = false;

    bool hasCycle = false;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (isCycleRecursive(i, -1, adj, visited)) {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle) printf("YES\n");
    else printf("NO\n");

    return 0;
}