// Find the number of vowels in a sentence.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int count = 0;  
    char vowels[] = "aeiou";
    char c;
    printf("Enter the sentence: ");
    while ((c = tolower(getchar()) ) != '\n') {
        if (strchr(vowels, c) != NULL) {
            printf("Vowel found: %c\n", c);
            count++;
        }
    }
    printf("Vowels found in your message: %d\n", count);

    return 0;
}