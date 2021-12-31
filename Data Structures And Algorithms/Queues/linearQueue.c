// Write a menu driven program to implement Insert, Delete and 
// Display operations in a Linear Queue using array.
 
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

// Queue Data Type //
typedef struct queue {
    int arr[SIZE];
    int *front;
    int *rear;
} *Queue;

// Queue Functions //
Queue initialize_queue();
void insert (Queue);
void delete (Queue);
void display(Queue);
int  isempty(Queue);
int  isfull (Queue);


int main() {
    int choice;
    Queue queue = initialize_queue();
    void (*commands[]) (Queue) = {insert, delete, display};

    for (;;) {
        puts(
                "************ LINEAR QUEUE ************\n"
                "1) Insert                   2) Delete\n"
                "3) Display                  4) Exit\n"
                "Command:"
        );

        scanf("%d", &choice);
        system("clear");
        if (choice > 4 || choice < 1) {
            puts("Invalid Option");
            continue;
        } 
        if (choice == 4) break;
        puts("Output:");
        commands[choice-1](queue);
    }
    puts("Exit");

    return 0;
}

Queue initialize_queue() {
    /* Allocate memory for a Queue ADT */
    Queue new = malloc(sizeof(struct queue));
    if (new == NULL) {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    new->front = new->arr-1;
    new->rear  = new->arr;
    return new;
}

void insert (Queue queueStr) {
    /* Insert a value in tail of queue */
    if (isfull(queueStr)) {
        puts("Queue Overflow");
        return;
    }
    printf("Enter value to insert: ");
    scanf("%d", queueStr->rear++);
}

void delete (Queue queueStr) {
    /* Delete an element from the front of queue */
    if (isempty(queueStr)) {
        puts("Queue Underflow");
        return;
    }
    printf("Element Deleted: %d\n", *(++queueStr->front));
}

void display(Queue queueStr) {
    /* Display the contents of the queue */
    if (isempty(queueStr)) {
        puts("Queue Empty");
        return;
    }
    for (int *ptr=queueStr->front+1; ptr<queueStr->rear; ptr++)
        printf("%d ", *ptr);
    putchar('\n');
}

int isempty(Queue queueStr) {
    /* Return 1 if queue empty, 0 otherwise */
    return queueStr->front == queueStr->rear-1;
}

int isfull(Queue queueStr) {
    /* Return 1 if queue full, 0 otherwise */
    return queueStr->rear == queueStr->arr + SIZE;
}

