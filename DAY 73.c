/*Problem Statement
Given a string s consisting of lowercase English letters, 
find and return the first character that does not repeat in the string. 
If all characters repeat, return '$'.

Input Format
A single string s.

Output Format
Print the first non-repeating character or '$' if none exists.

Sample Input
geeksforgeeks

Sample Output
f

Explanation
The character 'f' occurs only once in the string and appears before any other 
non-repeating character.
*/
#include <stdio.h>
#include <string.h>

char firstNonRepeating(char* s) {
    int count[26] = {0};
    int n = strlen(s);

    // First pass: Build the frequency map
    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
    }

    // Second pass: Find the first character with frequency 1
    for (int i = 0; i < n; i++) {
        if (count[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    return '$';
}

int main() {
    char s[100000]; // Assuming a reasonable maximum length
    if (scanf("%s", s) == 1) {
        printf("%c\n", firstNonRepeating(s));
    }
    return 0;
}