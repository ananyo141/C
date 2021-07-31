// Find out the magic square
#include <stdio.h>
#define EMPTY_CELL -23

int main() {
    int size;
    // Only works for 5
    printf("Enter the size of the square(: ");
    scanf("%d", &size);
    int magicSquare[size][size];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) 
            magicSquare[i][j] = EMPTY_CELL;
    }

    int currI = 0;
    int currJ = size / 2;
    int nextI, nextJ;

    for (int i = 1; i <= (size * size); i++) {
        magicSquare[currI][currJ] = i;
        nextI = (currI - 1) < 0 ? currI - 1 + size : currI - 1;
        nextJ = (currJ + 1) >= size ? currJ + 1 - size : currJ + 1;
        if (magicSquare[nextI][nextJ] != EMPTY_CELL) {
            currI = (currI + 1) >= size ? currI + 1 - size : currI + 1;
            currJ = currJ;
        }
        else {
            currI = nextI;
            currJ = nextJ;
        }
    }

    for (int i = 0; i < (int) (sizeof(magicSquare)/ sizeof(magicSquare[0])); i++) {
        for (int j = 0; j < (int) (sizeof(magicSquare[0])/sizeof(magicSquare[0][0])); j++) {
            printf("%2d ", magicSquare[i][j]);
        }
        printf("\n");
    }

    return 0;
}