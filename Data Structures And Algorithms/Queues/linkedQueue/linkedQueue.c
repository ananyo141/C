// Implementation for linked queue

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "linkedQueue.h"

static void terminate(const char *msg) {
    /* Terminate with error message (internal
    function) */
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

bool isempty(Queue lqueue) {
    /* Return if the queue is empty */
    return (lqueue->front == NULL);
}

bool isfull(Queue lqueue) {
    /* Return if the queue is full (Current
    Linked list implementation should not be full) */
    return false;
}

Queue initialize_queue() {
    /* Allocate and initialize queue structure */
    Queue new = malloc(sizeof(struct queue));
    if (new == NULL)
        terminate("Unable to allocate memory");
    new->front = new->rear = NULL;
    return new;
}

void free_queue(Queue lqueue) {
    /* Free total dynamically allocated memory
    of the nodes and queue */
    Node *temp, *ptr = lqueue->front;
    while (ptr) {
        temp = ptr->next;
        free(ptr);
        ptr = temp;
    }
    free(lqueue);
}

bool insert(Queue lqueue, double val) {
    /* Insert a node at the rear of the queue */
    Node *currNode = malloc(sizeof(Node));
    if (currNode == NULL) return false;

    currNode->data = val;
    currNode->next = NULL;
    if (lqueue->rear)
        lqueue->rear->next = currNode;
    else
        lqueue->front = currNode;
    lqueue->rear = currNode;
    return true;
}

double del(Queue lqueue) {
    /* Delete a node from the front of 
    the queue */
    if (isempty(lqueue))
        return -DBL_MAX;
    double val = lqueue->front->data;
    Node *next = lqueue->front->next;
    free(lqueue->front);
    lqueue->front = next;
    if (next == NULL) lqueue->rear = NULL;
    return val;
}

double peek(Queue lqueue) {
    /* Return the top value of the queue */
    if (lqueue->front == NULL)
        return -DBL_MAX;
    return lqueue->front->data;
}

void display(Queue lqueue) {
    /* Display the queue */
    if (lqueue->front == NULL) {
        puts("Queue Empty");
        return;
    }
    for (Node *ptr=lqueue->front; ptr; ptr=ptr->next)
        printf("%g ", ptr->data);
    putchar('\n');
}

