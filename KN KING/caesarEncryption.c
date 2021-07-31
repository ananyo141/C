// This creates a Julius Ceasar Type encryption that prompts the user for shift number.
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

int main() {
    // give choice to encrypt or decrypt
    char choice[10];
    printf("Do you want to encrypt a message or decrypt a message?: ");
    scanf("%s", choice);

    char sentence[40];
    int messageLen, shiftLen;
    char encodingKey[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
                          'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    printf("Enter the sentence: ");
    getchar();
    for (int i = 0, c; (c = getchar()) != '\n'; i++) {
        sentence[i] = c;
        messageLen = i;
    }
    messageLen++;

    printf("Enter the shift length(1-25): ");
    scanf("%d", &shiftLen);
    if (strcmp(choice, "decrypt") == 0) 
        shiftLen = 26 - shiftLen;
    

    for (int i = 0; i < messageLen; i++) {
        bool lower = false;
        char currChar = sentence[i];
        if (islower(currChar))
        lower = true;

        if (!isalpha(currChar)) {
            putchar(currChar);
            continue;
        }
        currChar = toupper(currChar);
        char encodedChar = encodingKey[(currChar-'A'+shiftLen) %26];
        if (lower)
        encodedChar = tolower(encodedChar);
        putchar(encodedChar);
    }
    printf("\n");

    return 0;
}