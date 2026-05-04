/**Problem Statement
Given an array of integers containing both positive and negative values,
find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.*/
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10007

typedef struct Node {
    int sum;
    int index;
    struct Node* next;
} Node;

Node* hash_table[TABLE_SIZE];

// Simple hash function for negative and positive sums
int hash(int sum) {
    int h = sum % TABLE_SIZE;
    return (h < 0) ? h + TABLE_SIZE : h;
}

void insert(int sum, int index) {
    int h = hash(sum);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->sum = sum;
    newNode->index = index;
    newNode->next = hash_table[h];
    hash_table[h] = newNode;
}

int find(int sum) {
    int h = hash(sum);
    Node* curr = hash_table[h];
    while (curr) {
        if (curr->sum == sum) return curr->index;
        curr = curr->next;
    }
    return -2; // Not found
}

int maxLen(int arr[], int n) {
    int max_len = 0;
    int curr_sum = 0;

    for (int i = 0; i < n; i++) {
        curr_sum += arr[i];

        if (curr_sum == 0) {
            max_len = i + 1;
        }

        int prev_idx = find(curr_sum);
        if (prev_idx != -2) {
            if (i - prev_idx > max_len) {
                max_len = i - prev_idx;
            }
        } else {
            // Only insert the first time a sum is seen to maximize length
            insert(curr_sum, i);
        }
    }
    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", maxLen(arr, n));
    return 0;
}
