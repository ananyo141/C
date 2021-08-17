// Decode the file compressed with runLengthEncoding
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILENAME_LEN 50

// function declarations //
void slicer (const char *str, char *returnStr, int start, int stop);
void splitext(const char *filepath, char *head, char *ext);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: runLengthDecoding <filename.rle>\n");
        exit(EXIT_FAILURE);
    }
    FILE *fileInp, *fileOut;
    if ((fileInp = fopen(argv[1], "rb")) == NULL) {
        printf("The file %s couldn't be opened.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char savefilename[FILENAME_LEN], extension[FILENAME_LEN];
    splitext(argv[1], savefilename, extension);
    if (strcmp(extension, ".rle") != 0) {
        printf("The file %s with extension '%s' is not a valid compressed format\n"
               "This program supports files compressed with runLengthEncoding program\n", argv[1], extension); 
        exit(EXIT_FAILURE);
    }
    if ((fileOut = fopen(savefilename, "wb")) == NULL) {
        printf("The file %s couldn't be opened\n", savefilename);
        fclose(fileInp);
        exit(EXIT_FAILURE);
    }
    int counter, ch;
    for(;;) {
        counter = getc(fileInp);    // get the counter byte
        if (counter == EOF) break;  // break if eof
        ch = getc(fileInp);         // get the character byte
        // write the repeated number of bytes
        for (int i = 0; i < counter; i++) 
            putc(ch, fileOut);
    }
    fclose(fileInp);
    fclose(fileOut);
    printf("File %s successfully decompressed and saved as %s\n", argv[1], savefilename);

    return 0;
}

// function definitions //
void slicer (const char *str, char *returnStr, int start, int stop) {   // stop is non-inclusive
    while (start < stop) 
        *returnStr++ = str[start++];
    *returnStr = '\0';          // close it off with null-terminator
}

void splitext(const char *filepath, char *head, char *ext) {
    int extIndex = strrchr(filepath, '.') - filepath;
    slicer(filepath, head, 0, extIndex);
    slicer(filepath, ext, extIndex, strlen(filepath));
}
