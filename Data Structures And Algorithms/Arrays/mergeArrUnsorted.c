// Merge two unsorted arrays.
#include <stdio.h>
#include <string.h>
#include "arrayUtils.h"

int main() {
    double arr1[] = {7, 4, 7, 5, 8, 2, 4};
    double arr2[] = {9, 3, 1, 6, 3, 4};
    int arr1Size = ArrLen(arr1);
    int arr2Size = ArrLen(arr2);
    puts("Array 1:");
    printArray(arr1, arr1Size);
    puts("Array 2:");
    printArray(arr2, arr2Size);

    double merge[arr1Size + arr2Size];
    memcpy(merge, arr1, sizeof(arr1));
    memcpy(merge + arr1Size, arr2, sizeof(arr2));
    puts("Merged Array:");
    printArray(merge, arr1Size + arr2Size);

    return 0;
}
