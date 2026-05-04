/*Problem: BST Search

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

// Create a new BST node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Insert function to build the tree
struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// THE SEARCH FUNCTION
struct Node* search(struct Node* root, int x) {
    // Base Case: root is null or data is found
    if (root == NULL || root->data == x) {
        return root;
    }

    // Value is greater than root's data
    if (x > root->data) {
        return search(root->right, x);
    }

    // Value is smaller than root's data
    return search(root->left, x);
}

int main() {
    int n, val, target;
    struct Node* root = NULL;

    // Input: Number of elements and the elements themselves
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    // Input: Value to search for
    scanf("%d", &target);

    struct Node* result = search(root, target);

    if (result != NULL) {
        printf("Found: %d\n", result->data);
    } else {
        printf("Not Found\n");
    }

    return 0;
}