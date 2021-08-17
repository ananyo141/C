// Display the contents of a file as bytes and characters.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: binaryFileViewer <filename>\n");
        exit(EXIT_FAILURE);
    }

    FILE *file;
    if ((file = fopen(argv[1], "rb")) == NULL) {
        printf("Cannot open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    int ch;
    printf("%7s  %30s  %10s\n", "Offset", "Bytes", "Characters");


    return 0;
}
