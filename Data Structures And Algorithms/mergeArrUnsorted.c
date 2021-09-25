// Merge two unsorted arrays.
#include <stdio.h>
#include <string.h>
#include "arrayUtils.h"

int main() {
    int arr1[] = {7, 4, 7, 5, 8, 2, 4};
    int arr2[] = {9, 3, 1, 6, 3, 4};
    int arr1Size = sizeof(arr1) / sizeof(arr1[0]);
    int arr2Size = sizeof(arr2) / sizeof(arr2[0]);
    puts("Array 1:");
    printArray(arr1, arr1Size);
    puts("Array 2:");
    printArray(arr2, arr2Size);

    int merge[arr1Size + arr2Size];
    memcpy(merge, arr1, sizeof(arr1));
    memcpy(merge + arr1Size, arr2, sizeof(arr2));
    puts("Merged Array:");
    printArray(merge, arr1Size + arr2Size);

    return 0;
}
