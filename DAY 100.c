/*Problem: For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT).*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int original_idx;
} Element;

void merge(Element* arr, Element* temp, int* counts, int left, int mid, int right) {
    int i = left;    // Left half pointer
    int j = mid + 1; // Right half pointer
    int k = left;    // Temp array pointer
    int right_count = 0; // Number of elements from right half moved

    while (i <= mid && j <= right) {
        if (arr[j].val < arr[i].val) {
            // Element on right is smaller
            right_count++;
            temp[k++] = arr[j++];
        } else {
            // Element on left is smaller or equal
            // Add the current right_count to this element's total
            counts[arr[i].original_idx] += right_count;
            temp[k++] = arr[i++];
        }
    }

    // Process remaining elements
    while (i <= mid) {
        counts[arr[i].original_idx] += right_count;
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy back to original array
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(Element* arr, Element* temp, int* counts, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, temp, counts, left, mid);
        mergeSort(arr, temp, counts, mid + 1, right);
        merge(arr, temp, counts, left, mid, right);
    }
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* counts = (int*)calloc(numsSize, sizeof(int));
    Element* arr = (Element*)malloc(numsSize * sizeof(Element));
    Element* temp = (Element*)malloc(numsSize * sizeof(Element));

    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].original_idx = i;
    }

    mergeSort(arr, temp, counts, 0, numsSize - 1);

    free(arr);
    free(temp);
    return counts;
}

int main() {
    int nums[] = {5, 2, 6, 1};
    int n = 4, returnSize;
    int* result = countSmaller(nums, n, &returnSize);

    for (int i = 0; i < returnSize; i++) printf("%d ", result[i]);
    // Output: 2 1 1 0 

    free(result);
    return 0;
}
