#ifndef LINKED_QUEUE_H_
#define LINKED_QUEUE_H_

#include <stdbool.h>

// Node Structure //
typedef struct node {
    double data;
    struct node *next;
} Node;

// Queue Structure //
typedef struct queue {
    Node *front;
    Node *rear;
} *Queue;

// Stack Operations //
Queue initialize_queue();
void free_queue(Queue);
bool isempty(Queue);
bool isfull(Queue);
bool insert(Queue, double);
double del(Queue);
double peek(Queue);
void display(Queue);

#endif

