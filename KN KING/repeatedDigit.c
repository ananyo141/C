// Find if the number contains repeated digits.
#include <stdio.h>
#include <stdbool.h>

int main() {
    int howmany;
    bool repeatFound;
    // Array to keep the numbers
    int number[20];
    // Array to keep track of the number found
    int numTracker[10] = {false};   // fills in the remaining slots with 0
    
    printf("Enter how many number you want to find: ");
    scanf("%d", &howmany);
    printf("Enter the number you want to find if contains repeated digits: ");

    for (int i = 0; i < howmany; i++) 
        scanf("%1d",&number[i]);
    
    for (int i = 0; i < howmany; i++) {
        if (numTracker[number[i]])
            continue;
        else
            numTracker[number[i]] = true;

        int repeats = 1;
        for (int j = i+1; j < howmany; j++) {
            if (number[i] == number[j]) 
                repeats++;
        }
        if (repeats > 1) {
            printf("%d appears %d times.\n", number[i], repeats);
            repeatFound = true;
        }
    }
    if (!repeatFound)
        printf("No repeats found\n");

    return 0;
}