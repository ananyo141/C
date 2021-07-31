// Validate if the command line user inputs are valid planet names
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLANETS 8

void tolowercase (char *string) {
    while (*string) {
        *string = tolower(*string);
        string++;
    }
}

int main(int argc, char *argv[]) {
    int i, j;
    char *planets[] = {"mercury", "venus", "earth", "mars", "jupiter", "saturn", "uranus", "neptune"};
    
    for (i = 1; i < argc; i++) {
        tolowercase(argv[i]);
        if (strcmp(argv[i], "pluto") == 0) {
            printf("%s is no longer a planet, just a dwarf one.\n", argv[i]);
            continue;
        }

        for (j = 0; j < NUM_PLANETS; j++) {
            if (strcmp(argv[i], planets[j]) == 0) {
                printf("%s is a planet\n", argv[i]);
                break;
            }
        }
        
        if (j == NUM_PLANETS)
            printf("%s is not a planet\n", argv[i]);
        
    }

    return 0;
}