// Get the scrabble value of the input word

#include <stdio.h>
#include <ctype.h>

int main() {
    printf("Enter the scrabble word: ");
    int sum = 0;
    char letter;
    do {
        letter = getchar();
        letter = tolower(letter);
        switch (letter) {
            case 'a': case 'e': case 'i': case 'l': case 'n': case 'o': case 'r': case 's': case 't':  case 'u': 
                sum += 1;
                break;
            case 'd': case 'g': 
                sum += 2;
                break;
            case 'b': case 'c': case 'm': case 'p': 
                sum += 3;
                break;
            case 'f': case 'h': case 'v': case 'w': case 'y': 
                sum += 4;
                break;
            case 'k': 
                sum += 5;
                break;
            case 'j': case 'x': 
                sum += 8;
                break;
            case 'q': case 'z': 
                sum += 10;
                break;
        }
    } while (letter != '\n');

    printf("The scrabble value is %d\n", sum);

    return 0;
}