#include <stdio.h>
#include "arrayUtils.h"

/* Print the given array */
void printArray(double arr[], int len) {
    for (int i = 0; i < len; i++)
        printf("%g ", arr[i]);
    printf("\n");
}

/* Read into an array of length 'len' */
void readArray(double arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("Arr[%d] = ", i);
        scanf("%lf", &arr[i]);
    }
}

/* Enter prompt for elements and accept elements upto
   'maxlen' or a newline (whichever comes first) */
int freeRead(double arr[], int maxlen) {
    int len = 0;
    printf("Enter elements: ");
    for (;;) {
        scanf("%lf", &arr[len++]);
        if (getchar() == '\n' || len == maxlen-1) // prevent overflow
            break;
    }
    return len;
}

/* Print a 2-Dimensional array */
void printMatrix(int m, int n, double arr[m][n]) {
    // print the upper brackets
    printf(" _");
    for (int i = 0; i < (n*5); i++) 
        printf(" ");
    printf("_\n");
    // print matrix body
    for (int i = 0; i < m; i++) {
        printf("| ");
        for (int j = 0; j < n; j++) 
            printf("%4g ", arr[i][j]);
        printf(" |\n");
    }
    // print the lower brackets
    printf("|_");
    for (int i = 0; i < (n*5); i++)
        printf(" ");
    printf("_|\n");
}

/* Read a 2-Dimensional array */
void readMatrix(int m, int n, double arr[m][n]) {
    for (int i = 0; i < m; i++) {
        printf("Starting Row #%d\n", i+1);
        for (int j = 0; j < n; j++) {
            printf("     Enter Col #%d: ", j+1);
            scanf("%lf", &arr[i][j]);
        }
    }
}
