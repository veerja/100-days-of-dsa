/*Problem Statement
Given n stalls located at different positions along a straight line and k 
cows, place the cows in the stalls such that the minimum distance between any 
two cows is maximized.

This is an optimization problem where binary search on the answer is required.

Input Format
n k
n space-separated integers representing stall positions

Output Format
Print the maximum possible minimum distance between any two cows.

Sample Input
5 3
1 2 8 4 9

Sample Output
3

Explanation
Cows can be placed at positions 1, 4, and 8. The minimum distance between any two 
cows is 3, which is the maximum possible.*/
#include <stdio.h>
#include <stdlib.h>

// Comparison function for sorting stall positions
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Check if it's possible to place k cows with at least 'dist' distance apart
int canPlace(int stalls[], int n, int k, int dist) {
    int count = 1; // Place the first cow
    int last_pos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - last_pos >= dist) {
            count++;
            last_pos = stalls[i];
            if (count >= k) return 1;
        }
    }
    return 0;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int stalls[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    // Step 1: Sort the stalls
    qsort(stalls, n, sizeof(int), compare);

    // Step 2: Binary search on the answer
    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlace(stalls, n, k, mid)) {
            ans = mid;      // This distance works, try to find a larger one
            low = mid + 1;
        } else {
            high = mid - 1; // Too large, try a smaller distance
        }
    }

    printf("%d\n", ans);

    return 0;
}