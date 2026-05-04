/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller 
value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20*/
#include <stdio.h>
#include <string.h>

#define MAX 1000

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int val) {
    if (size >= MAX) return;
    
    heap[size] = val;
    int curr = size;
    size++;
    
    // Bubble Up
    while (curr > 0 && heap[(curr - 1) / 2] > heap[curr]) {
        swap(&heap[(curr - 1) / 2], &heap[curr]);
        curr = (curr - 1) / 2;
    }
}

void deleteMin() {
    if (size == 0) {
        printf("-1\n");
        return;
    }
    
    printf("%d\n", heap[0]);
    heap[0] = heap[size - 1];
    size--;
    
    // Bubble Down
    int curr = 0;
    while (2 * curr + 1 < size) {
        int smallest = 2 * curr + 1; // Left child
        int right = 2 * curr + 2;
        
        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }
        
        if (heap[curr] <= heap[smallest]) break;
        
        swap(&heap[curr], &heap[smallest]);
        curr = smallest;
    }
}

void peek() {
    if (size == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", heap[0]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    char op[10];
    int val;
    
    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            scanf("%d", &val);
            insert(val);
        } else if (strcmp(op, "delete") == 0) {
            deleteMin();
        } else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }
    
    return 0;
}