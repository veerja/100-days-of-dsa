/*
Problem: BST Insert

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

// Function to create a new BST node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a value into the BST
struct Node* insert(struct Node* root, int val) {
    // 1. If the tree is empty, return a new node
    if (root == NULL) {
        return newNode(val);
    }

    // 2. Otherwise, recur down the tree
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }

    // Return the (unchanged) node pointer
    return root;
}

// Helper: Inorder traversal to verify the BST (should print sorted)
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n, val;
    struct Node* root = NULL;

    // Read number of elements
    if (scanf("%d", &n) != 1) return 0;

    // Insert each element
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    // Print result
    inorder(root);
    printf("\n");

    return 0;
}