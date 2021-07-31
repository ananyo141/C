#include <stdio.h>
#include "word.h"

// read a character and compress newlines and tabs
int read_char (void) {
    int ch = getchar();
    return (ch == '\n' || ch == '\t') ? ' ' : ch;
}

// read a word in the input word array
int read_word (char *word, int len) {
    int ch, pos = 0;
    while ((ch = getchar()) == ' ') ;   // skip leading spaces
    while (ch != ' ' && ch != EOF) {
        if (pos == len - 1) {
            word[pos++] = '*';
            continue;
        }
        if (pos < len)
            word[pos++] = ch;
        ch = read_char();
    }
    word[pos] = '\0';
    return pos;
}