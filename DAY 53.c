/*Problem Statement:
Given a binary tree, print its vertical order traversal. 
Nodes that lie on the same vertical line should be printed together from 
top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order
traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. 
Nodes sharing the same distance are printed together.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000

struct Node {
    int data;
    struct Node *left, *right;
};

struct QueueItem {
    struct Node* node;
    int hd;
};

// Linked list to store nodes at a specific HD
struct ListNode {
    int data;
    struct ListNode* next;
};

struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level-order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node* q[MAX_NODES];
    int f = 0, r = 0;
    q[r++] = root;
    int i = 1;
    while (i < n) {
        struct Node* curr = q[f++];
        if (i < n) {
            curr->left = newNode(arr[i++]);
            if (curr->left) q[r++] = curr->left;
        }
        if (i < n) {
            curr->right = newNode(arr[i++]);
            if (curr->right) q[r++] = curr->right;
        }
    }
    return root;
}

void printVerticalOrder(struct Node* root, int n) {
    if (!root) return;

    // Array of linked lists to store nodes at each HD
    // Offset by 500 to handle negative HDs (HD -500 to 500)
    struct ListNode* map[1001] = {NULL};
    int min_hd = 0, max_hd = 0;

    struct QueueItem q[MAX_NODES];
    int f = 0, r = 0;
    q[r++] = (struct QueueItem){root, 0};

    while (f < r) {
        struct QueueItem curr = q[f++];
        struct Node* node = curr.node;
        int hd = curr.hd;

        if (hd < min_hd) min_hd = hd;
        if (hd > max_hd) max_hd = hd;

        // Append to linked list at map[hd + 500]
        struct ListNode* newLNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newLNode->data = node->data;
        newLNode->next = NULL;

        if (map[hd + 500] == NULL) {
            map[hd + 500] = newLNode;
        } else {
            struct ListNode* temp = map[hd + 500];
            while (temp->next) temp = temp->next;
            temp->next = newLNode;
        }

        if (node->left) q[r++] = (struct QueueItem){node->left, hd - 1};
        if (node->right) q[r++] = (struct QueueItem){node->right, hd + 1};
    }

    // Print columns from min_hd to max_hd
    for (int i = min_hd; i <= max_hd; i++) {
        struct ListNode* temp = map[i + 500];
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    printVerticalOrder(root, n);

    return 0;
}
