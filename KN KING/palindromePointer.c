// Check if a sentence is a palindrome or not
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

// This takes a string input from the user
int analyzeMessage(char *a, int limit) {
    char c;
    int len = 0;
    while ((c = tolower(getchar())) != '\n') {
        if (c == ',' || c == '.' || c == ' ' || c == '!' || c == '?')
            continue;
        if (len++ >= limit)
            return len;
        
        *a++ = c;
    }

    return len;
}   

int main() {
    char message[50];
    printf("Enter the sentence: ");
    int length = analyzeMessage(message, 50);
    bool isPalindrome = true;
    
    int reverse = 0;
    for (char *i = message; i < message + length; i++) 
        if (*i != *(message + length - 1 - reverse++))
            isPalindrome = false;

    if (isPalindrome)
        printf("The sentence is palindrome\n");
    else
        printf("The sentence is not palindrome\n");

    return 0;
}