// Convert a Unix text file with EOL set as '\n' (Line Feed) to a Windows text file
// with EOL set as '\r\n' (Carriage Return - Line Feed) and EOF character ('\x1a', ASCII value 26)
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: unixToWin <inputfile> <outputfile>\n");
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
        if (ch == '\n')
            putc('\r', output);
        putc(ch, output);
    }

   /*************************************************************************
    *      this bit is optional and commented out as it causes problems     *        
    *putc('\n', output);      // since eof should be the first in a line    *       
    *putc('\x1a', output);                                                  *                 
    *************************************************************************/   

    fclose(input);
    fclose(output);
    puts("File successfully converted to Windows Format with CRLF End-Of-Line-Sequence");

    return 0;
}
