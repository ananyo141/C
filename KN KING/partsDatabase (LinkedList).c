// Create the Parts Database but use linked list instead of array.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// macro definitions //
#define NAME_LEN 25
#define NAME_LEN 25
#define COMMAND_LEN 10

// part structure //
struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    struct part *next;
};

// global variable: points to the first part //
struct part *inventory = NULL; 

// function declarations //
struct part *find_part(int number);
int read_line(char str[], int n);
void insert(void);
void search(void);
void update(void);
void print(void);

int main() {
    char command[COMMAND_LEN + 1]; // store the input command
    void (*available_commands[])(void) = {insert, search, update, print}; // array of available function pointer
    enum command_enum {INSERT, SEARCH, UPDATE, PRINT} command_val;
    for (;;) {
        printf("Enter Command: ");
        read_line(command, COMMAND_LEN);

        if (strcmp(command, "insert") == 0) available_commands[INSERT]();
        else if (strcmp(command, "search") == 0) available_commands[SEARCH]();
        else if (strcmp(command, "update") == 0) available_commands[UPDATE]();
        else if (strcmp(command, "print") == 0) available_commands[PRINT]();
        else if (strcmp(command, "quit") == 0) return 0;
        else printf("Invalid command\n");
    }
    printf('\n');
}

// find a part from the linked list and return the struct pointer
struct part *find_part(int number) {
    struct part *p;
    // search for number
    for(p = inventory; 
        p != NULL && number > p->number;
        p = p->next)   ;
    if (p != NULL && number == p->number)
        return p;
    return NULL;
}

// prompt and insert details into the inventory list
void insert(void) {
    struct part *cur, *prev, *new_node;

    new_node = malloc(sizeof(struct part));
    if (new_node == NULL) {
        printf("Database is full, can't add more parts\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &new_node->number);

    // find the position to insert the node (according to part number)
    for (cur = inventory, prev = NULL;
         cur != NULL && new_node->number > cur->number;
         prev = cur, cur = cur->next) ;
    
    // if part number is equal, i.e, already exists
    if (cur != NULL && new_node == cur->number) {
        printf("Part already exists.\n");
        free(new_node);
        return;
    }

    // insert new part information in the new node 
    printf("Enter part name: ");
    read_line(new_node->name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", new_node->on_hand);

    // rewiring the nodes at corresponding position to refer to new node
    // to maintain sort
    new_node->next = cur;
    if (prev == NULL)
        inventory = new_node;
    else
        prev->next = new_node;
}

// prompt the user for part number and searches in the database
void search(void) {
    int number;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL) {
        printf("Part name: %s\n", p->name);
        printf("Quantity on hand: %d\n", p->on_hand);
    } else 
        printf("Part not found.\n");
}

// update the part in database
void update(void) {
    int number, change;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL) {
        printf("Enter the change in quantity on hand: ");
        scanf("%d", &change);
        p->on_hand += change;
    } else 
        printf("Part not found.\n");
}

// print the list of all parts in the database
void print(void) {
    struct part *p;

    printf("Part Number      Part Name                 "
           "Quantity on Hand\n");

    for (p = inventory; p != NULL; p = p->next) 
        printf("%5d            %-26s%8d\n", p->number, p->name, p->on_hand);
}

// read string from stdin
int read_line(char str[], int n) {
    int ch, i = 0;
    
    while (isspace(ch = getchar())) ;
    while (ch != '\n' && ch != EOF) {
        if (i < n)
            str[i++] = ch;
        ch = getchar();
    }
    str[i] = '\0';
    return i;
}
