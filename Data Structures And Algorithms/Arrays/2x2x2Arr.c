// Write a program to read and display a 2x2x2 array
#include <stdio.h>
#define DIM 2

int main() {
    double array[DIM][DIM][DIM];
    for (int i = 0; i < DIM; i++)
        for (int j = 0; j < DIM; j++)
            for (int k = 0; k < DIM; k++)
                scanf("%lf", *(*(array + i) + j) + k);
    for (int i = 0; i < DIM; i++)
        for (int j = 0; j < DIM; j++)
            for (int k = 0; k < DIM; k++)
                printf("%g ", *(*(*(array + i) + j) + k));
    printf("\n");

    return 0;
}
