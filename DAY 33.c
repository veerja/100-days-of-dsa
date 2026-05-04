/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to return precedence of operators
int precedence(char ch) {
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return 0;
}

void infixToPostfix(char* exp) {
    char stack[100];
    int top = -1;
    int len = strlen(exp);

    for (int i = 0; i < len; i++) {
        char c = exp[i];

        // 1. If operand, print it
        if (isalnum(c)) {
            printf("%c", c);
        }
        // 2. If '(', push to stack
        else if (c == '(') {
            stack[++top] = c;
        }
        // 3. If ')', pop until '('
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                printf("%c", stack[top--]);
            }
            top--; // Pop '('
        }
        // 4. If operator
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                printf("%c", stack[top--]);
            }
            stack[++top] = c;
        }
    }

    // 5. Pop remaining operators
    while (top != -1) {
        printf("%c", stack[top--]);
    }
    printf("\n");
}

int main() {
    char exp[100];
    scanf("%s", exp);
    infixToPostfix(exp);
    return 0;
}
