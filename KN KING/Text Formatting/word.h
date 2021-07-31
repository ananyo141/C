// protecting header against multiple inclusions
#ifndef WORD_H
#define WORD_H
#define MAX_WORD_LEN 20

// read a character and compress newlines and tabs
int read_char(void);

// read a word in the input word array
int read_word(char *word, int len);

#endif