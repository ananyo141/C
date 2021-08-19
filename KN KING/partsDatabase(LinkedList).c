// Create the Parts Database but use linked list instead of array.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// macro definitions //
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
void save(void);
void restore(void);

int main() {
    char command[COMMAND_LEN + 1]; // store the input command
    void (*available_commands[])(void) = {insert, search, update, print, save, restore}; // array of available function pointer
    enum command_enum {INSERT, SEARCH, UPDATE, PRINT, SAVE, RESTORE} command_val;
    for (;;) {
        printf("Enter Command: ");
        read_line(command, COMMAND_LEN);

        if      (strcmp (command, "insert" ) == 0)  available_commands[INSERT] ();
        else if (strcmp (command, "search" ) == 0)  available_commands[SEARCH] ();
        else if (strcmp (command, "update" ) == 0)  available_commands[UPDATE] ();
        else if (strcmp (command, "print"  ) == 0)  available_commands[PRINT]  ();
        else if (strcmp (command, "save"   ) == 0)  available_commands[SAVE]   ();    
        else if (strcmp (command, "restore") == 0)  available_commands[RESTORE]();
        else if (strcmp (command, "exit"   ) == 0)  {
            puts("\n*** Thank you for using Parts Database written in C ***\n");
            return 0;                              
        }
        else
            puts("Invalid command");
    }
    printf("\n");
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
    if (cur != NULL && new_node->number == cur->number) {
        printf("Part already exists.\n");
        free(new_node);
        return;
    }

    // insert new part information in the new node 
    printf("Enter part name: ");
    read_line(new_node->name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &new_node->on_hand);

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

void save(void) {
    FILE *savefile;
    char savefilename[FILENAME_MAX];
    printf("Enter the save filepath: ");
    read_line(savefilename, FILENAME_MAX);
    if ((savefile = fopen(savefilename, "wb")) == NULL) {
        printf("File %s couldn't be opened for writing\n", savefilename);
        exit(EXIT_FAILURE);
    }
    // write data to save file
    // visit each node, write part number, name and quantity
    for (struct part *p = inventory; p != NULL; p = p->next) {
        fwrite(&p->number, sizeof(int), 1, savefile);                  // write part number
        fwrite(&p->name, sizeof(char), strlen(p->name) + 1, savefile); // write part name
        fwrite(&p->on_hand, sizeof(int), 1, savefile);                 // write quantity
    }
    puts("Savefile generated");

    fclose(savefile);
}

void restore(void) {
    FILE *readfile;
    char readfilename[FILENAME_MAX];
    printf("Enter the restore filepath: ");
    read_line(readfilename, FILENAME_MAX);
    if ((readfile = fopen(readfilename, "rb")) == NULL) {
        printf("File %s couldn't be read\n", readfilename);
        exit(EXIT_FAILURE);
    }
    // destroy the existing list
    for (struct part *next_p, *p = inventory; p != NULL; p = next_p) {
        next_p = p->next;
        free(p);
    }
    inventory = NULL;   // inventory is now null
    // rebuild the linked list from the entered file
    struct part *curr, *prev = inventory;
    for (;;) {
        struct part *curr = malloc(sizeof(struct part));
        if (curr = NULL) {
            fprintf(stderr, "Unable to allocate memory. Terminating...\n");
            exit(EXIT_FAILURE);
        }
        int temp_numb, ch, i = 0;
        if (!(fread(&temp_numb, sizeof(int), 1, readfile))) {
            if (prev != NULL)
                prev->next = NULL;
            free(curr); // list ends
            break;
        }
        curr->number = temp_numb;
        while ((ch = getc(readfile)) != '\0')
            curr->name[i++] = ch;
        curr->name[i] = '\0';
        fread(&curr->on_hand, sizeof(int), 1, readfile);
        if (prev = NULL) 
            inventory = curr;
        else 
            prev->next = curr;
        prev = curr;
    }
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
