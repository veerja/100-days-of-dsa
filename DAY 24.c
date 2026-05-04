/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous 
node's next pointer.*/

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

// Function to delete the first occurrence of a key
struct Node* deleteKey(struct Node* head, int key) {
    // 1. If list is empty
    if (head == NULL) return NULL;

    // 2. If the head node itself holds the key
    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp); // Free memory
        return head;
    }

    // 3. Search for the key, keeping track of the previous node
    struct Node* current = head;
    while (current->next != NULL && current->next->data != key) {
        current = current->next;
    }

    // 4. If key was found (current->next is not NULL)
    if (current->next != NULL) {
        struct Node* temp = current->next;
        current->next = current->next->next;
        free(temp); // Free memory
    }

    return head;
}

int main() {
    int n, key, val;
    if (scanf("%d", &n) != 1 || n <= 0) {
        // Handle empty case if n is 0
        if (n == 0) scanf("%d", &key); 
        return 0;
    }

    // Build the list
    scanf("%d", &val);
    struct Node* head = createNode(val);
    struct Node* tail = head;
    for (int i = 1; i < n; i++) {
        scanf("%d", &val);
        tail->next = createNode(val);
        tail = tail->next;
    }

    // Read the key to delete
    scanf("%d", &key);

    // Perform deletion
    head = deleteKey(head, key);

    // Print the result
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d%s", temp->data, (temp->next == NULL) ? "" : " ");
        temp = temp->next;
    }
    printf("\n");

    return 0;
}