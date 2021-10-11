// Write a program to read and display a 3x3 matrix(using pointer notation)
#include <stdio.h>
void readMatrix(int m, int n, double (*matrix)[n]);
void printMatrix(int m, int n, double (*matrix)[n]);

int main() {
    int m;
    printf("Enter value of m: ");
    scanf("%d", &m);
    printf("\n");
    double matrix[m][m];
    readMatrix(m, m, matrix);
    printMatrix(m, m, matrix);

    return 0;
}

void readMatrix(int m, int n, double (*matrix)[n]) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", (*(matrix + i) + j));
}

void printMatrix(int m, int n, double (*matrix)[n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%g ", *(*(matrix + i) + j));
        printf("\n");
    }
}
