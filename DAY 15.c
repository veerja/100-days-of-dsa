#include <stdio.h>

int main() {
    int m, n;
    
    
    if (scanf("%d %d", &m, &n) != 2) return 0;

    int matrix[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    
    long long sum = 0;
    
    
    int size = (m < n) ? m : n;
    
    for (int i = 0; i < size; i++) {
        sum += matrix[i][i];
    }

    
    printf("%lld\n", sum);

    return 0;
}