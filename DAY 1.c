/*roblem: Write a C program to insert an element x at a given 
1-based position pos in an array of n integers. Shift existing elements 
to the right to make space.

Input:
- First line: integer n
- Second line: n space-separated integers (the array)
- Third line: integer pos (1-based position)
- Fourth line: integer x (element to insert)

Output:
- Print the updated array (n+1 integers) in a single line, space-separated

Example:
Input:
5
1 2 4 5 6
3
3

Output:
1 2 3 4 5 6

Explanation: Insert 3 at position 3, elements [4,5,6] shift right.*/
#include <stdio.h>

int main() {
    int n, pos, x;

    // 1. Read the initial size
    if (scanf("%d", &n) != 1) return 0;

    // We create an array of size n+1 to accommodate the new element
    int arr[n + 1];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 2. Read position and element to insert
    scanf("%d", &pos);
    scanf("%d", &x);

    // Convert 1-based position to 0-based index
    int index = pos - 1;

    // 3. Shifting Logic
    // Move elements from the end of the array to the target index
    for (int i = n; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    // 4. Place the new element
    arr[index] = x;

    // 5. Print the updated array
    for (int i = 0; i <= n; i++) {
        printf("%d%s", arr[i], (i == n) ? "" : " ");
    }
    printf("\n");

    return 0;
}