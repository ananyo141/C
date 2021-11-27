// 6. Write a program to convert an infix expression into postfix notation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "Stack(ADT)/stack.h"

// helper functions //
static bool popUptoBrkt(Stack);
static int  precedence(char);
static void terminate(const char *);

int main() {
    int inp;
    Stack opStack = initialize_stack();
    printf("Enter infix expression: ");

    // read input from console
    while ((inp = getchar()) != '\n') {
        // if char is a digit or operand, just print,
        if (isdigit(inp) || isalpha(inp))
            putchar(inp);
        // if char is (, mark and push into stack,
        else if (inp == '(')
            push(opStack, inp);
        // if char is ), unpack and print stack upto (,
        else if (inp == ')') {
            while (popUptoBrkt(opStack))
                putchar(pop(opStack));
            if (isempty(opStack))
                terminate("Invalid expression");
            pop(opStack);   // get rid of '('
        }
        // if char is operator, pop stack upto ( or while operator precedence of
        // stack is greater than current operator and push current operator to stack,
        else if (strchr("+-*/%", inp) != NULL) {
            while (popUptoBrkt(opStack) && precedence(peek(opStack)) > precedence(inp))
                putchar(pop(opStack));
            push(opStack, inp);
        }
    }
    // pop stack if anything left
    while (popUptoBrkt(opStack))
        putchar(pop(opStack));
    putchar('\n');

    return 0;
}

// Internal Functions //
bool popUptoBrkt(Stack arg_stack) {
    /* Validate if stack is non-empty and top element is not '(' */
    return (!isempty(arg_stack)) && (peek(arg_stack) != '(');
}
int precedence(char operator) {
    /* Return operator precedence, *%/ has higher than +- */
    if (strchr("*/%", operator) != NULL)
        return 1;
    else if (strchr("+-", operator) != NULL)
        return 0;
    else
        terminate("Unknown operator present");
}
void terminate(const char *message) {
    /* Terminate with error message */
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}

