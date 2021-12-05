// Evaluate a postfix expression

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "Stack(ADT)/stack.h"

int operate(int op1, char operator, int op2);

int main() {
    Stack opStack = initialize_stack();
    int inp, num, op1, op2;

    puts("Enter postfix expression to evaluate:");
    // Read input from console
    for (;;) {
        inp = getchar();
        // If input is operand, push to stack
        if (isdigit(inp)) {
            num = 0;
            // extract the full number
            while (isdigit(inp)) {
                num = (num * 10) + (inp - '0');  // convert ascii to num value
                inp = getchar();
            }
            push(opStack, num);
        }
        // If input is operator, pop the lastest
        // 2 operands and operate on them, and push
        // result to stack
        if (strchr("+-*/%", inp)) {
            op2 = pop(opStack);
            op1 = pop(opStack);
            push(opStack, operate(op1, inp, op2));
        }
        if (inp == '\n') break;
    }

    int result = pop(opStack);
    if (!isempty(opStack)) {            // if value remains, given
        puts("Invalid expression");     // operator-operands don't match
        return 1;
    }
    printf("The result of the postfix expression is: %d\n", result);

    return 0;
}

int operate(int op1, char operator, int op2) {
    /* Operate on op1 and op2 by the given operand in string form */
    switch (operator) {
        case '+': return op1 + op2;      break;
        case '-': return op1 - op2;      break;
        case '*': return op1 * op2;      break;
        case '/': return op1 / op2;      break;
        case '%': return op1 % op2;      break;
    }
    fprintf(stderr, "Unknown Operator: %c\n", operator);
    return INT_MIN;
}

