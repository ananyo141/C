#include <stdio.h>
#include <string.h>
#include "readline.h"
#include "tools.h"

// variable definition
struct part inventory[MAX_PARTS];

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

    return 0;
}