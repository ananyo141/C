#ifndef STACK_H_
#define STACK_H_

#include <stdbool.h>

typedef int Item;
typedef struct stack_adt *Stack; // so it's easy to modify the
                                 // underlying stack datatype

Stack initialize_stack();
bool push(Stack, Item);
Item pop(Stack);
Item peek(const Stack);
bool isfull(const Stack);
bool isempty(const Stack);
void displayStack(const Stack);

#endif

