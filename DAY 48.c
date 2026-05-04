/*Problem: Count Leaf Nodes

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

// Standard node creation
struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Function to count leaf nodes
int countLeaves(struct Node* root) {
    if (root == NULL) return 0;
    
    // Check if current node is a leaf
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    
    // Otherwise, sum the leaves from both sides
    return countLeaves(root->left) + countLeaves(root->right);
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
    printf("%d\n", countLeaves(root));

    return 0;
}