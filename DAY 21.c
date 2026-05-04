/*Problem: Create and Traverse Singly Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50*/
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Get number of elements
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    // Step 1: Create the Linked List
    for (int i = 0; i < n; i++) {
        // Allocate memory for a new node
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &value);
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            // If it's the first node, head points to it
            head = newNode;
            temp = head;
        } else {
            // Link the previous node to the new node
            temp->next = newNode;
            // Move temp to the new last node
            temp = newNode;
        }
    }

    // Step 2: Traverse and Print the Linked List
    temp = head; // Start from the beginning
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" "); // Print space between elements
        }
        temp = temp->next; // Move to the next node
    }
    printf("\n");

    return 0;
}