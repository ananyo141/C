//4. Write a program to reverse a list of numbers using stack

#include <stdio.h>
#include <float.h>
#include <assert.h>
#include <stdbool.h>
#define STACK_SIZE 5

// Stack //
double numStack[STACK_SIZE];
int top = 0;

// Stack Functions //
bool isempty(void);
bool push(double);
double pop(void);

int main() {
    puts("Enter numbers (comma/space separated):");
    double inputVal;
    for (;;) {
        scanf("%lf", &inputVal);
        if (!push(inputVal)) {
            puts("\n********* Stack Overflowed ***********");
            break;
        }
        if (getchar() == '\n') break;
    }
    puts("The numbers reversed:");
    while (!isempty())
        printf("%g ", pop());
    putchar('\n');

    return 0;
}

// Stack Function Definitions //
bool isempty(void) {
    assert(top >= 0);         // assert len is always positive
    return !top;              // if len is zero, stack empty, else exists
}
bool push(double val) {
    if (top == STACK_SIZE)    // if stack is overflowed,
        return false;
    numStack[top++] = val;
    return true;
}
double pop(void) {
    if (isempty())
        return -DBL_MAX;      // return the lowest possible double value in case
    return numStack[--top];   // of failure to pop empty stack
}

