#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "readline.h"
#include "tools.h"
#define DEBUG(x) printf(#x " = %d\n", x)

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
    printf(" Part Number     Part Name                 "
           "Quantity on Hand\n");
    printf("------------    -----------                "
           "----------------\n");

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
    return (space_available == num_parts + 1) ? true : false;
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
    // save the dynamically allocated array in the file
    if (fwrite(inventory, sizeof(struct part), num_parts + 1, savefile) == num_parts + 1)
        puts("Inventory successfully saved");
    else
        puts("Error writing to savefile");

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
    // load the data into memory
    num_parts = fread(inventory, sizeof(struct part), space_available, readfile);
    num_parts--;    // as num_parts is 0-indexed
    printf("Parts read: %d\n", num_parts);

    fclose(readfile);
}
