// Queue with linked list implementation

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "linkedQueue.h"

// wrapper functions //
void insertQueue(Queue);
void deleteFrom(Queue);
void peekQueue(Queue);
void displayQueue(Queue);

int main() {
    int option;
    Queue pqueue = initialize_queue();
    void (*commands[]) (Queue) = {insertQueue, deleteFrom,
                                  peekQueue, display};
    for (;;) {
        puts(
                "******* Linked Queue ********\n"
                "1) Insert            2) Delete\n"
                "3) Peek              4) Display\n"
                "Command (-1 to quit):"
        );
        scanf("%d", &option);
        system("clear");
        puts("Output:");
        if (option < 1 || option > 4) {
            if (option == -1) break;
            puts("Invalid command");
            continue;
        }
        commands[option-1](pqueue);
        puts("Operation Successful\n");
    }
    puts("Exit");
    free_queue(pqueue);

    return 0;
}

// definitions //
void insertQueue(Queue pqueue) {
    double val;
    printf("Enter value: ");
    scanf("%lf", &val);
    insert(pqueue, val);
}

void deleteFrom(Queue pqueue) {
    double val;
    if ((val = del(pqueue)) == -DBL_MAX) {
        puts("Queue empty");
    }
    else
        printf("Deleted: %g\n", val);
}

void peekQueue(Queue pqueue) {
    double val;
    if ((val = peek(pqueue)) == -DBL_MAX) {
        puts("Queue empty");
    }
    else
        printf("Peek: %g\n", val);
}

