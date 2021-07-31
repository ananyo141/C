// Match the brackets and parenthesis entered by the user to see if they are nested properly or not.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 25

int main() {
    short flag = 0, top = 0;
    char input, *match, stack[MAX_SIZE];
    char *openBrace = "({[";
    char *closedBrace = ")}]";

    printf("Enter parenthesis and/or braces: ");
    for (;;) {
        input = getchar();
        if (input == '\n')
            break;
        if (top == MAX_SIZE) {
            printf("Stack overflowed, terminated\n");
            exit(EXIT_FAILURE);
        }
        if (!flag)
            if (strchr(openBrace, input) != NULL || strchr(closedBrace, input) != NULL)
                flag = 1;
        if (strchr(openBrace, input) != NULL)
            stack[top++] = input;
        else if ((match = strchr(closedBrace, input)) != NULL) {
            int index = match - closedBrace;
            if (stack[--top] == openBrace[index])
                continue;
            else {
                printf("The braces don't match.\n");
                exit(EXIT_SUCCESS);
            }
        }
    }
    if (top)
        printf("Braces unterminated or not closed properly\n");
    else if (flag)
        printf("The braces match and are properly nested.\n");
    else
        printf("No brackets entered\n");

    return 0;
}