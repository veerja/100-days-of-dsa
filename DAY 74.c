/*Problem Statement
Given an array of candidate names where each name represents a vote cast for
that candidate, determine the candidate who received the maximum number of votes. 
In case of a tie, return the lexicographically smallest candidate name.

Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.

Output Format
Print the name of the winning candidate followed by the number of votes received.

Sample Input
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

Sample Output
john 4

Explanation
Both john and johnny receive 4 votes, but john is lexicographically smaller, 
so john is declared the winner.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    int count;
} Candidate;

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    Candidate* votes = (Candidate*)malloc(n * sizeof(Candidate));
    int unique_candidates = 0;

    for (int i = 0; i < n; i++) {
        char temp_name[100];
        scanf("%s", temp_name);

        int found = 0;
        // Check if candidate already exists in our list
        for (int j = 0; j < unique_candidates; j++) {
            if (strcmp(votes[j].name, temp_name) == 0) {
                votes[j].count++;
                found = 1;
                break;
            }
        }

        // If new candidate, add to list
        if (!found) {
            strcpy(votes[unique_candidates].name, temp_name);
            votes[unique_candidates].count = 1;
            unique_candidates++;
        }
    }

    // Determine the winner
    char winner[100];
    int max_votes = -1;

    for (int i = 0; i < unique_candidates; i++) {
        if (votes[i].count > max_votes) {
            max_votes = votes[i].count;
            strcpy(winner, votes[i].name);
        } else if (votes[i].count == max_votes) {
            // Tie-breaker: Lexicographical comparison
            if (strcmp(votes[i].name, winner) < 0) {
                strcpy(winner, votes[i].name);
            }
        }
    }

    printf("%s %d\n", winner, max_votes);

    free(votes);
    return 0;
}