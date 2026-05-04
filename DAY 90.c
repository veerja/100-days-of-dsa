/*Problem Statement
Given n boards of different lengths and k painters, each painter paints
contiguous boards. Painting a unit length of board takes one unit of time.

Determine the minimum time required to paint all boards.

Input Format
n k
n space-separated integers representing board lengths

Output Format
Print the minimum time required to paint all boards.

Sample Input
4 2
10 20 30 40

Sample Output
60

Explanation
One painter paints boards of length 10, 20, and 30 (total 60), while the other
paints board of length 40.*/
#include <stdio.h>

typedef long long ll;

// Check if it's possible to paint all boards within 'limit' time using 'k' painters
int isPossible(int boards[], int n, int k, ll limit) {
    int painters = 1;
    ll currentTime = 0;

    for (int i = 0; i < n; i++) {
        // If a single board is longer than the limit, it's impossible
        if (boards[i] > limit) return 0;

        if (currentTime + boards[i] > limit) {
            painters++;
            currentTime = boards[i];
            if (painters > k) return 0;
        } else {
            currentTime += boards[i];
        }
    }
    return 1;
}

ll paintersPartition(int boards[], int n, int k) {
    ll low = 0, high = 0;
    
    for (int i = 0; i < n; i++) {
        if (boards[i] > low) low = boards[i];
        high += boards[i];
    }

    ll ans = high;
    while (low <= high) {
        ll mid = low + (high - low) / 2;

        if (isPossible(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1; // Try to find a smaller maximum time
        } else {
            low = mid + 1; // Increase allowed time
        }
    }
    return ans;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int boards[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    printf("%lld\n", paintersPartition(boards, n, k));

    return 0;
}