/*Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30*/
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
    
    // Bubble Up: Move element up to restore heap property
    while (curr > 0 && heap[(curr - 1) / 2] > heap[curr]) {
        swap(&heap[(curr - 1) / 2], &heap[curr]);
        curr = (curr - 1) / 2;
    }
}

void extractMin() {
    if (size == 0) {
        printf("-1\n");
        return;
    }
    
    printf("%d\n", heap[0]);
    
    // Replace root with the last element
    heap[0] = heap[size - 1];
    size--;
    
    // Bubble Down: Move element down to restore heap property
    int curr = 0;
    while (2 * curr + 1 < size) {
        int left = 2 * curr + 1;
        int right = 2 * curr + 2;
        int smallest = left;
        
        if (right < size && heap[right] < heap[left]) {
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
    if (scanf("%d", &n) != 1) return 0;
    
    char op[20];
    int val;
    
    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            scanf("%d", &val);
            insert(val);
        } else if (strcmp(op, "extractMin") == 0) {
            extractMin();
        } else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }
    
    return 0;
}

