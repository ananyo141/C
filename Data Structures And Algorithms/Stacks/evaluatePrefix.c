// Evaluate a prefix expression.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include "Stack(ADT)/stack.h"
#define ARRLEN 50

// Function declarations //
double evaluatePrefix(char prefix[]);
double operate(int operand1, char operator, int operand2);
int readline(char arr[], unsigned maxlen);

int main() {
    // Get prefix expression from user
    char prefixExp[ARRLEN];
    printf("Enter prefix expression: ");
    readline(prefixExp, ARRLEN);
    // Evaluate prefix expression
    double result = evaluatePrefix(prefixExp);
    printf("The result is: %g\n", result);

    return 0;
}

double evaluatePrefix(char prefix[]) {
    /* Evaluate a prefix expression
    and return the result */
    Stack opStack = initialize_stack();
    int op1, op2, len = 0;

    // Scan from end to start
    while (prefix[len]) len++;              // get the last index
    while (--len >= 0) {                    // and start from end
        // If operand, push to stack
        if (isdigit(prefix[len])) {         // extract the full number
            int num = 0, dig = 0;
            while (len >= 0 && isdigit(prefix[len]))
                num += (prefix[len--] - '0') * pow(10, dig++);
            push(opStack, num);
        } 
        if (len < 0) break;
        // If operator, pop, operate and push
        if (strchr("%/*+-", prefix[len])) {
            op1 = pop(opStack);
            op2 = pop(opStack);
            push(opStack, operate(op1, prefix[len], op2));
        }
    }

    // Last remaining number is the result
    double result = pop(opStack);
    if (!isempty(opStack)) {
        fprintf(stderr, "Invalid expression\n");
        exit(EXIT_FAILURE);
    }
    free(opStack);
    return result;
}

double operate(int op1, char operator, int op2) {
    /* Operate on operand1 and operand2 with operator and return
    the result */
    switch(operator) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / (double)op2;
        case '%': return op1 % op2;
        default : fprintf(stderr, "Invalid Operator\n");
                  return INT_MIN;
    }
}

int readline(char arr[], unsigned maxlen) {
    /* Read a line from stdin */
    int inp, len = 0;
    while ((inp = getchar()) != '\n')
        if (len < maxlen - 1)
            arr[len++] = inp;
    arr[len] = '\0';
    return len;
}

