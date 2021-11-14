// 5. Write a program to implement a header linked list.

#include <stdio.h>
#include <stdlib.h>
#define DEBUG(elem,type) printf(#elem " = " type "\n", elem)

typedef struct node {
    int data;
    struct node *next;
} Node;

//*** Function declarations ***//
Node *create_hll(Node *);
Node *display(Node *); 

int main() {
    Node *start = NULL;
    int option;
    Node *(*commands[])(Node *) = {create_hll, display};
    for(;;) {
        puts(
            "\n		 ****** Header Linked List ******\n"
            "i)    Create linked list             ii)   Display linked list\n"
            "Command (-1 to exit):"
        );
        scanf("%d", &option);
        system("clear"); // clear console, platform-specific, may need to change for windows("cls")
        puts("Output:");
        if (option < 1 || option > 2) {
            if (option == -1) break;
            puts("Invalid input");
            continue;
        }
        start = commands[option-1](start);
        puts("Operation Completed successfully");
    } 
    puts("Exit");

    return 0;
}

Node *create_hll(Node *start) {
    /* Create a header linked list */
    if (start) {
        puts("Previous list exists, unable to create new");
        return start;
    }
    Node *prevNode, *currNode;
    puts("Enter node values, -1 to exit");
    for (;;) {
        currNode = malloc(sizeof(Node));
        printf("Enter node data: ");
        scanf("%d", &currNode->data);
        if (currNode->data == -1) {
            free(currNode);
            if (start)
                prevNode->next = NULL;
            break;
        }
        if (start)                          // if start (or header node exists)
            prevNode->next = currNode;
        else {
            start = malloc(sizeof(Node));   // if not, create header node
            start->next = currNode;         // put its pointer to curr as first node
        }
        prevNode = currNode;
    }
    return start;
}

Node *display(Node *start) {
    /* Display a header linked list */
    if (start == NULL) {
        puts("List empty");
        return start;
    }
    Node *ptr;
    for (ptr = start->next; ptr; ptr=ptr->next)
        printf("%d ", ptr->data);
    printf("\n");
    return start;
}

