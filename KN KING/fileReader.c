#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int ch;
    char *filename = argv[1];
    FILE *file;     // file pointer to accomodate the file object

    if (argc != 2) {
        printf("Usage: fileReader <filepath>");
        exit(EXIT_FAILURE);
    }
    
    // if the file can't be opened
    if((file = fopen(filename, "r")) == NULL) {
        printf("Cannot open %s", filename);
        exit(EXIT_FAILURE);
    }
    // print the contents of the file to stdout
    while((ch = getc(file)) != EOF) 
        putchar(ch);
    // close the file
    fclose(file);

    return 0;
} 
