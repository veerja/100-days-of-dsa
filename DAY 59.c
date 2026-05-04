/*Problem Statement:
Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree

Example:
Input:
5
4 2 5 1 3
4 5 2 3 1

Output:
1 2 4 5 3

Explanation:
Postorder gives root at end, inorder divides left and right subtrees.*/
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
struct Node* buildTree(int in[], int post[], int inStart, int inEnd, int* postIdx) {
    if (inStart > inEnd) return NULL;

    // The last element in postorder is the root
    int currVal = post[(*postIdx)--];
    struct Node* root = newNode(currVal);

    // Find the index of this root in the inorder array
    int inIdx;
    for (int i = inStart; i <= inEnd; i++) {
        if (in[i] == currVal) {
            inIdx = i;
            break;
        }
    }

    // IMPORTANT: Build Right subtree before Left subtree
    root->right = buildTree(in, post, inIdx + 1, inEnd, postIdx);
    root->left = buildTree(in, post, inStart, inIdx - 1, postIdx);

    return root;
}

// Function to print preorder (Root, Left, Right)
void printPreorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int in[n], post[n];
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    for (int i = 0; i < n; i++) scanf("%d", &post[i]);

    int postIdx = n - 1;
    struct Node* root = buildTree(in, post, 0, n - 1, &postIdx);

    printPreorder(root);
    printf("\n");

    return 0;
}