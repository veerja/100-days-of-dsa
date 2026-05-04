/*Problem: Evaluate Postfix Expression - 
Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, 
push result back. Final stack top is result.*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Stack Node using Linked List
struct Node {
    int data;
    struct Node* next;
};

// Push operation
void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

// Pop operation
int pop(struct Node** top) {
    if (*top == NULL) return 0;
    struct Node* temp = *top;
    int val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}

int main() {
    char expression[100];
    // Read the entire line including spaces
    scanf("%[^\n]s", expression);

    struct Node* stack = NULL;
    char* token = strtok(expression, " ");

    while (token != NULL) {
        // If token is an operator
        if (strlen(token) == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
            int b = pop(&stack);
            int a = pop(&stack);

            switch (token[0]) {
                case '+': push(&stack, a + b); break;
                case '-': push(&stack, a - b); break;
                case '*': push(&stack, a * b); break;
                case '/': push(&stack, a / b); break;
            }
        } 
        // If token is a number
        else {
            push(&stack, atoi(token));
        }
        token = strtok(NULL, " ");
    }

    printf("%d\n", pop(&stack));

    return 0;
}
