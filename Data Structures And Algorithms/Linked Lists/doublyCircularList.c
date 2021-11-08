/* 4. Write a program to create a circular doubly linked list and perform insertions and deletions
at the beginning and end of the list.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct doubly_circular {
    struct doubly_circular *prev;
    int data;
    struct doubly_circular *next;
} DCL;

/*** Function declarations ***/
DCL *create_ll(DCL *);
DCL *display(DCL *);
DCL *insert_beg(DCL *);
DCL *insert_end(DCL *);
DCL *delete_beg(DCL *);
DCL *delete_end(DCL *);
DCL *delete_node(DCL *);
DCL *delete_list(DCL *);
DCL *display_reverse(DCL *);
/*** Helper Functions ***/
DCL *getLastNode(DCL *);
void checkAllocMem(void *, const char *, const int);

int main() {
    int option;
    DCL *start = NULL;  // head
    // an array of function pointers to hold the operations
    DCL *(*commands[])(DCL *) = {create_ll, display, insert_beg, insert_end, delete_beg,
                                 delete_end, delete_node, delete_list, display_reverse};
    // Make an interactive prompt //
    for(;;) {
        puts(
            "\n	    ****** Doubly Circular Linked List ******\n"
            "i)   Create doubly circular list    ii)   Display linked list\n"
            "iii) Insert node at beginning       iv)   Insert node at end\n"
            "v)   Delete node at beginning       vi)   Delete node at end\n"
            "vii) Delete a given node            viii) Delete list\n"
            "ix)  Display list reverse\n"
            "Command (-1 to exit):"
        );
        scanf("%d", &option);
        system("clear"); // clear console, platform-specific, may need to change for windows("cls")
        puts("Output:");
        if (option < 1 || option > 9) {
            if (option == -1) break;
            puts("Invalid input");
            continue;
        }
        start = commands[option-1](start);
        puts("Operation Completed successfully");
    } 
    puts("Exit");
    delete_list(start); // all the heap memory is released

    return 0;
}

// function definitions //
void checkAllocMem(void *ptr, const char *funcName, const int line) {
    /* Check if the memory allocated by malloc is valid */
    if (ptr == NULL) {
        fprintf(stderr, "Unable to allocate memory, exiting...\n");
        fprintf(stderr, "Error details: In function '%s' of file '%s'"
                        " line %d\nTime: %s, Date: %s\n",
                        funcName, __FILE__, line, __TIME__, __DATE__);
        exit(EXIT_FAILURE);
    }
}

DCL *create_ll(DCL *start) {
    /* Create a doubly circular linked list */
    if (start) {
        puts("Previously allocated list exists,\n"
             "freeing up space");
        delete_list(start);
    }
    start = NULL;
    DCL *prevNode, *currNode;
    for (;;) {
        currNode = malloc(sizeof(DCL));
        checkAllocMem(currNode, __func__, __LINE__);
        printf("Enter data (-1 to exit): ");
        scanf("%d", &currNode->data);
        if (currNode->data == -1) {
            free(currNode);
            if (start) {
                start->prev = prevNode;
                prevNode->next = start;
            }
            break;
        }
        if (start) {
            prevNode->next = currNode;
            currNode->prev = prevNode;
        } else start = currNode;
        prevNode = currNode;
    }
    return start;
}

DCL *display(DCL *start) {
    /* display a linked list */
    if (!start) {
        puts("List empty");
        return start;
    }
    DCL *ptr;
    for (ptr = start; ptr->next != start; ptr=ptr->next)
        printf("%d ", ptr->data);
    printf("%d\n", ptr->data);
    return start;
}

DCL *display_reverse(DCL *start) {
    /* display the list in reverse */
    DCL *end = getLastNode(start);
    for (; end != start; end=end->prev)
        printf("%d ", end->data);
    printf("%d\n", end->data);
    return start;
}

DCL *insert_beg(DCL *start) {
    /* insert a node at the beginning */
    DCL *currNode = malloc(sizeof(DCL));
    DCL *end = getLastNode(start);
    checkAllocMem(currNode, __func__, __LINE__);
    printf("Enter node value: ");
    scanf("%d", &currNode->data);

    if (start == NULL)                       // felt lazy and tried something new
        start = end = currNode;              // though inefficient, works
    currNode->next = start;
    start->prev = currNode;
    currNode->prev = end;
    end->next = currNode;

    return currNode;
}

DCL *insert_end(DCL *start) {
    /* insert node at end */
    DCL *ptr = insert_beg(start);           // this is another one of the hacks
    return start == NULL ? ptr : start;     // I discovered during testing
}

DCL *delete_beg(DCL *start) {
    /* delete the beginning node */
    if (start == NULL) {
        puts("List is already empty");
        return NULL;
    }
    DCL *end = getLastNode(start);
    end->next = start->next;
    start->next->prev = end;
    free(start);
    return start == end ? NULL : end->next;
}

DCL *delete_end(DCL *start) {
    /* delete the end node */
    if (start == NULL) {
        puts("List is already empty");
        return NULL;
    }
    DCL *end = getLastNode(start);
    end->prev->next = start;
    start->prev = end->prev;
    free(end);
    return start == end ? NULL : start;
}

DCL *delete_node(DCL *start) {
    /* delete a given node by value */
    if (start == NULL) {
        puts("List is already empty");
        return NULL;
    }
    int val;
    printf("Enter the node you want to delete: ");
    scanf("%d", &val);
    DCL *ptr;
    for (ptr=start;
         ptr->data != val && ptr->next != start; 
         ptr=ptr->next) ;
    if (ptr->data == val) {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        if (ptr == start && start->next == start)       // if start was deleted and it
            start = NULL;                               // was the only node
        else if (ptr == start)                          // or if start got deleted,
            start = start->next;                        // but next exists
        free(ptr);                                      // else, start remains unchanged
    } else {
        printf("Value %d not found\n", val);
    }
    return start;
}
DCL *delete_list(DCL *start) {
    /* delete the entire linked list */
    if (start == NULL) {
        puts("List is already empty");
        return NULL;
    }
    DCL *ptr = start, *temp;
    while (ptr->next != start) {
        temp = ptr->next;
        free(ptr);
        ptr=temp;
    }
    free(ptr);
    return NULL;
}
DCL *getLastNode(DCL *start) {
    /* return the last node of dcl list */
    if (start == NULL) return NULL;
    DCL *ptr = start;
    while (ptr->next != start)
        ptr=ptr->next;
    return ptr;
}

