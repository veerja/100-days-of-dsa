/*Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards*/
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
    int isPalindrome = 1; 

    while (left < right) {
        if (s[left] != s[right]) {
            isPalindrome = 0; 
            break;
        }
        left++;
        right--;
    }


    if (isPalindrome) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}