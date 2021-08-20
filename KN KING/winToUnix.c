// Convert a Windows text file with EOL set as '\r\n' (Carriage Return - Line feed) and EOF as '\x1a' (substitute
// character) to Unix text file with EOL set as '\n' (Line Feed) and no EOF character.
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: winToUnix <inputfile> <outputfile>\n");
        return 1;
    }

    FILE *input, *output;
    if ((input = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Unable to open file %s\n", argv[1]);
        return 1;
    }
    if ((output = fopen(argv[2], "wb")) == NULL) {
        fprintf(stderr, "Unable to open file %s\n", argv[2]);
        fclose(input);
        return 1;
    }

    int ch;
    while ((ch = getc(input)) != EOF) {
        if (ch == '\r' || ch == 26)
            continue;
        putc(ch, output);
    }

    fclose(input);
    fclose(output);


    return 0;
}
