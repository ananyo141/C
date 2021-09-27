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
