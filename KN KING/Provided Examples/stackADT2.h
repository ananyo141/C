#ifndef STACK_ADT
#define STACK_ADT

#include <stdbool.h>

typedef int Item;   // use appropriate type in place of 'int' to have stacks of corresponding type
typedef struct stack_type *Stack;

Stack create(int size);
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, Item i);
Item pop(Stack s);

#endif
