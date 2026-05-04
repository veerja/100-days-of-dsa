/*Problem: Given a target distance and cars’ positions & speeds, compute the number of car
fleets reaching the destination.
Sort cars by position in descending order and calculate time to reach target.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    double time;
} Car;

// Comparator to sort cars by position in descending order
int compareCars(const void* a, const void* b) {
    return ((Car*)b)->pos - ((Car*)a)->pos;
}

int carFleet(int target, int* position, int* speed, int n) {
    if (n == 0) return 0;

    Car* cars = (int*)malloc(n * sizeof(Car));
    for (int i = 0; i < n; i++) {
        cars[i].pos = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    // 1. Sort cars by position descending (closest to target first)
    qsort(cars, n, sizeof(Car), compareCars);

    int fleets = 0;
    double currentTimeLimit = 0.0;

    // 2. Iterate through cars
    for (int i = 0; i < n; i++) {
        // If this car takes more time than the current lead fleet,
        // it starts a new fleet because it can't catch up.
        if (cars[i].time > currentTimeLimit) {
            fleets++;
            currentTimeLimit = cars[i].time;
        }
        // Otherwise, it catches up and becomes part of the fleet ahead.
    }

    free(cars);
    return fleets;
}

int main() {
    int target = 12;
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};
    int n = 5;

    printf("Number of fleets: %d\n", carFleet(target, position, speed, n));
    // Output: 3
    return 0;
}
