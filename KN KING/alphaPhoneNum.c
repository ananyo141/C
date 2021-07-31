// Translate an alphabetic input into phone number

#include <stdio.h>
#include <ctype.h>

int main() {
    printf("Enter the number: ");
    char digit = getchar();
    digit = toupper(digit);
    while (digit != '\n') {
        switch (digit) {
            case 'A': case 'B': case 'C':
                printf("%d", 2);
                break;
            case 'D': case 'E': case 'F':
                printf("%d", 3);
                break;
            case 'G': case 'H': case 'I':
                printf("%d", 4);
                break;
            case 'J': case 'K': case 'L':
                printf("%d", 5);
                break;
            case 'M': case 'N': case 'O':
                printf("%d", 6);
                break;
            case 'P': case 'Q': case 'R':
                printf("%d", 7);
                break;
            case 'S': case 'T': case 'U':
                printf("%d", 8);
                break;
            case 'W': case 'X': case 'Y':
                printf("%d", 9);
                break;
            default:
            printf("%c", digit);
        }

    digit = getchar();
    digit = toupper(digit);
    }
    printf("\n");

    return 0;
}