/*Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
Distribute into buckets, sort each, concatenate.*/
#include <stdio.h>
#include <stdlib.h>

// Node for the linked list in each bucket
struct Node {
    double data;
    struct Node* next;
};

// Function to sort a linked list using Insertion Sort
struct Node* insertionSort(struct Node* head) {
    if (!head || !head->next) return head;
    
    struct Node* sorted = NULL;
    struct Node* curr = head;
    
    while (curr) {
        struct Node* next = curr->next;
        if (!sorted || sorted->data >= curr->data) {
            curr->next = sorted;
            sorted = curr;
        } else {
            struct Node* temp = sorted;
            while (temp->next && temp->next->data < curr->data) {
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
        }
        curr = next;
    }
    return sorted;
}

void bucketSort(double arr[], int n) {
    // 1. Create n empty buckets
    struct Node** buckets = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) buckets[i] = NULL;

    // 2. Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i]; // Bucket index
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = buckets[bi];
        buckets[bi] = newNode;
    }

    // 3. Sort individual buckets and concatenate
    int index = 0;
    for (int i = 0; i < n; i++) {
        buckets[i] = insertionSort(buckets[i]);
        
        struct Node* curr = buckets[i];
        while (curr) {
            arr[index++] = curr->data;
            struct Node* temp = curr;
            curr = curr->next;
            free(temp); // Clean up memory
        }
    }
    free(buckets);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    double* arr = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }

    bucketSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%.4f%s", arr[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");

    free(arr);
    return 0;
}