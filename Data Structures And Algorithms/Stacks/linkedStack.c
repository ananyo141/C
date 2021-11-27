// 2. Write a program to implement a linked stack (push, pop, peek, display)

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *next;
} Node;

// linked list implemented stack attributes,
// internally linked
static Node *start   = NULL;           // opted to use a node ptr instead of
static Node *topNode = NULL;           // top counter and getLastNode() combination
const char *emptyMsg = "Stack empty";  // display if stack is empty

// function declarations 
void push(void);
void pop (void);
void peek(void);
void display(void);
int isfull (void);
int isempty(void);

int main() {
    int choice;
    void (*commands[]) (void) = {push, pop, peek, display};
    for (;;) {
        puts(
                "************ Stack Operations ************\n"
                "1) Push                        2) Pop\n"
                "3) Peek                        4) Display\n"
                "Command: (-1 to exit)"
        );
        scanf("%d", &choice);
        if (choice < 1 || choice > 4) {
            if (choice == -1) break;
            puts("Invalid Choice");
            continue;
        }
        system("clear");
        commands[choice-1]();
        puts("Output:");
    }
    puts("Exit");

    return 0;
}

void push(void) {
    /* Push data into stack */
    Node *currNode = malloc(sizeof(Node));
    if (currNode == NULL) {
        fprintf(stderr, "Malloc failed in %s\n"
                "Line: %d, File: %s, Time: %s\n",
                __func__, __LINE__, __FILE__, __TIME__);
        exit(EXIT_FAILURE);
    }
    printf("Enter data: ");
    scanf("%d", &currNode->data);
    currNode->next = NULL;
    if (start == NULL)
        start = currNode;
    else 
        topNode->next = currNode;
    topNode = currNode;
}
void pop(void) {
    /* Pop the last data of the stack */
    if (isempty()) {
        puts(emptyMsg);
        return;
    }
    printf("Popped: %d\n", topNode->data);

    // find second-last node and update topNode
    Node *ptr;
    for (ptr = start;
         ptr && ptr->next != topNode;
         ptr = ptr->next) ;
    if (ptr)
        ptr->next = NULL;   // if second-last was found (is not start)
    else start = NULL;      // else if start is to be deleted
    free(topNode);          // deallocate last node
    topNode = ptr;          // update last node
}
void peek(void) {
    /* Display the last node data without popping */
    if (isempty())
        puts(emptyMsg);
    else
        printf("Top Stack data: %d\n", topNode->data);
}
void display(void) {
    /* Display the stack contents */
    if (isempty()) {
        puts(emptyMsg);
        return;
    }
    for (Node *ptr=start; ptr; ptr=ptr->next)
        printf("%d ", ptr->data);
    putchar('\n');
}
int isfull(void) {
    /* Return 1 if stack full, 0 otherwise */
    // Extra: Linked list stack implementation is never full
    // under normal circumstances, so this function always returns 0
    return 0;
}
int isempty(void) {
    /* Return 1 if stack empty, 0 otherwise */
    return start == NULL;
}

