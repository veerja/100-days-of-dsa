/*Problem: Implement a stack data structure using an array 
with the following operations: push, pop, and display.

Input:
- First line: integer n (number of operations)
- Next n lines: operation type and value (if applicable)
  - 1 value: push value
  - 2: pop
  - 3: display

Output:
- For display: print stack elements from top to bottom
- For pop: print popped element or 'Stack Underflow'

Example:
Input:
5
1 10
1 20
3
2
3

Output:
20 10
20
10*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000 // Maximum size of the stack

int stack[MAX];
int top = -1;

void push(int val) {
    if (top >= MAX - 1) {
        // Stack Overflow - though not required by prompt, good practice
        return;
    }
    stack[++top] = val;
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d\n", stack[top--]);
    }
}

void display() {
    if (top == -1) {
        return; // Empty stack display
    }
    for (int i = top; i >= 0; i--) {
        printf("%d%s", stack[i], (i == 0) ? "" : " ");
    }
    printf("\n");
}

int main() {
    int n, choice, value;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
        }
    }

    return 0;
}
