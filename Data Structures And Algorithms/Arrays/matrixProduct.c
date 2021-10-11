// Write a program to input two mxn matrices and then calculate the sum of their
// corresponding elements and store it in a third mxn matrix.
#include <stdio.h>
#include "arrayUtils.h"

int main() {
    int m1, n1, m2, n2;
    printf("Enter m, n value for matrix1: ");
    scanf("%d%d", &m1, &n1);
    double matrix1[m1][n1];
    readMatrix(m1, n1, matrix1);

    printf("Enter m, n value for matrix2: ");
    scanf("%d%d", &m2, &n2);
    if (n1 != m2) {
        printf("The matrix rule that n1 (%d) of first matrix should be equal "
               "to m2 (%d) of second matrix is not satisfied here.\n", n1, m2);
        return 1;   // exit failure
    }
    double matrix2[m2][n2];
    readMatrix(m2, n2, matrix2);


    // create and construct the product matrix            
    double matrixProd[m1][n2];
    for (int i = 0; i < m1; i++) {                 // i emulates the rows of the product matrix (m1)
        for (int j = 0; j < n2; j++) {             // j emulates the columns of the product matrix (n2)
            matrixProd[i][j] = 0;                  // initialize the cell
            for (int k = 0; k < m2; k++)           // k ranges to the common factor of columns and rows
                matrixProd[i][j] += matrix1[i][k] * matrix2[k][j]; // in the matrices (n1 == m2)
        }                                                             
    }                                                             

    puts("Result:");
    printMatrix(m1, n1, matrix1);
    printf("%10c\n", '*');
    printMatrix(m2, n2, matrix2);
    printf("%10c\n", '=');
    printMatrix(m1, n2, matrixProd);

    return 0;
}
