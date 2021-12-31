// Implement insert, delete, display in circular queue using 
// array.

#include <stdio.h>
#include <stdlib.h>
#define MAX 7
// A Simple Debugger (logs to stderr) //
#define DEBUG(elem,type) fprintf(stderr, #elem " = " type "\n", elem); \
                         fflush(stderr)
#undef  DEBUG       // finalize and disable
#define DEBUG(x,y)  // logging after completion
#define INC(x) (((x) + 1) % MAX)    // increment and warp as required
#define DEC(x) (((x) - 1) % MAX)    // decrement and warp as required

// Circular Queue structure //
typedef struct circular_queue {
    double arr[MAX];
    int front;
    int rear;
} *Queue;

// Circular Queue Functions //
Queue initialize_queue();
int isempty(Queue);
int isfull(Queue);
void insert(Queue);
void delete(Queue);
void display(Queue);

int main() {
    int choice;
    Queue cqueue = initialize_queue();
    for (;;) {
        puts(
                "********* Circular Queue *******\n"
                "1) Insert          2) Delete\n"
                "3) Display         4) Exit\n"
                "Command:"
        );
        scanf("%d", &choice);
        system("clear");
        puts("Output:");
        switch(choice) {
            case 1: insert(cqueue);  break;
            case 2: delete(cqueue);  break;
            case 3: display(cqueue); break;
            case 4: goto exit;
            default: puts("Invalid choice");
        }
        puts("Operation Successful");
    }
    exit:
    free(cqueue);
    puts("Exit");

    return 0;
}

// Definitions //
Queue initialize_queue() {
    /* Initialize a queue using heap
    memory */
    Queue new = malloc(sizeof(struct circular_queue));
    if (new == NULL) {
        fprintf(stderr, "Unable to allocate memory for queue\n");
        exit(EXIT_FAILURE);
    }
    new->front = 0; // initial positions don't matter as the 
    new->rear  = 1; // queue is circular and can warp around,
    return new;     // but is important for full and empty logic
}

int isempty(Queue cqueue) {
    /* Check if the queue is empty
    (if next position from front is rear,
    queue is empty) */
    return INC(cqueue->front) == cqueue->rear;  // next position from front
}                                               // is rear

int isfull(Queue cqueue){
    /* Check if the queue is full
    (if previous position from front is rear,
    queue is full) */
    return INC(cqueue->rear) == cqueue->front;  // or rear next is front
}

void insert(Queue cqueue) {
    /* Insert element into queue */
    DEBUG(cqueue->front, "%d");
    DEBUG(cqueue->rear, "%d");
    if (isfull(cqueue)) {
        puts("Queue Overflow");
        return;
    }
    double val;
    printf("Enter value: ");
    scanf("%lf", &val);
    cqueue->arr[cqueue->rear] = val;    // insert at rear,
    cqueue->rear = INC(cqueue->rear);   // increment rear
}

void delete(Queue cqueue){
    /* Delete from the queue */
    DEBUG(cqueue->front, "%d");
    DEBUG(cqueue->rear, "%d");
    if (isempty(cqueue)) {
        puts("Queue Underflow");
        return;
    }
    cqueue->front = INC(cqueue->front);                  // increment front to get
    printf("Deleted: %g\n", cqueue->arr[cqueue->front]); // value from position
}

void display(Queue cqueue) {
    /* Display the contents of queue */
    DEBUG(cqueue->front, "%d");
    DEBUG(cqueue->rear, "%d");
    if (isempty(cqueue)) {
        puts("Queue Underflow");
        return;
    }
    for (int i = INC(cqueue->front); i != cqueue->rear; i = INC(i))
        printf("%g ", cqueue->arr[i]);
    putchar('\n');
}

