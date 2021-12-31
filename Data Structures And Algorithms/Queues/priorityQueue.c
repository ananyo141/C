// Implement a Priority Queue using linked list

#include <stdio.h>
#include <stdlib.h>

// Node Structure //
typedef struct node {
    int data;
    int priority;
    struct node *next;
} Node;

// Queue Structure //
typedef struct queue {
    Node *head;
} *Queue;

static void terminate(const char *msg) {
    /* Terminate with message */
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

// Prototypes //
Queue initialize_queue ();
void insert_queue (Queue);
void delete_queue (Queue);
void display_queue(Queue);

int main() {
    int choice;
    void (*commands[]) (Queue) = {insert_queue, delete_queue, 
                                  display_queue};
    Queue lqueue = initialize_queue();
    for (;;) {
        puts(   "******* Priority Queue ********\n"
                "1) Insert          2) Delete\n"
                "3) Display\n"
                "Command (-1 to exit):"
        );
        scanf("%d", &choice);
        system("clear");
        if (choice < 1 || choice > 3) {
            if (choice == -1) break;
            puts("Invalid Choice");
            continue;
        }
        puts("Output:");
        commands[choice-1](lqueue);
    }
    puts("Exit");
    return 0;
}

Queue initialize_queue() {
    /* Allocate memory for Queue */
    Queue new = malloc(sizeof(struct queue));
    if (new == NULL)
        terminate("Unable to allocate memory");
    new->head = NULL;
    return new;
}

void insert_queue(Queue lqueue) {
    /* Insert data and priority in the queue according
    to entered priority number */
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
        terminate("Unable to allocate memory");
    printf("Enter data and priority: ");
    while (scanf("%d%d", &newNode->data, &newNode->priority) != 2) {
        while (getchar() != '\n') 
            continue;
        puts("Unable to read data\n"
             "Input data and priority separated by space:");
    }
    Node **ptr = &(lqueue->head);
    while (*ptr && (*ptr)->priority <= newNode->priority)
        ptr = &(*ptr)->next;
    newNode->next = *ptr;
    *ptr = newNode;
}

void delete_queue(Queue lqueue) {
    /* Delete the highest priority entry from
    the queue */
    if (lqueue->head == NULL) {
        puts("Queue Underflow");
        return;
    }
    printf("Deleted: %d (P: %d)\n", lqueue->head->data,
                                    lqueue->head->priority);
    Node *toFree = lqueue->head;
    lqueue->head = lqueue->head->next;
    free(toFree);
}

void display_queue(Queue lqueue) {
    /* Display the queue contents */
    if (lqueue->head == NULL) {
        puts("Queue Underflow");
        return;
    }
    for (Node *ptr = lqueue->head; ptr; ptr=ptr->next)
        printf("| Data: %3d, Priority: %3d |\n", 
                      ptr->data, ptr->priority);
    putchar('\n');
}

