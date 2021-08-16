//  IMPLEMENTATION - 1  (ARRAY VERSION) //

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define STACK_SIZE 100

// this is the completion of the incomplete stack_type declaration (for encapsulation)
struct stack_type {
    int contents[STACK_SIZE];
    int top;
};

/* static storage class is used wherever information hiding is needed, 
for providing internal scope so that client file can't access those
functions or variables */
static void terminate(const char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

void make_empty(Stack *s) {
    s->top = 0;
}

bool is_empty(const Stack *s) {
    return  s->top == 0;
}

bool is_full(const Stack *s) {
    return s->top == STACK_SIZE;
}

void push(Stack *s, int i) {
    if (is_full(s)) 
        terminate("Error in push: stack is full.");
    s->contents[s->top++] = i;
}

int pop(Stack *s) {
    if (is_empty(s)) 
        terminate("Error in pop: Stack Empty.");
    return s->contents[--s->top];
}
