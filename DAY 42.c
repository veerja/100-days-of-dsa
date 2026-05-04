/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10*/
#include <stdio.h>
#include <stdlib.h>

// Queue Node
struct Node {
    int data;
    struct Node* next;
};

// Queue Structure
struct Queue {
    struct Node *front, *rear;
};

// Stack Node
struct StackNode {
    int data;
    struct StackNode* next;
};

// --- Queue Operations ---
void enqueue(struct Queue* q, int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(struct Queue* q) {
    if (q->front == NULL) return -1;
    struct Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return data;
}

// --- Stack Operations ---
void push(struct StackNode** top, int x) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = x;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct StackNode** top) {
    if (*top == NULL) return -1;
    struct StackNode* temp = *top;
    int data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}

// --- Reversal Logic ---
void reverseQueue(struct Queue* q, int n) {
    struct StackNode* stack = NULL;

    // Step 1: Queue to Stack
    for (int i = 0; i < n; i++) {
        push(&stack, dequeue(q));
    }

    // Step 2: Stack back to Queue
    while (stack != NULL) {
        enqueue(q, pop(&stack));
    }
}

int main() {
    int n, val;
    if (scanf("%d", &n) != 1) return 0;

    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(q, val);
    }

    reverseQueue(q, n);

    // Print output
    struct Node* temp = q->front;
    while (temp) {
        printf("%d%s", temp->data, temp->next ? " " : "");
        temp = temp->next;
    }
    printf("\n");

    return 0;
}