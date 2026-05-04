/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
1 2 3 4 5 6 7
4 5

Output:
2*/
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

// Build tree from level-order array
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

// Recursive function to find LCA in a general binary tree
struct Node* findLCA(struct Node* root, int p, int q) {
    if (root == NULL || root->data == p || root->data == q) {
        return root;
    }

    struct Node* leftResult = findLCA(root->left, p, q);
    struct Node* rightResult = findLCA(root->right, p, q);

    // If p is in one subtree and q is in the other, current node is LCA
    if (leftResult != NULL && rightResult != NULL) {
        return root;
    }

    // Otherwise, return the side that found a target
    return (leftResult != NULL) ? leftResult : rightResult;
}

int main() {
    int n, p, q;
    if (scanf("%d", &n) != 1) return 0;
    
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d %d", &p, &q);

    struct Node* root = buildTree(arr, n);
    struct Node* lca = findLCA(root, p, q);

    if (lca) printf("%d\n", lca->data);

    return 0;
}