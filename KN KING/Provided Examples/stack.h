#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#define STACK_SIZE 100

// stack type to create an instance of the stack object
typedef struct stack_type Stack; // using incomplete type

void make_empty(Stack *s);
bool is_empty(const Stack *s);
bool is_full(const Stack *s);
void push(Stack *s,int i);
int pop(Stack *s);

#endif
