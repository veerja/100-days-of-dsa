/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 1e9

typedef struct {
    int to, weight;
} Edge;

typedef struct Node {
    int v, dist;
} Node;

typedef struct {
    Node* data;
    int size;
} MinHeap;

void push(MinHeap* h, int v, int d) {
    int i = ++(h->size);
    while (i > 1 && h->data[i / 2].dist > d) {
        h->data[i] = h->data[i / 2];
        i /= 2;
    }
    h->data[i].v = v;
    h->data[i].dist = d;
}

Node pop(MinHeap* h) {
    Node res = h->data[1];
    Node last = h->data[(h->size)--];
    int i = 1, child;
    while (i * 2 <= h->size) {
        child = i * 2;
        if (child != h->size && h->data[child + 1].dist < h->data[child].dist) child++;
        if (last.dist > h->data[child].dist) h->data[i] = h->data[child];
        else break;
        i = child;
    }
    h->data[i] = last;
    return res;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Adjacency list setup
    int* head = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) head[i] = -1;
    
    struct ListNode { int to, w, next; } *edges = malloc(m * 2 * sizeof(struct ListNode));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges[i].to = v; edges[i].w = w; edges[i].next = head[u]; head[u] = i;
        // If undirected, add: edges[i+m].to = u; edges[i+m].w = w; edges[i+m].next = head[v]; head[v] = i+m;
    }

    int src;
    scanf("%d", &src);

    int* dist = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[src] = 0;

    MinHeap pq;
    pq.data = (Node*)malloc((m * 2 + 1) * sizeof(Node));
    pq.size = 0;
    push(&pq, src, 0);

    while (pq.size > 0) {
        Node current = pop(&pq);
        int u = current.v;
        if (current.dist > dist[u]) continue;

        for (int i = head[u]; i != -1; i = edges[i].next) {
            int v = edges[i].to;
            if (dist[u] + edges[i].w < dist[v]) {
                dist[v] = dist[u] + edges[i].w;
                push(&pq, v, dist[v]);
            }
        }
    }

    for (int i = 1; i <= n; i++) printf("%d ", dist[i] == INF ? -1 : dist[i]);
    printf("\n");

    return 0;
}
