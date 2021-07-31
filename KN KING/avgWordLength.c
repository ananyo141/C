// Find the average word length of a sentence.
#include <stdio.h>

int main() {
    int wordCount = 0, letterCount = 0;
    char c;
    printf("Enter your sentence: ");
    while ((c = getchar()) != '\n') {
        // skip punctutation
        if (c == '.' || c == ',' || c == '!' || c == '?' || c == '\'' || c == '\"' || c == ':' || c == ';')
            continue;

        if (c == ' ') {
            // skip over notorious multiple spaces
            while ((c = getchar()) == ' ');     
            wordCount++;
        }
        letterCount++;
    }

    // compensate for word loss as loop ended at newline
    wordCount++;                                
    float avg = letterCount / (float) wordCount;

    printf("Total Letters = %d\nWord Count = %d\n", letterCount, wordCount);
    printf("Average word length = %.1f\n", avg);

    return 0;
}