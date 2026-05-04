/*Problem: Circular Linked List Creation and Traversal -
Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Last node's next points to head. Traverse from head until returning to head
to avoid infinite loop.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, val;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    struct Node *head = NULL, *tail = NULL;

    // 1. Creation of Circular Linked List
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            newNode->next = head; // Point to itself initially
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;    // Make it circular
        }
    }

    // 2. Traversal
    if (head != NULL) {
        struct Node* temp = head;
        do {
            printf("%d", temp->data);
            temp = temp->next;
            if (temp != head) printf(" ");
        } while (temp != head);
        printf("\n");
    }

    // Note: In a real program, remember to break the loop to free memory properly!
    return 0;
}