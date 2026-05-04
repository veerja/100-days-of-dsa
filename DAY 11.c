#include <stdio.h>

int main() {
    int m, n;
    
    
    if (scanf("%d %d", &m, &n) != 2) return 0;

    
    int A[m][n], B[m][n], C[m][n];
    int i, j;

    
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            printf("%d", C[i][j]);
            
            if (j < n - 1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}