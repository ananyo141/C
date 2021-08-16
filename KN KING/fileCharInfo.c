// Display the properties of text file provided on the command line
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// TODO: Count the number of characters 
// TODO: Count the number of words
// TODO: Count the number of lines
// TODO: Average char per word
// TODO: Avg word per line

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: fileCharInfo <filename>\n");
        exit(EXIT_FAILURE);
    }

    // open the file
    FILE *stream;
    if ((stream = fopen(argv[1], "r")) == NULL) {
        printf("File %s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    // Analyze the text file
    int ch;
    long ch_count = 0, word_count = 0, line_count = 0;
    while ((ch = getc(stream)) != EOF) {
        if (ch == ' ' || ch == '.') {
            while (ch == ' ' || ch == '.')
                ch = getc(stream);
            ungetc(ch, stream);   // put back the non-space character for further reading
            word_count++;
        }
        else if (isspace(ch)) 
            line_count++;
        
        else if (isdigit(ch) || isalpha(ch)) 
            ch_count++;
    }
    fclose(stream);

    // print results
    printf("%15s%15s\n", "Parameters", "Count");
    printf("%15s%15s\n", "----------", "-----");
    printf("%15s%15ld\n", "Characters", ch_count);
    printf("%15s%15ld\n", "Words", word_count);
    printf("%15s%15ld\n", "Lines", line_count);
    printf("%20s%10.2f\n", "Average Char/Word", ch_count/(float)word_count);
    printf("%20s%10.2f\n", "Average Word/Line", word_count/(float)line_count);

    return 0;
}
