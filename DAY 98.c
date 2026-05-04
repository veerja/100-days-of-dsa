/*Problem: Given intervals, merge all overlapping ones.
Sort first, then compare with previous.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Comparator to sort by start time
int compareIntervals(const void* a, const void* b) {
    Interval* i1 = (Interval*)a;
    Interval* i2 = (Interval*)b;
    return i1->start - i2->start;
}

void mergeIntervals(Interval intervals[], int n) {
    if (n <= 0) return;

    // 1. Sort based on start time
    qsort(intervals, n, sizeof(Interval), compareIntervals);

    int index = 0; // Index of the last merged interval

    for (int i = 1; i < n; i++) {
        // 2. Check for overlap: current start <= last merged end
        if (intervals[i].start <= intervals[index].end) {
            // Merge: update end time to the furthest end
            intervals[index].end = MAX(intervals[index].end, intervals[i].end);
        } else {
            // No overlap: move to the next slot in the array and update it
            index++;
            intervals[index] = intervals[i];
        }
    }

    // 3. Print the merged intervals
    printf("Merged Intervals:\n");
    for (int i = 0; i <= index; i++) {
        printf("[%d, %d] ", intervals[i].start, intervals[i].end);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of intervals: ");
    if (scanf("%d", &n) != 1) return 0;

    Interval* intervals = (Interval*)malloc(n * sizeof(Interval));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    mergeIntervals(intervals, n);

    free(intervals);
    return 0;
}