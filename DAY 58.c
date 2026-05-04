/*Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree

Example:
Input:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1

Explanation:
Preorder identifies root, inorder splits left and right subtrees.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Recursive function to build the tree
struct Node* buildTree(int pre[], int in[], int inStart, int inEnd, int* preIdx, int n) {
    if (inStart > inEnd) return NULL;

    // The first element in preorder is the root
    struct Node* root = newNode(pre[(*preIdx)++]);

    // Find the index of this root in the inorder array
    int inIdx;
    for (int i = inStart; i <= inEnd; i++) {
        if (in[i] == root->data) {
            inIdx = i;
            break;
        }
    }

    // Build left and right subtrees
    root->left = buildTree(pre, in, inStart, inIdx - 1, preIdx, n);
    root->right = buildTree(pre, in, inIdx + 1, inEnd, preIdx, n);

    return root;
}

// Function to print postorder (Left, Right, Root)
void printPostorder(struct Node* root) {
    if (root == NULL) return;
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int pre[n], in[n];
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);

    int preIdx = 0;
    struct Node* root = buildTree(pre, in, 0, n - 1, &preIdx, n);

    printPostorder(root);
    printf("\n");

    return 0;
}