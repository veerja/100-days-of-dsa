/*Problem: Level Order Traversal

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Function to perform Level Order Traversal
void printLevelOrder(struct Node* root, int n) {
    if (root == NULL) return;

    // Use a simple array-based queue
    struct Node* queue[n];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* curr = queue[front++];
        
        printf("%d ", curr->data);

        // Enqueue left child
        if (curr->left != NULL) {
            queue[rear++] = curr->left;
        }

        // Enqueue right child
        if (curr->right != NULL) {
            queue[rear++] = curr->right;
        }
    }
}

// Helper to build tree from level-order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node* queue[n];
    int f = 0, r = 0;
    queue[r++] = root;

    int i = 1;
    while (i < n) {
        struct Node* curr = queue[f++];
        if (i < n) {
            curr->left = newNode(arr[i++]);
            if (curr->left) queue[r++] = curr->left;
        }
        if (i < n) {
            curr->right = newNode(arr[i++]);
            if (curr->right) queue[r++] = curr->right;
        }
    }
    return root;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    printLevelOrder(root, n);
    printf("\n");

    return 0;
}