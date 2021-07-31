// Encode a message using that reads a message entered by user and translates to BIFF-speak
#include <stdio.h>
#include <ctype.h>

int main() {
    char message[30];
    printf("Enter message: ");
    fgets(message, 30, stdin);

    // Converts message to uppercase
    for (int i = 0; message[i]; i++) 
        message[i] = toupper(message[i]);

    for (int i = 0; message[i] != '\n'; i++) {
        char toPrint;
        switch (message[i]) {
            case 'A': toPrint = '4'; break;
            case 'B': toPrint = '8'; break;
            case 'E': toPrint = '3'; break;
            case 'I': toPrint = '1'; break;
            case 'O': toPrint = '0'; break;
            case 'S': toPrint = '5'; break;
            default: toPrint = message[i]; break;
        }
        printf("%c", toPrint);
    }
    // print excessive exclamations
    for (int i = 0; i < 10; i++)
        printf("!");
    printf("\n");
    
    return 0;
}