#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

// macro definitions
#define NAME_LEN 25
#define MAX_PARTS 100
#define COMMAND_LEN 10
#define PARTS_SPACE_INCREMENT 1
#define DEBUG(x) printf(#x " = %d\n", x)

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};

// function declarations
int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void expand(int req_space);
bool is_full(void);
int read_line(char str[], int n);

// variable definition
struct part *inventory;
int space_available = PARTS_SPACE_INCREMENT;

int main() {
    // make initial space for inventory 
    inventory = malloc (sizeof(struct part) * PARTS_SPACE_INCREMENT);
    if (inventory == NULL) {
        printf("Heap memory failure, failed to initialize database\n"); 
        exit(EXIT_FAILURE);
    }

    char command[COMMAND_LEN + 1]; // store the input command
    void (*available_commands[])(void) = {insert, search, update, print}; // array of available function pointer
    enum command_enum {INSERT, SEARCH, UPDATE, PRINT} command_val;
    for (;;) {
        printf("Enter Command: ");
        read_line(command, COMMAND_LEN);

        if      (strcmp(command, "insert") == 0)   available_commands[INSERT]();
        else if (strcmp(command, "search") == 0)   available_commands[SEARCH]();
        else if (strcmp(command, "update") == 0)   available_commands[UPDATE]();
        else if (strcmp(command, "print" ) == 0)   available_commands[PRINT]();
        else if (strcmp(command, "exit"  ) == 0)   {printf("\n*** Thank you for using Parts Database written in C ***\n\n"); return 0;}
        else                                       printf("Invalid command\n");

        if (is_full()) {
            printf("Extending storage for more storage allocation\n");
            expand(PARTS_SPACE_INCREMENT);
        }
    }

    return 0;
}

int num_parts = 0;

int find_part(int number) {
    for (int i = 0; i < num_parts; i++)
        if (inventory[i].number == number)
            return i;
    return -1;
}

void insert(void) {
    int part_number;
    if (is_full()) {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);
    if (find_part(part_number) != -1) {
        printf("Part already exists.\n");
        return;
    }
    int insert_pos;

    // find the appropriate position to insert the part
    for (insert_pos = 0; insert_pos < num_parts; insert_pos++) 
        if (part_number <= inventory[insert_pos].number)
            break;

    // scoot the trailing parts to make space
    for (int i = num_parts; i >= insert_pos; i--)
        inventory[i + 1] = inventory[i];

    // insert at the position
    inventory[insert_pos].number = part_number;
    printf("Enter part name: ");
    read_line(inventory[insert_pos].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[insert_pos].on_hand);
    num_parts++;
}

void search(void) {
    int i, number;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0) {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
    } else 
        printf("Part not found\n");
}

void update(void) {
    int i, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    } else
        printf("Part not found\n");
}

void print(void) {
    printf("Part Number      Part Name                 "
           "Quantity on Hand\n");

    for (int i = 0; i < num_parts; i++) 
        printf("%5d            %-26s%8d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
}

// Expand the storage for inventory array as needed
void expand(int req_space) {
    space_available += req_space;
    inventory = realloc(inventory, sizeof(struct part) * space_available);
    if (inventory == NULL) {
        printf("Heap memory failure, no space left to allocate\n"); 
        exit(EXIT_FAILURE);
    }
    DEBUG(space_available);
}

// check if the array is full
bool is_full(void) {
    return (space_available == num_parts) ? true : false;
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
