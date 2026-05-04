/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.*/

#include <stdio.h>
#include <stdlib.h>

// Definition of the Node structure
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

// Function to build a list from user input
struct Node* buildList(int size) {
    if (size == 0) return NULL;
    int val;
    scanf("%d", &val);
    struct Node* head = createNode(val);
    struct Node* tail = head;
    for (int i = 1; i < size; i++) {
        scanf("%d", &val);
        tail->next = createNode(val);
        tail = tail->next;
    }
    return head;
}

// Function to merge two sorted lists
struct Node* mergeSortedLists(struct Node* l1, struct Node* l2) {
    struct Node dummy; // Use a stack-allocated dummy node
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // Attach the remaining part of the non-empty list
    if (l1 != NULL) tail->next = l1;
    else tail->next = l2;

    return dummy.next;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d%s", head->data, (head->next == NULL) ? "" : " ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, m;

    // Build List 1
    if (scanf("%d", &n) != 1) return 0;
    struct Node* list1 = buildList(n);

    // Build List 2
    if (scanf("%d", &m) != 1) return 0;
    struct Node* list2 = buildList(m);

    // Merge and Print
    struct Node* mergedHead = mergeSortedLists(list1, list2);
    printList(mergedHead);

    return 0;
}