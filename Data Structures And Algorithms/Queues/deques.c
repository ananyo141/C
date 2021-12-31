// Implement Input and Output Restricted Deques

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5
#define DEBUG(elem,type) fprintf(stderr, #elem " = " type "\n", elem); \
                         fflush(stderr)
#undef  DEBUG
#define DEBUG(elem,type)

// Queue Structure //
typedef struct queue {
    double arr[MAX];
    int front;
    int rear;
} *Queue;

// Helper Functions //
static inline int INC(int x) {
    /* Increment x and return the result 
    within valid array range */
    return (x + 1) % MAX;
}

static inline int DEC(int x) {
    /* Decrement x and return the result
    within valid array range */
    int result;
    if ((result = x-1) < 0)    // if negative,
        result = MAX + result; // warp around 
    return result;
}

// Function Prototypes (Shared functions) //
Queue initialize_queue (void);
bool isempty(Queue);
bool isfull (Queue);
void insertRight (Queue);
void insertLeft  (Queue);
void deleteRight (Queue);
void deleteLeft  (Queue);
void displayQueue(Queue);
double getValue  (void);

// Wrapper for Input And Output Restricted Deques
void inputRestrictedDeque (void);
void outputRestrictedDeque(void);

// Error Messages and OS Specific Commands//
const char *OVERFLOW   = "Queue Overflowed";
const char *UNDERFLOW  = "Queue Underflowed";
const char *CLEAR_CODE = "clear";   // for *nix, require "cls" for windows

// Show Master Menu that gives option for inp/out restricted
// queue
int main() {
    int mainChoice;
    void (*deques[]) (void) = {inputRestrictedDeque, outputRestrictedDeque};
    for (;;) {
        puts(
                "********* DEQUES MAIN MENU ********\n"
                "1) Input Restricted Deques\n"
                "2) Output Restricted Deques\n"
                "Command (-1 to quit):"
        );
        scanf("%d", &mainChoice);
        system(CLEAR_CODE);
        if (mainChoice < 1 || mainChoice > 2) {
            if (mainChoice == -1) break;
            puts("Invalid Choice");
            continue;
        }
        deques[mainChoice-1]();
        puts("Operation Completed Successfully");
        putchar('\n');
    }

    return 0;
}

// Individual Menus // 
// (Each option provides and implements a submenu 
// for input and output restricted queues)
void inputRestrictedDeque(void) {
    /* Menu driven Input Restriced Deque */
    int inputChoice;
    Queue inputQ = initialize_queue();
    void (*inputCommands[]) (Queue) = {
        insertRight, deleteRight, deleteLeft, displayQueue
    };

    for (;;) {
        puts(
                "******* Input Restricted Deques *******\n"
                "1) Insert Right      2) Delete Right\n"
                "3) Delete Left       4) Display\n"
                "Command (-1 to quit):"
        );
        scanf("%d", &inputChoice);
        system(CLEAR_CODE);
        if (inputChoice < 1 || inputChoice > 4) {
            if (inputChoice == -1) break;
            puts("Invalid Choice");
            continue;
        }
        puts("Output:");
        inputCommands[inputChoice-1](inputQ);
        putchar('\n');
    }
    free(inputQ);
}

void outputRestrictedDeque(void) {
    /* Menu driven Output Restriced Deque */
    int outputChoice;
    Queue outputQ = initialize_queue();
    void (*outputCommands[]) (Queue) = {
        insertRight, insertLeft, deleteLeft, displayQueue
    };

    for (;;) {
        puts(
                "****** Output Restricted Deques *******\n"
                "1) Insert Right      2) Insert Left\n"
                "3) Delete Left       4) Display\n"
                "Command (-1 to quit):"
        );
        scanf("%d", &outputChoice);
        system(CLEAR_CODE);
        if (outputChoice < 1 || outputChoice > 4) {
            if (outputChoice == -1) break;
            puts("Invalid Choice");
            continue;
        }
        puts("Output:");
        outputCommands[outputChoice-1](outputQ);
        putchar('\n');
    }
    free(outputQ);
}

// Implementation //
double getValue(void) {
    /* Get value from the user, this assumes the value
    is type double */
    double val;
    printf("Enter value: ");
    scanf("%lf", &val);
    return val;
}

Queue initialize_queue(void) {
    /* Return a queue type dynamically created
    from heap */
    Queue new = malloc(sizeof(struct queue));
    if (new == NULL) {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    new->front = new->rear = -1;    // empty condition
    return new;
}

bool isempty(Queue cqueue) {
    /* Find if the queue is empty */
    return cqueue->front == -1 &&   // when both front and
           cqueue->rear  == -1;     // rear are -1
}

bool isfull(Queue cqueue) {
    /* Find if the queue is full */
    return cqueue->front != -1 &&         // when both front and rear
           cqueue->front == cqueue->rear; // are equal but not -1
}

void insertRight(Queue cqueue) {
    /* Ask and insert an element into the
    right (rear) side of the queue */
    DEBUG(cqueue->front, "%d");
    DEBUG(cqueue->rear,  "%d");
    if (isfull(cqueue)) {
        puts(OVERFLOW);
        return;
    }
    double val = getValue();
    if (isempty(cqueue))
        cqueue->front = cqueue->rear = 0;
    cqueue->arr[cqueue->rear] = val;
    cqueue->rear = INC(cqueue->rear);
}

void insertLeft(Queue cqueue) {
    /* Ask and insert element from 
    the front of queue */
    DEBUG(cqueue->front, "%d");
    DEBUG(cqueue->rear,  "%d");
    if (isfull(cqueue)) {
        puts(OVERFLOW);
        return;
    }
    double val = getValue();
    cqueue->front = DEC(cqueue->front); // decrement front to get previous empty space
    cqueue->arr[cqueue->front] = val;   // insert the element there
}

void deleteRight(Queue cqueue) {
    /* Delete an element from the rear */
    DEBUG(cqueue->front, "%d");
    DEBUG(cqueue->rear,  "%d");
    if (isempty(cqueue)) {
        puts(UNDERFLOW);
        return;
    }
    cqueue->rear = DEC(cqueue->rear);
    printf("Deleted: %g\n", cqueue->arr[cqueue->rear]);
    if (cqueue->front == cqueue->rear)
        cqueue->front = cqueue->rear = -1;
}

void deleteLeft(Queue cqueue) {
    /* Delete element from the front side */
    DEBUG(cqueue->front, "%d");
    DEBUG(cqueue->rear,  "%d");
    if (isempty(cqueue)) {
        puts(UNDERFLOW);
        return;
    }
    printf("Deleted: %g\n", cqueue->arr[cqueue->front]);
    cqueue->front = INC(cqueue->front);
    if (cqueue->front == cqueue->rear)      // if all the elements got deleted,
        cqueue->front = cqueue->rear = -1;  // trigger the empty condition for distinction
}                                           // with full condition

void displayQueue(Queue cqueue) {
    /* Display the queue contents */
    DEBUG(cqueue->front, "%d");
    DEBUG(cqueue->rear,  "%d");
    if (isempty(cqueue)) {
        puts(UNDERFLOW);
        return;
    }
    int i = cqueue->front;
    do {
        printf("%g ", cqueue->arr[i]);      // increment first before checking the
        i = INC(i);                         // loop condition to overcome the initial
    } while(i != cqueue->rear);             // false positive (initially if full,
    putchar('\n');                          // cqueue->front == cqueue->rear)
}

