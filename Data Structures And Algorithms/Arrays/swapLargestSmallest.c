// Write a program to interchange the largest and smallest number in an array.
#include <stdio.h>
#include "arrayUtils.h"

// function prototypes //
void findLargestSmallest(double array[], int arrSize, int *largestIndex, int *smallestIndex);
void interchangePos(double array[], int index1, int index2);

int main() {
    int arrSize;
    printf("Enter the size of the array: ");
    scanf("%d", &arrSize);

    double array[arrSize];
    readArray(array, arrSize);
    puts("Array before:");
    printArray(array, arrSize);

    int largestIndex, smallestIndex;
    findLargestSmallest(array, arrSize, &largestIndex, &smallestIndex);
    interchangePos(array, largestIndex, smallestIndex);

    puts("Array after:");
    printArray(array, arrSize);

    return 0;
}

void findLargestSmallest(double array[], int arrSize, int *largestIndex, int *smallestIndex) {
    /* Find the largest and smallest element of the array and store their
       index by modifying the values of largestIndex and smallestIndex variables */

    *largestIndex  = 0;
    *smallestIndex = 0;
    for (int i = 1; i < arrSize; i++) {
        if (array[i] > array[*largestIndex])  *largestIndex  = i;
        if (array[i] < array[*smallestIndex]) *smallestIndex = i;
    }
}

void interchangePos(double array[], int index1, int index2) {
    /* Interchange the specified positions of the elements */

    double temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}
