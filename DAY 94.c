/*Problem: Sort array of non-negative integers using counting sort.
Find max, build freq array, compute prefix sums, build output.*/
#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {
    if (n <= 1) return;

    // 1. Find the maximum element to define the range
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }

    // 2. Create and initialize frequency array
    int *count = (int *)calloc(max + 1, sizeof(int));
    int *output = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // 3. Compute Prefix Sums (Cumulative count)
    // This gives the ending position for each element
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // 4. Build the output array
    // We iterate backwards to ensure the sort is STABLE
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // 5. Copy output back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(count);
    free(output);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    countingSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");

    free(arr);
    return 0;
}
