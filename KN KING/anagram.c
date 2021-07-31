// Find if two numbers entered by the user are anagrams.
#include <stdio.h>
#include <ctype.h>

int main() {
    char firstWord[20], secondWord[20];
    int charMapping[26] = {0};
    printf("Enter the first word: ");
    scanf("%s", firstWord);
    // Get the character mapping for the first word
    for (int i = 0; firstWord[i] != '\0'; i++) {
        int index;
        if (isupper(firstWord[i]))
        index = firstWord[i] - 'A';
        else
        index = firstWord[i] - 'a';

        charMapping[index] += 1;
    }

    printf("Enter the second word: ");
    scanf("%s", secondWord);
    // Balance the character mapping with the second word
    for (int i = 0; secondWord[i] != '\0'; i++) {
        int index;
        if (isupper(secondWord[i]))
        index = secondWord[i] - 'A';
        else
        index = secondWord[i] - 'a';

        charMapping[index] -= 1;
    }

    // Check if the array is back to initial all-zero state
    int isAnagram = 1;
    for (int i = 0; i < (int)(sizeof(charMapping)/sizeof(charMapping[0])); i++) {
        if (charMapping[i]) {   // anything non-zero
        isAnagram = 0;
        break;
        }
    }

    if (isAnagram)
        printf("The two words %s and %s are anagrams.", firstWord, secondWord);
    else
        printf("The two words %s and %s are not anagrams.", firstWord, secondWord);
    
    printf("\n");
    
    return 0;
}