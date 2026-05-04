/*Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)

Output:
- Print the transformed code name after applying the mirror operation

Example:
Input:
hello

Output:
olleh

Explanation: The first character moves to the last position, 
the second to the second-last, and so on until the entire string is mirrored*/
#include <stdio.h>

int main() {
    char s[100];

    
    if (scanf("%s", s) != 1) return 0;


    int n = 0;
    while (s[n] != '\0') {
        n++;
    }


    int left = 0;
    int right = n - 1;

    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }


    printf("%s\n", s);

    return 0;
}