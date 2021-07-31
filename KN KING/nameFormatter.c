// Format the input name as <Last Name>, <First Initial>.

#include <stdio.h>

int main() {
    char initial, c;
    printf("Enter your name: ");
    
    while ((initial = getchar()) == ' ');
    while((c = getchar()) != ' ');      // Loop with null body to skip over first name
    while ( (c = getchar()) != '\n') {
        if (c == ' ') {

            // skip over any excess whitespace,
            while( (c = getchar()) == ' ');     
            if (c == '\n')                       // perform newline validation or '\n' gets consumed
                break;
            putchar(' ');                        // and replace with single space.
        }
        putchar(c);
    }
    
    printf(", %c.\n", initial);

    return 0;
}