// Read the dates from a file containing one date in a line separated by spaces and characters,
// and output them in a standardized format.
#include <stdio.h>
#include <ctype.h>
#define DATE_BUFFER 20

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: dateStandardizeFile <datefilename>\n");
        return 1;
    }

    FILE *datefile;
    if ((datefile = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "File %s couldn't be opened.\n", argv[1]);
        return 1;
    }

    // read each line for 10 digits
    int ch, buffer[DATE_BUFFER], digits_read = 0;
    while ((ch = getc(datefile)) != EOF) {
        if (ch == '\n') {
            if (digits_read = 10) {
                for (int i = 0; i < 10; i++) {
                    if (i == 0)
                        putchar('(');
                    else if (i == 3)
                        printf(") ");
                    else if (i == 6)    
                        putchar('-');
                    printf("%c", buffer[i]);
                }
                printf("\n");

            digits_read = 0;
            }
        }

        if (isdigit(ch))
            buffer[digits_read++] = ch;
    }
    fclose(datefile);

    return 0;
}        
