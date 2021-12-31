// Implement Multiple Queue
/* NOTE: This program is a convoluted piece of work; require further testing
** and debugging. After a lot of contemplation and several mindducks, this
** comes as near to utility as possible, and is fair to say may even be
** perfect after some time and deliberation. Further DEBUGGING RECOMMENDED */

#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define DEFPART   -2    // default/unset value for partition
#define DEFEMPTYA -1    // empty indicator for queue A
#define DEFEMPTYB MAX   // empty indicator for queue B
#define _INC(x) (((x) + 1) % MAX)                   // private macro to just increment and wrap
#define _DEC(x) (((x) - 1) < 0 ? MAX - 1 : (x) - 1) // private macro to decrement and wrap
#define DEBUG(elem,type) fprintf(stderr, #elem "\t= " type "\n", elem); \
                         fflush(stderr)

#undef  DEBUG                 // comment/uncomment these two lines
#define DEBUG(elem,type)      // to toggle logging to stderr

// Multiple Queue Data Aggregation //
typedef struct multiple_queue {
    double arr[MAX];     // hold both the queues
    int partition;       // partition index (holds the last valid index of A)
    int frontA;          // front of A
    int frontB;          // rear  of A
    int rearA;           // front of B
    int rearB;           // rear  of B
} *multiQ;

// Prototypes //
static inline int INC_A(int, const multiQ);
static inline int DEC_B(int, const multiQ);
multiQ initialize_queue();
int isfullA (const multiQ);
int isfullB (const multiQ);
int isemptyA(const multiQ);
int isemptyB(const multiQ);
int liftPartition(const multiQ);
void insertA(multiQ);
void insertB(multiQ);
void deleteA(multiQ);
void deleteB(multiQ);
void displayA(multiQ);
void displayB(multiQ);

int main() {
    // Declare and initialize multiple
    // queue structure
    int choice;
    multiQ mqueue = initialize_queue();
    void (*commands[]) (multiQ) = {
                insertA, insertB, deleteA,
                deleteB, displayA, displayB,
    };
    for (;;) {
        puts(
                "****** Multiple Queue *******\n"
                "1) Insert A      2) Insert B\n"
                "3) Delete A      4) Delete B\n"
                "5) Display A     6) Display B\n"
                "Command (-1 to exit):"
        );
        if (!scanf("%d", &choice)) {    // for failed read,
            while(getchar() != '\n') ;  // clear input buffer
            choice = -111;              // set invalid value to trigger 
        }                               // continue in the next test
        system("clear");
        if (choice < 1 || choice > 6) {
            if (choice == -1) break;
            puts("Invalid Choice");
            continue;
        }
        puts("Output:");
        commands[choice-1](mqueue);
        puts("Operation Successful");
    }
    puts("Exit");
    return 0;
}

// Definitions //
int INC_A(int x, const multiQ mqueue) {
    /* Increment front and rear of Queue A respecting partition */
    ++x;
    return (x >  mqueue->rearB  ||          // if greater than the rear end of queue B,
            x == mqueue->frontB ||          // or equal to front of queue B, 
            x == _INC(mqueue->partition))   // or crosses the partition limit (last valid index of A)
            ? 0         // warp to front
            : x;
}

int DEC_B(int x, const multiQ mqueue) {
    /* Decrement front and rear of Queue B respecting partition */
    --x;
    return (x <  mqueue->rearA  ||          // if less than rear of queue A,
            x == mqueue->frontA ||          // or equal to front of queue A,
            x == mqueue->partition)         // or equal to partition limit (doesn't hold value for B)
            ? MAX - 1   // warp to front
            : x;
}

