// Write a program that computes rpn expressions using a stack.
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define MAX_STACK_SIZE 20

int main() {
    int stack[MAX_STACK_SIZE];
    char *operators = "+-*/%%=";
    char c, top = 0;
    printf("Enter an RPN expression: ");
    for(;;) {
        scanf(" %c", &c);
        if (tolower(c) == 'q')
            break;
        if (isdigit(c)) {
            stack[top++] = c - '0';
            continue;
        }
        if (strchr(operators, c) == NULL)
            continue;
        top--;
        switch(c) {
            case '+': stack[top - 1] = stack[top - 1] + stack[top]; break;
            case '-': stack[top - 1] = stack[top - 1] - stack[top]; break;
            case '*': stack[top - 1] = stack[top - 1] * stack[top]; break;
            case '/': stack[top - 1] = stack[top - 1] / stack[top]; break;
            case '%': stack[top - 1] = fmod(stack[top - 1], stack[top]); break;
            case '=': printf("The value of the expression is %d\nEnter another RPN expression ('Q' to quit): ", stack[top]); break;
        }
    }
        
    return 0;
}