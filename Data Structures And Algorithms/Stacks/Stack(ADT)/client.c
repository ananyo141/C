// Write a menu driven program to implement Push, Pop and Display functions in a Stack.

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/** Helper functions (interactive version) **/
void pushStack   (Stack);
void popStack    (Stack);
void isEmptyStack(Stack);
void isFullStack (Stack);
void peekStack   (Stack);

int main() {
    int choice;
    Stack progStack = initialize_stack();
    void (*operations[]) (Stack) = {pushStack, popStack, isEmptyStack, 
                                   isFullStack, peekStack, displayStack};
    for (;;) {
        puts(
            "********** STACK OPERATIONS ***********\n"
            "1) Push to Stack       2) Pop Stack\n"
            "3) Is empty            4) Is full\n"
            "5) Peek Stack Value    6) Display Stack\n"
            "Command: (-1 to exit)"
        );
        scanf("%d", &choice);
        system("clear");        // may need to use ("cls") for windows systems
        puts("Output:");
        if (choice > 7 || choice < 1) {
            if (choice == -1) break;
            puts("Invalid choice");
            continue;
        }
        operations[choice-1](progStack);
    }
    puts("Exit");
    return 0;
}

/* Function Definitions */
void pushStack(Stack p_stack) {
    /* Get user input to push data to stack */
    if (isfull(p_stack)) {
        puts("Stack already full");
        return;
    }
    int val;
    printf("Enter data to push: ");
    scanf("%d", &val);
    push(p_stack, val);
}
void popStack(Stack p_stack) {
    /* Pop data from stack and display to user */
    if (isempty(p_stack)) {
        puts("Stack already empty, unable to pop");
        return;
    }
    printf("Item popped %d\n", pop(p_stack));
}
void isEmptyStack(Stack p_stack) {
    /* Find and display if stack is empty */
    if (isempty(p_stack))
        puts("Stack is empty");
    else 
        puts("Stack is not empty");
}
void isFullStack(Stack p_stack) {
    /* Find and display if stack is full */
    if (isfull(p_stack)) 
        puts("Stack is full");
    else 
        puts("Stack is not full");
}
void peekStack(Stack p_stack) {
    /* Show the topmost value in the stack */
    if (isempty(p_stack)) {
        puts("Stack already empty, unable to peek");
        return;
    }
    printf("Topmost value in stack: %d\n", peek(p_stack));
}
