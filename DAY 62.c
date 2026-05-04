/*Problem: Build a graph with adjacency list representation. 
Use linked lists or dynamic arrays.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- List of adjacency lists for each vertex*/
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure for the adjacency list
struct AdjList {
    struct Node* head;
};

// Function to create a new adjacency list node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct AdjList* array, int u, int v) {
    // Add an edge from u to v
    struct Node* newNode = createNode(v);
    newNode->next = array[u].head;
    array[u].head = newNode;

    // Since the graph is undirected, add an edge from v to u
    newNode = createNode(u);
    newNode->next = array[v].head;
    array[v].head = newNode;
}

void printGraph(struct AdjList* array, int n) {
    for (int i = 0; i < n; i++) {
        struct Node* temp = array[i].head;
        printf("Vertex %d:", i);
        while (temp) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Create an array of adjacency lists
    struct AdjList* array = (struct AdjList*)malloc(n * sizeof(struct AdjList));

    for (int i = 0; i < n; i++) {
        array[i].head = NULL;
    }

    // Input m edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        // Assuming 0-indexed input; if 1-indexed, use u-1 and v-1
        addEdge(array, u, v);
    }

    printGraph(array, n);

    return 0;
}
