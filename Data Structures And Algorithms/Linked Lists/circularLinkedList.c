/* 2. Write a program to create a circular linked list. Perform insertion and deletion at the beginning
and end of the list. */

#include <stdio.h>
#include <stdlib.h>

typedef struct circular_node {
    int data;
    struct circular_node *next;
} CircularNode;

// prototypes //
void checkAllocMem(void *, const char *, const int);
CircularNode *getLastNode(CircularNode *);
CircularNode *create_cll(CircularNode *);
CircularNode *display(CircularNode *);
CircularNode *insert_beg(CircularNode *);
CircularNode *insert_end(CircularNode *);
CircularNode *delete_beg(CircularNode *);
CircularNode *delete_end(CircularNode *);
CircularNode *delete_after(CircularNode *);
CircularNode *delete_list(CircularNode *); 

int main() {
    int option;
    CircularNode *start = NULL;  // head
    // an array of function pointers to hold the operations
    CircularNode *(*commands[])(CircularNode *) = {create_cll, display, insert_beg, insert_end,
                                                   delete_beg, delete_end, delete_after, delete_list};
    // Make an interactive prompt //
    for(;;) {
        puts(
            "\n		 ****** Circular Linked List ******\n"
            "i)   Create Circular linked list    ii)   Display linked list\n"
            "iii) Insert node at beginning       iv)   Insert node at end\n"
            "v)   Delete node at beginning       vi)   Delete node at end\n"
            "vii) Delete after a node            viii) Delete list\n"
            "Command (-1 to exit):"
        );
        scanf("%d", &option);
        system("clear"); // clear console, platform-specific, may need to change for windows("cls")
        puts("Output:");
        if (option < 1 || option > 8) {
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

CircularNode *getLastNode(CircularNode *start) {
    /* Return the pointer to the last node of the list */
    if (start == NULL) return NULL;
    CircularNode *ptr;
    for (ptr = start;
         ptr->next != start;
         ptr = ptr->next)  ;
    return ptr;
}

CircularNode *create_cll(CircularNode *startPrev) {
    /* Create a circular linked list by taking input from the user */
    if (startPrev) {
        puts("A previously allocated linked list exists,\n"
              "free up space by deleting and then try creating\n"
              "another one");
        return startPrev;
    }
    
    CircularNode *start = NULL, *currNode, *prevNode;
    for (;;) {
        currNode = malloc(sizeof(CircularNode));
        checkAllocMem(currNode, __func__, __LINE__);
        printf("Enter the data: ");
        scanf("%d", &currNode->data);
        if (currNode->data == -1) {         // stop building list
            free(currNode);                 // free the allocated memory
            if (start)                      // if start exists, prevNode exists
                prevNode->next = start;     // so, mark it's end as the addr of start
            break;
        }
        if (start)                          // if start exists, first iteration is done
            prevNode->next = currNode;      // so prevNode next can be set
        else
            start = currNode;               // else set start as addr of current node
        prevNode  = currNode;               // and initialize prevNode
    }
    return start;                           // return start at end of list
}

CircularNode *display(CircularNode *start) {
    /* Display the circular linked list */
    if (start == NULL) {
        puts("List empty");
        return start;
    }
    CircularNode *ptr;
    for (ptr = start; ptr->next != start; ptr = ptr->next) 
        printf("%d ", ptr->data);
    printf("%d\n", ptr->data);
    return start;
}

CircularNode *insert_beg(CircularNode *start) {
    /* Insert a node at the beginning */
    CircularNode *insertBeg = malloc(sizeof(CircularNode));
    checkAllocMem(insertBeg, __func__, __LINE__);
    printf("Enter data to insert at beginning: ");
    scanf("%d", &insertBeg->data);
    if (start) {                                // if start (atleast one element) exists, 
        CircularNode *end = getLastNode(start); // traverse to the end of list
        end->next = insertBeg;                  // and assign next of end ptr to insertBeg
        insertBeg->next = start;                // and insertBeg points to previous start
    }
    else
        insertBeg->next = insertBeg;        // else insertBeg just points to itself
    return insertBeg;                       // return insertBeg as the new start
}

CircularNode *insert_end(CircularNode *start) {
    /* Insert node at the end */
    CircularNode *insertEnd = malloc(sizeof(CircularNode));
    checkAllocMem(insertEnd, __func__, __LINE__);
    printf("Enter the value to insert at end: ");
    scanf("%d", &insertEnd->data);
    if (start == NULL) {                    // if list empty,
        insertEnd->next = insertEnd;        // insertEnd points to itself
        return insertEnd;                   // return insertEnd as start
    }
    CircularNode *end = getLastNode(start); // traverse to the end of list
    end->next = insertEnd;                  // end-next points to insertEnd
    insertEnd->next = start;                // insertEnd-next points to start
    return start;
}

CircularNode *delete_beg(CircularNode *start) {
    /* Delete the node at the beginning */
    if (start == NULL) {
        puts("Already empty");
        return start;
    }
    CircularNode *temp, *end;
    end  = getLastNode(start);              // record the end node
    temp = start->next;                     // save the start-next, i.e, second node
    free(start);                            // free the starting node
    end->next = temp;                       // set end-next to point at second node
    return end==start ? NULL : temp;        // if start == end (only one item), return NULL
}                                           // else, return second-node ptr as first node

CircularNode *delete_end(CircularNode *start) {
    /* Delete the end node */
    if (start == NULL) {
        puts("List empty");
        return start;
    }
    CircularNode *second_last, *end;
    for (end = start;                       // traverse to the end of list
         end->next != start;                // keeping track of second_last node
         second_last=end, end=end->next) ;
    free(end);                              // free the last node
    if (start == end) return NULL;          // if deleted node was the only one, return NULL
    second_last->next = start;              // else rewire second_last node to point to start
    return start;
}

CircularNode *delete_after(CircularNode *start) {
    /* Delete a node after a given node */
    int val;
    printf("Enter the value after which you want to delete: ");
    scanf("%d", &val);
    CircularNode *ptr, *toDelete;
    for (ptr = start;
         ptr->data != val && ptr->next != start;        // traverse list finding value
         ptr = ptr->next) ;
    if (ptr->data == val) {                             // if value is found,
        if (start == ptr) {                             // if only one node exists
            delete_end(start);                          // delete that node(by code reuse)
            return NULL;                                // return empty list as NULL 
        }
        toDelete = ptr->next;                           // else find the node to delete
        ptr->next = ptr->next->next;                    // set next field of curr node to next of
        free(toDelete);                                 // the node to delete and free node
        return toDelete == start ? ptr->next : start;   // if start was deleted, return second ptr, else start
    } else puts("Value not found in list");
    return start;
}

CircularNode *delete_list(CircularNode *start) {
    /* Delete the entire linked list */
    if (start == NULL) {
        puts("List empty");
        return start;
    } if (start->next == start) {                       // if only node,
        free(start);                                    // free start node and return NULL
        return NULL;
    }
    CircularNode *ptr=start, *next;
    while(ptr->next != start) {                         // traverse list until last node
        next = ptr->next;                               // save next node address
        free(ptr);                                      // safely delete current node
        ptr = next;                                     // advance to next node
    }
    free(ptr);                                          // free last node and,
    return NULL;                                        // return NULL as empty list
}

