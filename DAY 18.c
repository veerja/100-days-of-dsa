#include <stdio.h>

int main()
{
    int n,i,k;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n] , rotated[n];
    printf("Enter %d numbers: ", n);
    for (i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    printf ("Enter number of positions rotated(k): ");
    scanf ("%d", &k);
    k=k%n;
    for (i=0;i<n;i++){
        rotated[(i+k)%n] =arr[i];
        
    }
printf ("Rotated array:");
for (i=0; i<n; i++) {
        printf("%d ", rotated[i]);
    }
    return 0;
}
