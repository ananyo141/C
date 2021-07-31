// Find the number of characters in entered sentence.
#include <stdio.h>

int main() {
    int count = 0;
    char c;
    printf("Enter your sentence: ");
    while ((c = getchar()) != '\n') {
        if (c == ' ')
            continue;            
        count++;
    }
    printf("Your message was %d character(s) long.\n", count);

    return 0;
}