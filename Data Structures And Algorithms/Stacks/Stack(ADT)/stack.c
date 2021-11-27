// Implementation file for Stack Datatype

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"
#define MAXSIZE 100

struct stack_adt {
    Item stack_arr[MAXSIZE];
    int top;
};

/* A function with internal linkage to handle corner cases */
static void terminate(const char *message) {
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}

Stack initialize_stack() {
    Stack p_stack = malloc(sizeof(struct stack_adt));
    if (p_stack == NULL)
        terminate("Unable to allocate memory for stack");
    p_stack->top = 0;
    return p_stack;
}
bool isfull(const Stack p_stack) {
    /* Return boolean T/F if the stack is full */
    return p_stack->top == MAXSIZE;
}
bool isempty(const Stack p_stack) {
    /* Return boolean T/F if the stack is empty */
    return p_stack->top == 0;
}
bool push(Stack p_stack, Item ins) {
    /* Push an item into the stack, return true if successful
       and false if unsuccessful */
    if (isfull(p_stack))
        return false;
    else 
        p_stack->stack_arr[p_stack->top++] = ins;
    return true;
}
Item pop(Stack p_stack) {
    /* Pop an item from stack and return */
    return p_stack->stack_arr[--p_stack->top];
}
Item peek(const Stack p_stack) {
    /* Display the topmost value of stack */
    if (isempty(p_stack))
        terminate("Stack already empty");
    return p_stack->stack_arr[p_stack->top-1];
}
void displayStack(const Stack p_stack) {
    /* Display the stack from first to last value */
    if (isempty(p_stack)) {
        puts("Stack empty");
        return;
    }
    for (int i = 0; i < p_stack->top; i++) 
        printf("%d ", p_stack->stack_arr[i]);
    putchar('\n');
}

