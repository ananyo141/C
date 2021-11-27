//3. Write a program to implement double stack.

#include <stdio.h>
#include <stdlib.h>

// Globals to manage stack positions //
static const int STACK_SIZE = 50;    // instead of #define, similar to cpp const with internal linkage
static int topA = 0;                 // top A is ahead-position, ie, the index next value will go to
static int topB = STACK_SIZE;        // top B is on-position, ie, the index the current value is in stack

// functions //
void pushA(double *);
void pushB(double *);
void popA (double *);
void popB (double *);
void peekA(double *);
void peekB(double *);
void displayA(double *);
void displayB(double *);

int main() {
    double stack[STACK_SIZE];
    int choice;
    void (*commands[]) (double *) = {pushA, pushB, popA, popB, peekA, 
                                     peekB, displayA, displayB};
    for (;;) {
        puts(
                "*********** DOUBLE STACK ************\n"
                "1) Push A                2) Push B\n"
                "3) Pop  A                4) Pop  B\n"
                "5) Peek A                6) Peek B\n"
                "7) Display A             8) Display B\n"
                "Command: (-1 to exit)"
        );
        if (!scanf("%d", &choice)) {               // if unable to read choice
            fprintf(stderr, "\nInvalid input\n");  // instead of hanging,
            exit(EXIT_FAILURE);                    // exit with failure status
        }
        system("clear");
        puts("Output:");
        if (choice > 8 || choice < 1) {
            if (choice == -1) break;
            puts("Invalid choice");
            continue;
        }
        commands[choice - 1](stack);
        putchar('\n');
    }
    puts("Exit");
    return 0;
}

void pushA(double *stack) {
    /* Push a value into stackA */
    if (topA == STACK_SIZE || topA == topB) {
        puts("Stack A Overflowed");
        return;
    }
    printf("Enter value: ");
    scanf("%lf", &stack[topA++]);
}

void pushB(double *stack) {
    /* Push a value into stackB */
    if (topB < 0 || topA == topB) {
        puts("Stack B Overflowed");
        return;
    }
    printf("Enter value: ");
    scanf("%lf", &stack[--topB]);
}
    
void popA(double *stack) {
    /* Pop value from stack A */
    if (!topA) 
        puts("Stack A Underflowed");
    else
        printf("Popped value from Stack A: %g\n", stack[--topA]);
}

void popB(double *stack) {
    /* Pop value from stack B */
    if (topB == STACK_SIZE)
        puts("Stack B Underflowed");
    else
        printf("Popped value from Stack B: %g\n", stack[topB++]);
}

void peekA(double *stack) {
    /* Peek the top value in stack A */
    if (!topA)
        puts("Stack A Empty");
    else
        printf("Stack A Top: %g\n", stack[topA-1]);
}

void peekB(double *stack) {
    /* Peek the top value in stack B */
    if (topB == STACK_SIZE)
        puts("Stack B Empty");
    else 
        printf("Stack B Top: %g\n", stack[topB]);
}

void displayA(double *stack) {
    /* Display stack A */
    if (!topA) {
        puts("Stack A Empty");
        return;
    }
    printf("Stack A Contents: ");
    for (int i = 0; i < topA; i++) 
        printf("%g ", stack[i]);
    putchar('\n');
}

void displayB(double *stack) {
    /* Display stack B */
    if (topB == STACK_SIZE) {
        puts("Stack B Empty");
        return;
    }
    printf("Stack B Contents: ");
    for (int i = STACK_SIZE-1; i >= topB; i--)
        printf("%g ", stack[i]);
    putchar('\n');
}

