// Merge two sorted arrays
#include <stdio.h>
#include <stdlib.h>
#include "arrayUtils.h"

// Prototype for merge function //
double *mergeSortedArrays(double arr1[], int arr1Size, double arr2[], int arr2Size);

int main() {
    double arr1[] = {1, 3, 5, 7,  9};
    double arr2[] = {2, 4, 6, 8, 10};
    int arr1Size  = ArrLen(arr1);
    int arr2Size  = ArrLen(arr2);
    int mergeSize = arr1Size + arr2Size;

    puts("Array 1:");
    printArray(arr1, arr1Size);
    puts("Array 2:");
    printArray(arr2, arr2Size);

    puts("Array Merged:");
    double *const mergeSorted = mergeSortedArrays(arr1, arr1Size, arr2, arr2Size);
    printArray(mergeSorted, mergeSize);
    free(mergeSorted); // free the dynamically allocated memory

    return 0;
}

double *mergeSortedArrays(double arr1[], int arr1Size, double arr2[], int arr2Size) {
    /* Return a dynamically allocated array of doubles after merging the two sorted arrays */

    int mergedSize = arr1Size + arr2Size;                       // calculate merge size,
    double *mergedArray = malloc(sizeof(double) * mergedSize);  // and allocate dynamic memory

    int i = 0, arr1_index = 0, arr2_index = 0;
    while (arr1_index < arr1Size && arr2_index < arr2Size) {
        if (arr1[arr1_index] < arr2[arr2_index])                // compare array elements, insert
            mergedArray[i] = arr1[arr1_index++];                // smaller element and increment index
        else                                                    // of that array
            mergedArray[i] = arr2[arr2_index++];
        i++;
    }

    while (arr1_index < arr1Size) // if array1 got leftovers as array2 ended
        mergedArray[i++] = arr1[arr1_index++];
    while (arr2_index < arr2Size) // if array2 got leftovers as array1 ended
        mergedArray[i++] = arr2[arr2_index++];

    return mergedArray;
}
