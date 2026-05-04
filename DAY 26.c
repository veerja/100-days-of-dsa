/*Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes 
sequentially, traverse from head using next pointer.*/

#include <stdio.h>
#include <stdlib.h>

// Define the Doubly Linked List Node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

int main() {
    int n, value;
    struct Node *head = NULL, *tail = NULL;

    // Read the number of elements
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    // Step 1: Create the Doubly Linked List
    for (int i = 0; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &value);
        
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {
            // First node: both head and tail point here
            head = newNode;
            tail = newNode;
        } else {
            // Link the current tail to the new node
            tail->next = newNode;
            // Set the new node's prev to the old tail
            newNode->prev = tail;
            // Move the tail pointer to the new node
            tail = newNode;
        }
    }

    // Step 2: Forward Traversal
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" ");
        }
        temp = temp->next;
    }
    printf("\n");

    return 0;
}