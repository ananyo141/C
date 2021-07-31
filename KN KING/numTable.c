// Write a program that prints a table of the input number and pauses every 12 values for further printing

#include <stdio.h>

int main() {
    long num;
    printf("Enter the number you want to print table: ");
    scanf("%ld", &num);      //  newline left by scanf()

    // As advised, it's dangerous to mix scanf() and getchar() in same program, as scanf peeks at newlines
    // and spaces, which can cause getchar to consume them when least expected.
    for (int i = 0; ; i++) {
        if ( i == 0 && getchar() == '\n') {     // employed a small workaround that checks if zero (we don't need) and getchar() consumes the '\n'
            continue;
        }

        printf("%4ld  x%5d    =%8ld\n", num, i, num * i);
        if ((i % 12) == 0) {
            printf("Press Enter to continue: ");
            if (getchar() == '\n'){
                continue;
            }
            else {
                break;
            }
        }
    }
    
    printf("You exited the program.\n");

    return 0;
}