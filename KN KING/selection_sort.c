// Sort a given array with the help of recursive selection sort.
#include <stdio.h>

// swapper function that swaps the values
void swap(double *num1, double *num2) {
    double temp = *num1; 
    *num1 = *num2;
    *num2 = temp;
}

// main selection sort function
void selection_sort(double arr[], int size) {
    if (size == 0)
        return;
    int max_index = 0;
    // find the max index
    for (int i = 0; i < size; i++) 
        if (arr[i] > arr[max_index])
            max_index = i;
    // swap the max with the first element
    swap (&arr[max_index], &arr[size - 1]);

    // sort the first elements
    selection_sort(arr, size - 1);
}

void printArray(double array[], int size) {
    for (int i = 0; i < size; i++) 
        printf("%.2g ", array[i]);
    printf("\n");
}

int main() {
    int num;
    printf("Enter how many numbers you want to store?: ");
    scanf("%d", &num);
    double numArr[num];
    printf("Enter the numbers: ");
    for (int i = 0; i < num; i++) 
        scanf("%lf", &numArr[i]);

    printf("User Array:\n");
    printArray(numArr, num);

    printf("Sorted Array:\n");
    selection_sort(numArr, num);
    printArray(numArr, num);

    return 0;
}