multiQ initialize_queue() {
    /* Allocate and Initalize data parts of queue */
    multiQ new = malloc(sizeof(struct multiple_queue));
    if (new == NULL) {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    new->partition = DEFPART;              // default value
    new->frontA = new->rearA = DEFEMPTYA;  // empty condition for A
    new->frontB = new->rearB = DEFEMPTYB;  // empty condition for B
    return new;
}

int isfullA(const multiQ mqueue) {
    /* Return if Queue A is full */
    return (mqueue->frontA != DEFEMPTYA) &&     // front and rear are equal, but
           (mqueue->frontA == mqueue->rearA);   // not equal to -1 (i.e, empty condition)
}

int isfullB(const multiQ mqueue) {
    /* Return if Queue B is full */
    return (mqueue->frontB != DEFEMPTYB) &&     // front and rear are equal, but
           (mqueue->frontB == mqueue->rearB);   // not equal to B's empty condition (MAX)
}

int isemptyA(const multiQ mqueue) {
    /* Return if Queue A is empty */
    return (mqueue->frontA == DEFEMPTYA) &&     // satisfies the empty condition for A
           (mqueue->rearA  == DEFEMPTYA);
}

int isemptyB(const multiQ mqueue) {
    /* Return if Queue B is empty */
    return (mqueue->frontB == DEFEMPTYB) &&    // satisfies the empty condition for B
           (mqueue->rearB  == DEFEMPTYB);
}

int liftPartition(const multiQ mqueue) {
    /* Check whether conditions for lifting partition
    is fulfilled */
    return (isemptyA(mqueue) && isemptyB(mqueue)) ||   // if both are empty, else test true for all of these:
           (mqueue->frontA <= mqueue->rearA       &&   // if frontA is less equal to rearA
            mqueue->rearA  < mqueue->partition    &&   // and rearA is less than partition
            !isfullA(mqueue) && !isfullB(mqueue)  &&
            mqueue->frontB >= mqueue->rearB       &&   // frontB is greater or less than rearB
            mqueue->rearB  > mqueue->partition);       // rearB is greater than partition
}                                                      // (all given both are not full, when less
                                                       // `equal` and greater `equal` will give false positive)
void insertA(multiQ mqueue) {
    /* Insert an element into Queue A */
    DEBUG(mqueue->frontA, "%d");
    DEBUG(mqueue->rearA,  "%d");
    if (isfullA(mqueue)) {
        puts("Queue A Overflow");
        return;
    }
    if (liftPartition(mqueue))              // lift partition if condition is satisfied
            mqueue->partition = DEFPART;
    if (isemptyA(mqueue))                   // if queue A is empty, first initialize front and rear
        mqueue->frontA = mqueue->rearA = 0;
    if (mqueue->rearA == mqueue->rearB) {   // if rear of A is equal to rear of B (contending
        mqueue->partition = mqueue->rearA;  // position), set that as partition, (last valid position of A), fill it,
        mqueue->rearB = mqueue->frontB;     // and mark queue B as full
    }
    printf("Enter value: ");
    scanf("%lf", &mqueue->arr[mqueue->rearA]);      // save and
    mqueue->rearA = INC_A(mqueue->rearA, mqueue);   // increment
}

void insertB(multiQ mqueue) {
    /* Insert an element into Queue B */
    DEBUG(mqueue->frontB, "%d");
    DEBUG(mqueue->rearB,  "%d");
    if (isfullB(mqueue)) {
        puts("Queue B Overflow");
        return;
    }
    if (liftPartition(mqueue))
            mqueue->partition = DEFPART;
    if (isemptyB(mqueue))                           // if empty, initialize front and rear
        mqueue->frontB = mqueue->rearB = MAX-1;
    if (mqueue->rearB == mqueue->rearA) {           // if queue B gets to the contending position, 
        mqueue->partition = _DEC(mqueue->rearB);    // set one lower index to be the partition,
        mqueue->rearA = mqueue->frontA;             // and mark queue A to be full
    }
    printf("Enter value: ");
    scanf("%lf", &mqueue->arr[mqueue->rearB]);
    mqueue->rearB = DEC_B(mqueue->rearB, mqueue);
}

void deleteA(multiQ mqueue) {
    /* Delete front element from Queue A */
    DEBUG(mqueue->frontA, "%d");
    DEBUG(mqueue->rearA,  "%d");
    if (isemptyA(mqueue)) {
        puts("Queue A Underflow");
        return;
    }
    if (liftPartition(mqueue))
        mqueue->partition = DEFPART;
    printf("Deleted A: %g\n", mqueue->arr[mqueue->frontA]);
    mqueue->frontA = INC_A(mqueue->frontA, mqueue); 
    if (mqueue->frontA == mqueue->rearA)             // increment taking care, that if rear and front
        mqueue->frontA = mqueue->rearA = DEFEMPTYA;  // become equal, the queue is empty and set empty condition
}

void deleteB(multiQ mqueue) {
    /* Delete front element from Queue B */
    DEBUG(mqueue->frontB, "%d");
    DEBUG(mqueue->rearB,  "%d");
    if (isemptyB(mqueue)) {
        puts("Queue B Underflow");
        return;
    }
    if (liftPartition(mqueue))
        mqueue->partition = DEFPART;
    printf("Deleted B: %g\n", mqueue->arr[mqueue->frontB]);
    mqueue->frontB = DEC_B(mqueue->frontB, mqueue);
    if (mqueue->frontB == mqueue->rearB)                // decrement and if front and rear are equal,
        mqueue->frontB = mqueue->rearB = DEFEMPTYB;     // set empty condition
}

void displayA(multiQ mqueue) {
    /* Display Queue A */
    DEBUG(mqueue->frontA, "%d");
    DEBUG(mqueue->rearA,  "%d");
    DEBUG(mqueue->partition, "%d");
    if (isemptyA(mqueue)) {
        puts("Queue A Underflow");
        return;
    }
    int i = mqueue->frontA;
    do {
        printf("%g ", mqueue->arr[i]);
        i = INC_A(i, mqueue);       // increment first to avoid stopping
    } while (i != mqueue->rearA);   // of loop before first iteration
    putchar('\n');
}

void displayB(multiQ mqueue) {
    /* Display Queue B */
    DEBUG(mqueue->frontB, "%d");
    DEBUG(mqueue->rearB,  "%d");
    DEBUG(liftPartition(mqueue), "%d");
    if (isemptyB(mqueue)) {
        puts("Queue B Underflow");
        return;
    }
    int i = mqueue->frontB;
    do {
        printf("%g ", mqueue->arr[i]);
        i = DEC_B(i, mqueue);
    } while (i != mqueue->rearB);
    putchar('\n');
}

