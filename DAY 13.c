/*Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.

Input:
- First line: two integers r and c representing the number of rows and columns
- Next r lines: c integers each representing the matrix elements

Output:
- Print all visited elements in the order of traversal, separated by spaces

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
1 2 3 6 9 8 7 4 5

Explanation:
The traversal begins along the top row, proceeds down the rightmost column, then moves across the bottom row in reverse, and finally goes up the leftmost column. The same pattern repeats for the inner submatrix.

Test Cases:

Test Case 1:
Input:
2 3
1 2 3
4 5 6
Output:
1 2 3 6 5 4

Test Case 2:
Input:
3 1
7
8
9
Output:
7 8 9*/
#include <stdio.h>

int main() {
    int r, c;
    
    // 1. Read rows and columns
    if (scanf("%d %d", &r, &c) != 2) return 0;

    int matrix[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // 2. Initialize boundaries
    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;
    int first = 1; // Helper to manage space between outputs

    while (top <= bottom && left <= right) {
        // Step A: Move Right along the top boundary
        for (int i = left; i <= right; i++) {
            if (!first) printf(" ");
            printf("%d", matrix[top][i]);
            first = 0;
        }
        top++;

        // Step B: Move Down along the right boundary
        for (int i = top; i <= bottom; i++) {
            printf(" %d", matrix[i][right]);
        }
        right--;

        // Step C: Move Left along the bottom boundary
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                printf(" %d", matrix[bottom][i]);
            }
            bottom--;
        }

        // Step D: Move Up along the left boundary
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf(" %d", matrix[i][left]);
            }
            left++;
        }
    }
    printf("\n");

    return 0;
}