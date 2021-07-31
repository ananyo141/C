// Reverse the input message and print (using a pointer)
#include <stdio.h>

int main() {
    // input the message and store in array
    char c, message[50], *character;
    character = message;
    int len = 0;
    printf("Enter message: ");
    while ((c = getchar()) != '\n') {
        if (len++ > 50)
            break;

        *character = c;
        character++;
    }

    // Reverse the message
    for (char *reverse = message + len - 1; reverse >= message; reverse--)
        printf("%c", *reverse);
    printf("\n");

    return 0;
}