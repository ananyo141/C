// Compare the user input words and find the word that would come first and last in a dictionary.
#include <stdio.h>
#include <string.h>

int main() {
    char word[20];
    char smallest[20] = "uninitiated";
    char largest[20] = "uninitiated";
    
    for (;;) {
        printf("Enter word: ");
        scanf("%s", word);
        // initiator for the first loop
        if (strcmp(smallest, "uninitiated") == 0) {
            strcpy(smallest, word);
            strcpy(largest, word);
        }
        if (strcmp(smallest, word) > 0) 
            strcpy(smallest, word);
        if (strcmp(largest, word) < 0) 
            strcpy(largest, word);
        // stop if user enters four-lettered word
        if (strlen(word) == 4)
            break;
    }
    printf("\nSmallest Word: %s\n", smallest);
    printf("Largest Word: %s\n", largest);

    return 0;
}