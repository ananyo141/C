// Merge two sorted arrays
#include <stdio.h>
#include <stdlib.h>
#include "arrayUtils.h"

const double *mergeSortedArrays(double arr1[], int arr1Size, double arr2[], int arr2Size);

int main() {
    double arr1[] = {1, 3, 5, 7,  9};
    double arr2[] = {2, 4, 6, 8, 10};
    int arr1Size  = ArrLen(arr1);
    int arr2Size  = ArrLen(arr2);
    int mergeSize = arr1Size + arr2Size;

    const double *mergeSorted = mergeSortedArrays(arr1, arr1Size, arr2, arr2Size)


    return 0;
}

const double *mergeSortedArrays(double arr1[], int arr1Size, double arr2[], int arr2Size) {
    /* Return a dynamically allocated array of doubles after merging the two sorted arrays */

    int mergedSize = arr1Size + arr2Size;
    const double *mergedArray = malloc(sizeof(double) * mergedSize)

    // for (int )
}

double insertSmaller(double dst[], double src[], int srcSize, double compareElem) {
    /* Copy elements from src array to dst array until hits an element bigger than compareElem;
       finally copies the compareElem and return the bigger element */

    double bigger;
    // for (int i = 0; src[i] < compareElem; i++);
}
