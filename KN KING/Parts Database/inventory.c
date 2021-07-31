#include <stdio.h>
#include <string.h>
#include "readline.h"
#include "tools.h"

// variable definition
struct part inventory[MAX_PARTS];

int main() {
    char command[COMMAND_LEN + 1];
    for (;;) {
        printf("Enter Command: ");
        read_line(command, COMMAND_LEN);
        if (strcmp(command, "insert") == 0) insert();
        else if (strcmp(command, "search") == 0) search();
        else if (strcmp(command, "update") == 0) update();
        else if (strcmp(command, "print") == 0) print();
        else if (strcmp(command, "quit") == 0) return 0;
        else printf("Invalid command\n");
    }

    return 0;
}