/*Problem: Polynomial Using Linked List - Implement using 
linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50

Explanation:
Each node stores coefficient and exponent. Traverse nodes to 
print polynomial in decreasing exponent order.*/

#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coeff;
    int exp;
    struct Term* next;
};

struct Term* createTerm(int c, int e) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coeff = c;
    newTerm->exp = e;
    newTerm->next = NULL;
    return newTerm;
}

void printPolynomial(struct Term* head) {
    struct Term* curr = head;
    while (curr != NULL) {
        // 1. Print Coefficient
        printf("%d", curr->coeff);

        // 2. Print Variable and Exponent
        if (curr->exp > 0) {
            printf("x");
            if (curr->exp > 1) {
                printf("^%d", curr->exp);
            }
        }

        // 3. Print " + " if there's another term following
        if (curr->next != NULL) {
            printf(" + ");
        }
        
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    int n, c, e;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    struct Term *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        struct Term* newTerm = createTerm(c, e);
        
        if (head == NULL) {
            head = tail = newTerm;
        } else {
            tail->next = newTerm;
            tail = newTerm;
        }
    }

    printPolynomial(head);

    return 0;
}
