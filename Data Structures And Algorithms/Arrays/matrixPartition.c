// Write a program to fill a square matrix with values zero on the diagonals,
// 1 on the upper right triangle, and -1 on the lower left triangle.
#include <stdio.h>
#include "arrayUtils.h"

int main() {
    int m;
    printf("Enter the matrix length: ");
    scanf("%d", &m);
    double sqMatrix[m][m];
    readMatrix(m, m, sqMatrix);
    printf("\n");

    for (int i = 0; i < m; i++) {
        sqMatrix[i][i] = 0;     // make the diagonals 0
        for (int j = i+1; j < m; j++) sqMatrix[i][j] =  1;  // set upper rectangle to  1
        for (int j = 0;   j < i; j++) sqMatrix[i][j] = -1;  // set lower rectangle to -1
    }
    printMatrix(m, m, sqMatrix);

    return 0;
}
