/*Problem: Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

// Comparator for sorting meetings by start time
int compareIntervals(const void* a, const void* b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

// Simple Min-Heap implementation for end times
void heapifyUp(int heap[], int idx) {
    while (idx > 0 && heap[idx] < heap[(idx - 1) / 2]) {
        int temp = heap[idx];
        heap[idx] = heap[(idx - 1) / 2];
        heap[(idx - 1) / 2] = temp;
        idx = (idx - 1) / 2;
    }
}

void heapifyDown(int heap[], int size, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;

    if (smallest != idx) {
        int temp = heap[idx];
        heap[idx] = heap[smallest];
        heap[smallest] = temp;
        heapifyDown(heap, size, smallest);
    }
}

int minMeetingRooms(Interval intervals[], int n) {
    if (n == 0) return 0;

    // 1. Sort by start time
    qsort(intervals, n, sizeof(Interval), compareIntervals);

    // 2. Min-Heap to store end times
    int* heap = (int*)malloc(n * sizeof(int));
    int heapSize = 0;

    // Push the first meeting's end time
    heap[heapSize++] = intervals[0].end;

    for (int i = 1; i < n; i++) {
        // If the current meeting starts after the earliest ending meeting
        if (intervals[i].start >= heap[0]) {
            // Reuse room: remove old end time
            heap[0] = heap[--heapSize];
            heapifyDown(heap, heapSize, 0);
        }
        
        // Add current meeting's end time to heap
        heap[heapSize++] = heap[heapSize - 1]; // Placeholder
        heap[heapSize - 1] = intervals[i].end;
        heapifyUp(heap, heapSize - 1);
    }

    free(heap);
    return heapSize;
}

int main() {
    int n;
    scanf("%d", &n);
    Interval* intervals = (Interval*)malloc(n * sizeof(Interval));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    printf("%d\n", minMeetingRooms(intervals, n));

    free(intervals);
    return 0;
}