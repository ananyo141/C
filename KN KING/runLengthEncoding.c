// Use run-length encoding to compress the contents of a file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILENAME_LEN 50

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: runLengthEncoding <filename>\n");
        exit(EXIT_FAILURE);
    }
    FILE *file, *fileOut;
    if ((file = fopen(argv[1], "rb")) == NULL) {
        printf("The file %s couldn't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    char savename[FILENAME_LEN];
    strcpy(savename, argv[1]);
    strcat(savename, ".rle");
    if ((fileOut = fopen(savename, "wb")) == NULL) {
        printf("File %s couldn't be opened\n", savename);
        fclose(file);
        exit(EXIT_FAILURE);
    }
    int ch, compare, counter;
    while ((ch = getc(file)) != EOF) {
        counter = 1;    // init counter
        compare = ch;   // current variable
        // count number of same bytes
        while ((ch = getc(file)) == compare) 
            counter++;
        ungetc(ch, file);

        // write the repetation count and the byte
        putc(counter, fileOut);
        putc(compare, fileOut);
    }
    // close opened files
    fclose(file);
    fclose(fileOut);

    return 0;
}
