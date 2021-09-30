// Transpose of a matrix
#include <stdio.h>
#include "arrayUtils.h"

int main() {
    int m, n;
    printf("Enter row(m) and column(n) number: ");
    scanf("%d%d", &m, &n);

    double array[m][n];
    puts("Enter elements:");
    readMatrix(m, n, array);

    double transpose[n][m];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            transpose[j][i] = array[i][j];
    
    printMatrix(m, n, array);
    printMatrix(n, m, transpose);

    return 0;
}
