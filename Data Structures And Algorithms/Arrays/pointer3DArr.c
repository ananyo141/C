// Write a program that illustrates the use of pointer to 3D array
#include <stdio.h>

int main() {
    int m, n, o;
    printf("Enter m, n, o values: ");
    scanf("%d%d%d", &m, &n, &o);
    int arr3D[m][n][o];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < o; k++)
                scanf("%d", (*(*(arr3D + i) + j) + k));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < o; k++)
                printf("%d ", arr3D[i][j][k]);
    printf("\n");

    return 0;
}
