//  IMPLEMENTATION - 2  (LINKED LIST VERSION) //
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct node {
    int data;
    struct node *next;  // pointer to the next structure
};

static struct node *top = NULL; // to keep track of the first structure in the linked list

static void terminate(const char *message) {
    puts(message);
    exit(EXIT_FAILURE);
}

void make_empty(void) {
    while (!is_empty())   // making just top = NULL won't cut it, there would be memory leak 
        pop();
}

bool is_empty(void) {
    return top == NULL;
}

bool is_full(void) {
    return false;
}

void push(int i) {
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) 
        terminate("Error in push: no memory left");
    // adding the new node in first of the list
    new_node->data = i;
    new_node->next = top;
    top = new_node;
}

int pop(void) {
    struct node *old_top;
    int i;

    if (is_empty())
        terminate("Error in pop: stack is empty.");
    // removing the node from top of the list
    old_top = top;
    i = top->data;
    top = top->next;
    free(old_top);
    return i;
}
