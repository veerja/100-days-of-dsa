/*Problem Statement
Given an array of integers where each element represents the number of
pages in a book, and m students, allocate books such that each student gets at
least one book and the maximum number of pages assigned to a student is minimized.

Books must be allocated in contiguous order.

Input Format
n m
n space-separated integers representing pages in books

Output Format
Print the minimum possible value of the maximum pages assigned to any student.

Sample Input
4 2
12 34 67 90

Sample Output
113

Explanation
One optimal allocation is:
Student 1: 12 + 34 + 67 = 113
Student 2: 90
Maximum pages = 113 (minimum possible).*/
#include <stdio.h>

typedef long long ll;

int isPossible(int arr[], int n, int m, ll maxPages) {
    int students = 1;
    ll currentSum = 0;

    for (int i = 0; i < n; i++) {
        // If a single book is larger than the limit, it's impossible
        if (arr[i] > maxPages) return 0;

        if (currentSum + arr[i] > maxPages) {
            students++;
            currentSum = arr[i];
            if (students > m) return 0;
        } else {
            currentSum += arr[i];
        }
    }
    return 1;
}

ll allocateBooks(int arr[], int n, int m) {
    if (m > n) return -1; // More students than books

    ll low = 0, high = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > low) low = arr[i];
        high += arr[i];
    }

    ll ans = high;
    while (low <= high) {
        ll mid = low + (high - low) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1; // Try to minimize the maximum
        } else {
            low = mid + 1; // Increase the limit
        }
    }
    return ans;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%lld\n", allocateBooks(arr, n, m));

    return 0;
}