/*Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int vertex;
    struct Node* next;
};

// Standard adjacency list insertion
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

void dfs(int u, struct Node* adj[], bool visited[], int* count) {
    visited[u] = true;
    (*count)++; // Increment count of reached nodes
    
    struct Node* temp = adj[u];
    while (temp) {
        if (!visited[temp->vertex]) {
            dfs(temp->vertex, adj, visited, count);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // If there are nodes but no edges, it's only connected if n = 1
    if (n > 1 && m == 0) {
        printf("NOT CONNECTED\n");
        return 0;
    }

    struct Node** adj = (struct Node**)calloc(n + 1, sizeof(struct Node*));
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    bool* visited = (bool*)calloc(n + 1, sizeof(bool));
    int reachedNodes = 0;

    // Start DFS from the first node
    dfs(1, adj, visited, &reachedNodes);

    if (reachedNodes == n) {
        printf("CONNECTED\n");
    } else {
        printf("NOT CONNECTED\n");
    }

    return 0;
}