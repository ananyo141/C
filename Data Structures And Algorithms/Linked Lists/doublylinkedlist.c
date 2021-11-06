/* 3. Write a program to create a doubly linked list and perform insertions and deletions in all
cases. */

#include <stdio.h>
#include <stdlib.h>

typedef struct double_linked_list {
    struct double_linked_list *prev;
    int data;
    struct double_linked_list *next;
} DLL;

// *** Function declarations *** //
DLL *create_ll     (DLL *);
DLL *display       (DLL *);
DLL *displayReverse(DLL *);
DLL *insert_beg    (DLL *);
DLL *insert_end    (DLL *);
DLL *insert_before (DLL *);
DLL *insert_after  (DLL *);
DLL *delete_beg    (DLL *);
DLL *delete_end    (DLL *);
DLL *delete_before (DLL *);
DLL *delete_after  (DLL *);
DLL *delete_list   (DLL *);
DLL *getLastNode   (DLL *);
DLL *getNodeByVal  (DLL *, int);
void checkAllocMem(void *, const char *, const int);

int main() {
    int option;
    DLL *start = NULL;  // head
    // an array of function pointers to hold the operations
    DLL *(*commands[])(DLL *) = {create_ll, display, displayReverse, insert_beg, insert_end, insert_before,
                                 insert_after, delete_beg, delete_end, delete_before, delete_after, delete_list};
    // Make an interactive prompt //
    for(;;) {
        puts(
            "\n		 ****** Doubly Linked List ******\n"
            "  i) Create linked list            ii) Display linked list\n"
            "iii) Display linked list reversed  iv) Insert node at beginning\n"
            "  v) Insert node at end            vi) Insert before a given node\n"
            "vii) Insert after a given node   viii) Delete node at beginning\n"
            " ix) Delete node at end             x) Delete before a given node\n"
            " xi) Delete after a given node    xii) Delete the entire linked list\n"
            "Command (-1 to exit):"
        );
        scanf("%d", &option);
        system("clear"); // clear console, platform-specific, may need to change for windows("cls")
        puts("Output:");
        if (option < 1 || option > 12) {
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

// Function Definitions //
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

DLL *getLastNode(DLL *start) {
    /* Return the address of the last node */
    DLL *ptr, *prev;
    for (ptr = start;
         ptr;
         prev = ptr, ptr = ptr->next) ;
    return start ? prev : NULL;
}

DLL *create_ll(DLL *startPrev) {
    /* create the doubly linked list */
    DLL *start=NULL, *currNode, *prevNode;
    if (startPrev) {
        puts("Previously allocated doubly linked list\n"
             "present; deleting to free memory");
        delete_list(startPrev);
    }
    for (;;) {
        currNode = malloc(sizeof(DLL));
        checkAllocMem(currNode, __func__, __LINE__);
        printf("Enter value (-1 to exit): ");
        scanf("%d", &currNode->data);
        if (currNode->data == -1) {                 // for end signal,
            free(currNode);                         // free current allocation
            if (start) prevNode->next = NULL;       // if atleast one node exists
            break;                                  // mark the prev-next as end of list
        }
        if (start) {                                // if start exists,
            prevNode->next = currNode;              // prevNode is initialised, set to curr
            currNode->prev = prevNode;              // and curr-prev to prevNode
        } else {
            start = currNode;                       // else initialize start,
            currNode->prev = NULL;                  // and set first node-prev to null
        }
        prevNode = currNode;                        // keep track of latest node
    }
    return start;
}

DLL *display(DLL *start) {
    /* Display the linked list */
    if (start == NULL) printf("List Empty");
    for (DLL *ptr = start; ptr; ptr = ptr->next) 
        printf("%d ", ptr->data);
    printf("\n");
    return start;
}

DLL *displayReverse(DLL *start) {
    /* Display the linked list reversed */
    DLL *end = getLastNode(start);
    for (DLL *ptr = end; ptr; ptr = ptr->prev) 
        printf("%d ", ptr->data);
    printf("\n");
    return start;
}

DLL *getNodeByVal(DLL *start, int val) {
    /* return pointer to a node containing
             a given value            */
    DLL *ptr;
    for (ptr = start;
         ptr && ptr->data != val;
         ptr = ptr->next) ;
    return ptr;                 // returns either DLL* or NULL
}

DLL *insert_beg(DLL *start) {
    /* Insert node at beginning */
    DLL *insertBeg = malloc(sizeof(DLL));
    checkAllocMem(insertBeg, __func__, __LINE__);
    printf("Enter value: ");
    scanf("%d", &insertBeg->data);
    if (start) {                        // if node exists,
        insertBeg->next = start;        // insertBeg-next points to that start
        start->prev = insertBeg;        // and start-prev points to insertBeg
    }
    else insertBeg->next = NULL;        // else, insertBeg is only node and points
    return insertBeg;                   // to null, and return it as the start
}

DLL *insert_end(DLL *start) {
    /* Insert node at the end */
    DLL *currNode, *end = getLastNode(start);
    currNode = malloc(sizeof(DLL));
    checkAllocMem(currNode, __func__, __LINE__);
    printf("Enter value: ");
    scanf("%d", &currNode->data);
    if (end) {                      // if end (atleast one node) exists,
        end->next = currNode;       // end-next is curr
        currNode->prev = end;       // curr-prev is end
    } else {
        start = currNode;           // else, start is curr
        currNode->prev = NULL;      // curr-prev is null
    }
    currNode->next = NULL;          // either case, curr-next is null
    return start;                   // return start
}

DLL *insert_before(DLL *start) {
    /* Insert node before a node of given value */
    if (start == NULL) {
        puts("List is empty, populate before using operation");
        return insert_beg(start);
    }
    int val;
    printf("Enter the value before which node has to be inserted: ");
    scanf("%d", &val);
    DLL *ptr = getNodeByVal(start, val);
    DLL *currNode = malloc(sizeof(DLL));
    checkAllocMem(currNode, __func__, __LINE__);
    if (ptr == NULL) {                          // not (ptr->data == val),
        printf("Value %d not found\n", val);    // as ptr fields are not valid
        free(currNode);                         // in case of NULL
    } else {
        printf("Enter value to insert: ");
        scanf("%d", &currNode->data);
        if (ptr == start) {                     // if first node,
            currNode->prev = NULL;              // currNode-prev is set to NULL
            start = currNode;                   // and currNode becomes start
        } else {
            currNode->prev = ptr->prev;         // else currNode-prev is ptr-prev
            ptr->prev->next = currNode;         // and ptr-prev points to currNode
        }
        currNode->next = ptr;                   // currNode points to ptr
        ptr->prev = currNode;                   // and ptr-prev to currNode
    }
    return start;
}

DLL *insert_after(DLL *start) {
    /* Insert a node after a given value */
    if (start == NULL) 
        return insert_before(start); // for the default 'scolding' message
    int val;
    printf("Enter the value after which node has to be inserted: ");
    scanf("%d", &val);
    DLL *ptr = getNodeByVal(start, val);
    DLL *currNode = malloc(sizeof(DLL));
    checkAllocMem(currNode, __func__, __LINE__);
    if (ptr == NULL) {
        printf("Value %d not found\n", val);
        free(currNode);
    } else {
        printf("Enter value to insert: ");
        scanf("%d", &currNode->data);
        if (ptr->next) {                           // if ptr's next node is not NULL
            ptr->next->prev = currNode;            // (i.e, exists) set prev of that node
            currNode->next = ptr->next;            // to curr and curr-next to it
        }
        ptr->next = currNode;                      // ptr-next points to curr
        currNode->prev = ptr;                      // and curr-prev to ptr
    }
    return start;
}

DLL *delete_beg(DLL *start) {
    /* Delete the first node */
    if (start == NULL) {
        puts("List is already empty");
        return start;
    }
    DLL *second = start->next;
    free(start);
    return second;
}

DLL *delete_end(DLL *start) {
    /* Delete the end node */
    if (start == NULL)
        return delete_beg(start);         // same message
    DLL *end = getLastNode(start);
    if (end->prev)                        // if previous node of end exists, ie
        end->prev->next = NULL;           // end isn't start, next of that node is NULL
    free(end);
    return end == start ? NULL : start;   // if end wasn't start, return start else NULL
}


DLL *delete_before(DLL *start) {
    /* Delete node before a given node */
    if (start == NULL) 
        return delete_beg(start);
    int val;
    printf("Enter the value before which node has to be deleted: ");
    scanf("%d", &val);
    DLL *ptr = getNodeByVal(start, val);
    if (ptr == start)                           // if node before start has to be deleted,
        return delete_end(start);               // delete the end node
    DLL *toDelete = ptr->prev;                  // else, ptr-prev is the addr of node to delete
    if (toDelete->prev)                         // if it exists, set its next to ptr
        toDelete->prev->next = ptr;
    ptr->prev = toDelete->prev;                 // set ptr-prev to prev of node to delete
    free(toDelete);
    return toDelete == start ? ptr : start;     // if deleted start, return ptr, else start
}

DLL *delete_after(DLL *start) {
    /* Delete after a given node */
    if (start == NULL)
        return delete_beg(start);
    int val;
    printf("Enter the value after which node has to be deleted: ");
    scanf("%d", &val);
    DLL *ptr = getNodeByVal(start, val);
    if (ptr == getLastNode(start))          // if ptr is last node,
        return delete_beg(start);           // delete the start
    DLL *toDelete = ptr->next;
    if (toDelete->next)                     // if next node after to-delete exists
        toDelete->next->prev = ptr;         // assign its prev to ptr
    ptr->next = toDelete->next;             // set ptr-next to that next node of delete
    free(toDelete);
    return start;
}

DLL *delete_list(DLL *start) {
    /* Delete the linked list */
    DLL *currNode = start, *temp;
    while (currNode) {
        temp = currNode->next;
        free(currNode);
        currNode = temp;
    }
    return NULL;
}

