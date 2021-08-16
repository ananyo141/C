// Concatenate the text files given in the command line
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: fcat <filenames>...\nLast filename should be the output filename\n");
        exit(EXIT_FAILURE);
    }

    int ch;
    char *outputFilename = argv[argc - 1];
    FILE *file, *fileOutput;
    if ((fileOutput = fopen(outputFilename, "w")) == NULL) {
        printf("Output File %s can't be opened\n", outputFilename);
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc - 1; i++) {
        if ((file = fopen(argv[i], "r")) == NULL) {
            printf("File %s can't be opened\n", argv[i]);
            continue;
        }
        while ((ch = getc(file)) != EOF) 
            putc(ch, fileOutput);
        fprintf(fileOutput, "\n\n*** End of File - %s ***\n\n", argv[i]);
        fclose(file); // close the opened stream
    }

    fclose(fileOutput); // close output stream
    printf("File concatenated and saved as %s\n", outputFilename);

    return 0;
}
