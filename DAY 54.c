/*Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. 
Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order

Example:
Input:
7
1 2 3 4 5 6 7

Output:
1 3 2 4 5 6 7

Explanation:
Level 1 is printed left-to-right, level 2 right-to-left, and so on*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Build tree from level-order input array
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node* q[n];
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

void printZigzag(struct Node* root, int n) {
    if (!root) return;

    struct Node* queue[n];
    int front = 0, rear = 0;
    queue[rear++] = root;

    bool leftToRight = true;

    while (front < rear) {
        int levelSize = rear - front;
        int levelData[levelSize];

        for (int i = 0; i < levelSize; i++) {
            struct Node* curr = queue[front++];
            
            // Determine position in the temporary level array
            int index = leftToRight ? i : (levelSize - 1 - i);
            levelData[index] = curr->data;

            if (curr->left) queue[rear++] = curr->left;
            if (curr->right) queue[rear++] = curr->right;
        }

        // Print the processed level
        for (int i = 0; i < levelSize; i++) {
            printf("%d ", levelData[i]);
        }
        
        // Toggle the direction for the next level
        leftToRight = !leftToRight;
    }
    printf("\n");
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    printZigzag(root, n);

    return 0;
}