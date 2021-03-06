#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "readline.h"
#include "tools.h"

// variable definition
struct part *inventory;
int space_available = PARTS_SPACE_INCREMENT;

int main() {
    // make initial space for inventory 
    inventory = malloc (sizeof(struct part) * PARTS_SPACE_INCREMENT);
    if (inventory == NULL) {
        puts("Heap memory failure, failed to initialize database"); 
        exit(EXIT_FAILURE);
    }

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

        if (is_full()) {
            puts("Extending storage for more storage allocation");
            expand(PARTS_SPACE_INCREMENT);
        }
    }

    return 0;
}
