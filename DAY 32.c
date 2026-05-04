/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10*/
#include <stdio.h>

#define MAX 1000

int main() {
    int n, m;
    int stack[MAX];
    int top = -1;

    // 1. Read number of elements to push
    if (scanf("%d", &n) != 1) return 0;

    // 2. Push elements onto the stack
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        if (top < MAX - 1) {
            stack[++top] = val;
        }
    }

    // 3. Read number of pops
    scanf("%d", &m);

    // 4. Perform pop operations
    for (int i = 0; i < m; i++) {
        if (top >= 0) {
            top--;
        }
    }

    // 5. Print remaining elements from top to bottom
    if (top == -1) {
        // Stack is empty
        return 0;
    }

    for (int i = top; i >= 0; i--) {
        printf("%d%s", stack[i], (i == 0) ? "" : " ");
    }
    printf("\n");

    return 0;
}
