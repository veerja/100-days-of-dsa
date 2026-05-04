/*Problem: Circular Queue Using Array - Implement using linked list 
with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to 
start after reaching array end. Dequeue removes elements from front. 
Display remaining elements in correct order.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct CircularQueue {
    struct Node* rear;
};

void enqueue(struct CircularQueue* q, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    if (q->rear == NULL) {
        q->rear = newNode;
        newNode->next = q->rear;
    } else {
        newNode->next = q->rear->next;
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void dequeue(struct CircularQueue* q) {
    if (q->rear == NULL) return;

    struct Node* front = q->rear->next;
    if (front == q->rear) {
        free(front);
        q->rear = NULL;
    } else {
        q->rear->next = front->next;
        free(front);
    }
}

void display(struct CircularQueue* q) {
    if (q->rear == NULL) return;

    struct Node* temp = q->rear->next; // Start at front
    do {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp != q->rear->next) printf(" ");
    } while (temp != q->rear->next);
    printf("\n");
}

int main() {
    int n, m, val;
    struct CircularQueue q = {NULL};

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        dequeue(&q);
    }

    display(&q);

    return 0;
}