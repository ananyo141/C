/* 1. Write a program to create a linked list and perform insertions and deletions of all cases.
i) At beginning
ii) At end
iii) After a given node
iv) Before a given node
v) Delete first node
vi) Delete last node
vii) The node after a given node
Also adding functions to save and reload from a file.
Write functions to sort and finally delete the entire list at once. */

/* NOTE: malloc() calls are susceptible to failures, and must be checked against NULL in case of 
failure to allocate heap memory. Such calls here are not wrapped in safety and should be used carefully */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define FILENAME 200

// node structure //
typedef struct node {
    int data;
    struct node *next;
} Node;

// prototypes //
Node *create_ll(Node *);
Node *display(Node *);
Node *insert_beg(Node *);
Node *insert_end(Node *);
Node *insert_before(Node *);
Node *insert_after(Node *);
Node *delete_beg(Node *);
Node *delete_end(Node *);
Node *delete_node(Node *);
Node *delete_after(Node *);
Node *delete_list(Node *);
Node *sort_list(Node *);
Node *save_list(Node *);
Node *reload_list(Node *);
int readline(char [], int);

int main() {
    int option;
    Node *start = NULL;  // head
    // an array of function pointers to hold the operations
    Node *(*commands[])(Node *) = {create_ll, display, insert_beg, insert_end, insert_before, insert_after,
                                   delete_beg, delete_end, delete_node, delete_after, delete_list, sort_list,
                                   save_list, reload_list};
    // Make an interactive prompt //
    for(;;) {
        puts(
            "\n		 ****** Linear Linked List ******\n"
            "i)    Create linked list             ii)   Display linked list\n"
            "iii)  Insert node at beginning       iv)   Insert node at end\n"
            "v)    Insert before a given node     vi)   Insert after a given node\n"
            "vii)  Delete node at beginning       viii) Delete node at end\n"
            "ix)   Delete a given node            x)    Delete all nodes after a given node(inclusive)\n"
            "xi)   Delete the entire linked list  xii)  Sort the linked list\n"
            "xiii) Save to a file                 xiv)  Reload from a file\n"
            "Command (-1 to exit):"
        );
        scanf("%d", &option);
        system("clear"); // clear console, platform-specific, may need to change for windows("cls")
        puts("Output:");
        if (option < 1 || option > 14) {
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
// This argument is a dummy one as it never gets used, 
 Node *create_ll(Node *startDummy) {    // used for function type compatibility
    /* Create a linked list from user input and 
      return the pointer to the starting node 
      (-1 to exit) */

    Node *start = NULL, *prevNode, *currNode;
    for (;;) {
        currNode = malloc(sizeof(Node));
        printf("Enter node value: ");
        scanf("%d", &currNode->data);
        if (currNode->data == -1) {
            if (start != NULL)
                prevNode->next = NULL;
            free(currNode);
            return start;
        }
        if (start == NULL) start = currNode;
        else prevNode->next = currNode;
        prevNode = currNode;
    }
    return start;
}

Node *display(Node *start) {
    /* Display the given linked list */
    if (start == NULL) {
       puts("List empty\n");
       return start;
    }
    Node *returnptr = start;
    while (start) {
        printf("%d ", start->data);
        start = start->next;
    }
    printf("\n");
    return returnptr;
}

Node *insert_beg(Node *start) {
    /* insert node at the beginning */
    Node *new = malloc(sizeof(Node));
    printf("Enter the value of new node at beginning: ");
    scanf("%d", &new->data);
    new->next = start;
    return new;
}

Node *insert_end(Node *start) {
    /* insert a node at the end of list */
    Node *endptr = start;
    if (endptr == NULL) {
        printf("List is empty\n");
        return start;
    }
    while (endptr->next) endptr = endptr->next;
    Node *new = malloc(sizeof(Node));
    printf("Enter the value of node at end: ");
    scanf("%d", &new->data);
    endptr->next = new;
    new->next = NULL;
    return start;
}

Node *insert_before(Node *start) {
    /* Insert a node before a given node */
    int val;
    Node *new = malloc(sizeof(Node));
    printf("Enter the value of node: ");
    scanf("%d", &new->data);
    printf("Enter the value before which you want to insert: ");
    scanf("%d", &val);

    Node *prev = NULL, *ptr;
    // find the position to put the new node 
    for (ptr = start;
        ptr && ptr->data != val;
        prev = ptr, ptr = ptr->next)  ;
    // if the previous node is null,
    if (prev == NULL) {
        if (start) new->next = start; // if start exists, (there is atlest one node in the linked list)
        else new->next = NULL;        // else, put next as null as the first node in the list
        return new;
    }
    // insert the new node
    Node *temp = prev->next;
    prev->next = new;
    if (ptr != NULL)          // if value is found,
        new->next  = temp;
    else new->next = NULL;    // else put node at the end

    return start;
}	

Node *insert_after(Node *start) {
    /* Insert a node after a given value */
    int val;
    Node *new = malloc(sizeof(Node));
    printf("Enter the value of the node: ");
    scanf("%d", &new->data);
    printf("Enter the value after which you want to insert node: ");
    scanf("%d", &val);

    Node *ptr = start, *prev;
    while (ptr && ptr->data != val) {
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {               // if not found,
        new->next = NULL;            // first set new node next field to NULL
        if (start) prev->next = new; // if even one node exists
        else return new;             // else just return pointer to new
        return start;                // return start (applicable if one node exists)
    }
    // insert the node
    Node *temp = ptr->next;
    ptr->next = new;
    new->next = temp;

    return start;    
}

Node *delete_beg(Node *start) {
    /* delete the first node in the list */
    if (start == NULL) return start; // if list empty
    Node *newStart = start->next;
    free(start);
    return newStart;
}

Node *delete_end(Node *start) {
    /* delete the end node */
    puts("Deleted end node");
    if (start == NULL) return start; // if list empty
    Node *prev, *ptr;
    for (ptr = start, prev = NULL;
         ptr->next; 
         prev = ptr, ptr = ptr->next) ;
    if (prev == NULL) return NULL;   // if only one element
    prev->next = NULL;
    free(ptr);
    return start;
}

Node *delete_node(Node *start) { 
    /* delete the node containing a given value */
    int val;
    printf("Enter the value of the node you want to delete: ");
    scanf("%d", &val);
    puts("Done");
    if (start == NULL) return start; // if empty

    Node *prev, *ptr, *temp;
    for (ptr = start, prev = NULL;
         ptr && ptr->data != val;
         prev = ptr, ptr = ptr->next) ;
    if (ptr == NULL) return start;   // if reaches end, not found
    if (ptr == start) {              // if first node to delete
        temp = ptr->next;
        free(ptr);
        return temp;
    }
    prev->next = ptr->next;          // else simple deletion
    free(ptr);
    return start;
}

Node *delete_after(Node *start) {
    /* delete the linked list after the given value */
    int val;
    printf("Enter the value after which you want to delete: ");
    scanf("%d", &val);

    Node *prev, *ptr;
    for (ptr = start, prev = NULL;
         ptr && ptr->data != val;
         prev = ptr, ptr = ptr->next) ;
    if (ptr == start) {		// if to be deleted from the first node
           delete_list(start);
           return NULL;
    }
    prev->next = NULL;		// end the list at the previous node
    // traverse the remaining nodes and delete them
    while (ptr) {
        prev = ptr->next;	// prev is repurposed to hold the value of next node
        free(ptr);	        // as the current node is deleted
        ptr = prev;
    }
    return start;
}

Node *delete_list(Node *start) {
    /* delete the entire linked list */
    Node *temp;
    while (start) {
        temp = start->next;
        free(start);
        start = temp;
    }
    return NULL;
}

Node *sort_list(Node *start) {
    /* sort the given linked list using insertion sort algo */
    int temp;
    Node *ptr1, *ptr2;
    for (ptr1 = start; ptr1; ptr1 = ptr1->next) {           // traverse the entire list
        for (ptr2 = ptr1->next; ptr2; ptr2 = ptr2->next) {  // from every index, travel upto last
            if (ptr2->data < ptr1->data) {             // and swap if value is less (find min)
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
        }
    }
    puts("List sorted successfully");
    return start;
}

Node *save_list(Node *start) {
    /* save the entire linked list in a file */
    char filename[FILENAME];
    printf("Enter the filename to save: ");
    readline(filename, FILENAME);

    FILE *savefile;
    if ((savefile = fopen(filename, "wb")) == NULL) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        return start;
    }

    // save the data in file
    for (Node *ptr = start; ptr; ptr = ptr->next)	     // traverse the list
        fwrite(&ptr->data, sizeof(int), 1, savefile);    // saving the data to file
    fclose(savefile);
    printf("Data saved in file: %s\n", filename);

    return start;
}	
    
Node *reload_list(Node *start) {
    /* reload the list from a previously generated file */
    char filename[FILENAME];
    printf("Enter the filename to reload: ");
    readline(filename, FILENAME);
    
    FILE *readfile;
    if ((readfile = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "Unable to open readfile %s\n", filename);
        return start;
    }
    delete_list(start); start = NULL;       // delete the previous list and start anew

    int temp;              		    // holds temporary data, also holds the failed read
    Node *new, *prev;
    while (fread(&temp, sizeof(int), 1, readfile)) {
        new = malloc(sizeof(Node));	// create node for every successful read
        new->data = temp;           // and save data
        if (start == NULL) start = new;
        else prev->next = new;
        prev = new;
    }
    prev->next = NULL;
    fclose(readfile);
    printf("Data reloaded from file %s\n", filename);

    return start;
}

int readline(char array[], int max) {
    /* read a line from stdin */
    int i = 0, ch;
    while (isspace(ch = getchar())) ; // skip leading whitespace
    do {
        if (i < max - 1)
            array[i++] = ch;
    } while ((ch = getchar()) != '\n');
    array[i] = '\0';
    return i;
}
