#include <stdio.h>
#include "arrayUtils.h"

/* Print the given integer array */
void printArray(int arr[], int len) {
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* Read into an integer array of length 'len' */
void readArray(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("Arr[%d] = ", i + 1);
        scanf("%d", &arr[i]);
    }
}
