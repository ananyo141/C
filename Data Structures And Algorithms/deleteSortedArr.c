// Delete a number from an array that is already sorted in ascending order.
#include <stdio.h>
#include "printArray.h"

int main() {
    int sortedArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int delElem, arrSize = sizeof(sortedArr) / sizeof(sortedArr[0]);
    puts("Sorted Array: ");
    printArray(sortedArr, arrSize);

    printf("Enter the number you want to delete: ");
    scanf("%d", &delElem);
    for (int i = 0; i < arrSize; i++)
        if (sortedArr[i] == delElem)
            for (int j = i; j < arrSize - 1; j++)
                sortedArr[j] = sortedArr[j + 1];

    puts("Array after deleting: ");
    printArray(sortedArr, --arrSize);
    
    return 0;
}
