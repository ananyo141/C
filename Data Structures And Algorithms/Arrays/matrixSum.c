// Write a program to input two mxn matrices and then calculate 
// the sum of their corresponding elements and store it in a third mxn matrix.
#include <stdio.h>
#include "arrayUtils.h"

int main() {
    int m, n;
    printf("Enter m and n value: ");
    scanf("%d%d", &m, &n);
    double matrix1[m][n], matrix2[m][n], matrixSum[m][n];
    puts("First matrix:");
    readMatrix(m, n, matrix1);
    puts("Second matrix:");
    readMatrix(m, n, matrix2);

    // sum the two matrices
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matrixSum[i][j] = matrix1[i][j] + matrix2[i][j];
    
    // print formatted output
    printf("\n\n");
    printMatrix(m, n, matrix1);
    printf("%10c\n", '+');
    printMatrix(m, n, matrix2);
    printf("%10c\n", '=');
    printMatrix(m, n, matrixSum);

    return 0;
}
