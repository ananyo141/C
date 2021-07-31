// Write a program that creates a crawling snake leaving alphabets in a grid.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#define GRID_HEIGHT 10
#define GRID_WIDTH 10

void printArray(char arr[GRID_WIDTH][GRID_HEIGHT]) {
    system("clear");
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) 
            printf("%c ", arr[i][j]);
        printf("\n");
    }
}

int main() {
    // Grid Array
    char alphaGrid[GRID_HEIGHT][GRID_WIDTH];
    // Initialize with '.' placeholders
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) 
            alphaGrid[i][j] = '.';
    }
    // Alphabet Array
    char alphabetSeries[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
                             'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    // seeding for rand
    srand((unsigned)time(NULL));

    // Initialization
    int currI = 0, currJ = 0;
    int alphabetIndex = 0;
    alphaGrid[currI][currJ] = alphabetSeries[alphabetIndex++];

    // Creating the main program loop
    while (1) {
        int topBlock = 0, belowBlock = 0, rightBlock = 0, leftBlock = 0;
        printArray(alphaGrid);
        int nextI, nextJ;
        int nextMove = rand() % 4;

        // Calculate blocks
        if (isalpha(alphaGrid[(currI-1) % 10] [currJ % 10]))
            topBlock = 1;
        if (isalpha(alphaGrid[(currI+1) % 10] [currJ % 10])) 
            belowBlock = 1;
        if (isalpha(alphaGrid[currI%10] [(currJ-1) % 10])) 
            leftBlock = 1;
        if (isalpha(alphaGrid[currI%10] [(currJ+1) % 10]))
            rightBlock = 1;

        // If no cells present adjascent, terminate
        if (topBlock && belowBlock && leftBlock && rightBlock)
            break;

        // If blocked by 3 sides and in a corner - break, to avoid infinity loop bug
        if ((topBlock + belowBlock + leftBlock + rightBlock >= 3) && (currI == 0 || currI == 9 || currJ == 0 || currJ == 9))
            break;
        
        // If at end of alphabet streak
        if (alphabetIndex > 25)
            break;
        
        // MOVE UP      
        if (nextMove == 0) {
            nextI = (currI - 1) % 10;
            nextJ = currJ % 10;  
        }
        
        // MOVE LEFT
        else if (nextMove == 1) {
            nextI = currI % 10;
            nextJ = (currJ - 1) % 10; 
        }

        // MOVE RIGHT
        else if (nextMove == 2) {
            nextI = currI % 10;
            nextJ = (currJ + 1) % 10;   
        }

        // MOVE DOWN
        else if (nextMove == 3) {
            nextI = (currI + 1 % 10);
            nextJ = currJ % 10;
        }
        
        // If accessing non-existent grid cells
        if (nextI < 0 || nextI > 9 || nextJ < 0 || nextJ > 9)
            continue;
        // If cell already occupied
        if (isalpha(alphaGrid[nextI][nextJ]))
            continue;
        
        alphaGrid[(nextI)][nextJ] = alphabetSeries[alphabetIndex];
        currI = nextI;
        currJ = nextJ;
        alphabetIndex++;
        sleep(1);
    }

    printf("Thank you for playing!\n");

    return 0;
}