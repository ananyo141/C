// This program receives a sentence from the user and reverses word by word.
// This program is not cleanly written, consider improving and organising further if possible.
#include <stdio.h>

int main() {
    char sentence[50];
    char c, terminatingChar;
    int sentenceIndex = 0;
    int messageLen = 0;
    printf("Enter the sentence you want to reverse: ");
    while ((c = getchar()) != '\n') {
        if (c == '?' || c == '.' || c == '!')
            break;
        sentence[sentenceIndex] = c;
        sentenceIndex++;
        messageLen++;
    }
    if (c != '\n') 
    terminatingChar = c;
    else
    terminatingChar = ' ';

    // reverse the sentence
    printf("Reversal of Sentence:");
    int wordLen = 0;
    for (int i = messageLen - 1; i >= 0; i--) {
        if (sentence[i] != ' ') {
            wordLen++;
            continue;
        }
        for (int j = i; j <= (i + wordLen); j++) {
            putchar(sentence[j]);
        }
        wordLen = 0;
    }
    // print the first word
    putchar(' ');
    for(int i = 0; i < wordLen; i++) {
        putchar(sentence[i]);
    }

    printf("%c\n", terminatingChar);
        
    return 0;
}