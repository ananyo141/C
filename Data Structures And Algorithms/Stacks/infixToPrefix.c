// Convert infix to prefix expression

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Stack(ADT)/stack.h"
#define ARRSIZE 80

// function prototypes //
void infixToPostfix(char expStr[], char resStr[]);
void reverseExp(char expStr[]);
int readline(char arr[], unsigned maxlen);
static int getUptoBrkt(Stack opStack);
static int precedence (char operator);
static void terminate (char *message);

int main() {
    char infixExpression  [ARRSIZE], 
         postfixExpression[ARRSIZE],
         prefixExpression [ARRSIZE];
    // Capture the infix expression
    puts("Enter the infix expression:");
    readline(infixExpression, ARRSIZE);

    infixToPostfix(infixExpression, postfixExpression);
    puts("The postfix expression is:");
    puts(postfixExpression);

    // Reverse expression interchanging brackets
    reverseExp(infixExpression);
    // Convert infix to postfix
    infixToPostfix(infixExpression, prefixExpression);
    // Reverse expression interchanging brackets
    // to get final prefix expression
    reverseExp(prefixExpression);

    puts("The converted prefix expression is:");
    puts(prefixExpression);

    return 0;
}

int precedence(char operator) {
    /* Get the precedence of operators */
    return operator == '+' || operator == '-'
           ? 0 
           : 1;
}

int getUptoBrkt(Stack opStack) {
    /* Return if nearest bracket approached and 
    stack is not empty (auxillary test) */
    return (!isempty(opStack)) && (peek(opStack) != '(');
}

void infixToPostfix(char expStr[], char resStr[]) {
    /* Convert infix to postfix */
    int inp;
    Stack opStack = initialize_stack();
    while (inp = *expStr++) {
        // If character is operand, simply copy
        if (isalnum(inp))
            *resStr++ = inp;
        // if character is '(', push to stack
        else if (inp == '(')
            push(opStack, inp);
        // if character is ')', pop stack upto '(' and 
        // discard it
        else if (inp == ')') {
            while (getUptoBrkt(opStack)) 
                *resStr++ = pop(opStack);
            if (isempty(opStack))
                terminate("Invalid Expression");
            pop(opStack);
        }
        // if character is operator, pop upto '(' or while 
        // precedence of stacktop is greater than operator
        // and push to stack
        else if (strchr("+-/*", inp)) {
            while(getUptoBrkt(opStack) && 
                  precedence(peek(opStack)) >= precedence(inp))
                *resStr++ = pop(opStack);
            push(opStack, inp);
        }
    }
    // finally, pop remaining operators
    while (getUptoBrkt(opStack))
        *resStr++ = pop(opStack);
    *resStr = '\0';
    free(opStack);
}

void reverseExp(char expStr[]) {
    /* Reverse the expression while substituting
    '(' for ')' and ')' for '(' */
    int ch;
    Stack charStack = initialize_stack();
    for (char *ptr=expStr; *ptr; ptr++) {
        ch = *ptr;
        if      (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
        push(charStack, ch);
    }
    while (!isempty(charStack))
        *expStr++ = pop(charStack);
    *expStr = '\0';
    free(charStack);
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

static void terminate (char *message) {
    /* Terminate with error message */
    puts(message);
    exit(EXIT_FAILURE);
}

