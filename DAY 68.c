/*Problem: Implement topological sorting using in-degree array and queue 
(Kahnâ€™s Algorithm).*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

void addEdge(struct Node* adj[], int indegree[], int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
    
    // Increment in-degree of the destination vertex
    indegree[v]++;
}

void kahnsTopologicalSort(int n, struct Node* adj[], int indegree[]) {
    int queue[n];
    int front = 0, rear = 0;
    int topoOrder[n];
    int count = 0;

    // 1. Add all vertices with in-degree 0 to queue
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // 2. Process the queue
    while (front < rear) {
        int u = queue[front++];
        topoOrder[count++] = u;

        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->vertex;
            indegree[v]--; // "Remove" edge u -> v
            
            if (indegree[v] == 0) {
                queue[rear++] = v;
            }
            temp = temp->next;
        }
    }

    // 3. Output results
    if (count != n) {
        printf("The graph contains a cycle. Topological sort impossible.\n");
    } else {
        printf("Topological Order: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", topoOrder[i]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Node* adj[n];
    int indegree[n];
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        indegree[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, indegree, u, v);
    }

    kahnsTopologicalSort(n, adj, indegree);

    return 0;
}