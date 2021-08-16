// Make the contents of file uppercase and produce the results to stdout
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: fileUppercase <read_filename> <wrie_filename>\n");
        exit(EXIT_FAILURE);
    }

    FILE *fileR, *fileW;
    if ((fileR = fopen(argv[1], "r")) == NULL) {
        printf("The read file can't be opened\n");
        exit(EXIT_FAILURE);
    }

    if ((fileW = fopen(argv[2], "w")) == NULL) {
        printf("The file can't be opened\n");
        fclose(fileR);
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = getc(fileR)) != EOF) {
        putc(toupper(ch), fileW);
        fputc(toupper(ch), stdout);
    }
    fclose(fileR);
    fclose(fileW);
    
    return 0;
}
