// Use QuickSort using pointers to sort an array
#include <stdio.h>

// function prototypes
void printArray(int *array, int size);
void quickSortPointer(int *arr, int *low, int *high);
int *split(int *arr, int *low, int *high);

// driver function
int main() {
    // input an array
    int num;
    printf("How many numbers you want to sort?: ");
    scanf("%d", &num);
    int array[num];
    printf("Enter the numbers: ");
    for (int *p = array; p < array + num; p++) 
        scanf("%d", p);
    
    // user input
    printf("User input:\n");
    printArray(array, num);

    quickSortPointer(array, array, &array[num - 1]);
    
    // print the sorted array
    printf("Sorted Array:\n");
    printArray(array, num);

    return 0;
}

void quickSortPointer(int *arr, int *low, int *high) {
    int *middle;

    if (low >= high) return;
    middle = split(arr, low, high);
    quickSortPointer(arr, low, middle - 1);                        
    quickSortPointer(arr, middle + 1, high);                            
}

int *split(int *arr, int *low, int *high) {
    int part_element = *low;

    for(;;) {
        while (low < high && part_element <= *high)
            high--;
        if (low >= high) break;
        *low++ = *high;

        while (low < high && part_element >= *low)
            low++;
        if (low >= high) break;
        *high-- = *low;
    }

    *high = part_element;
    return high;
}

void printArray(int *array, int size) {
    for (int *p = array; p < array + size; p++) 
        printf("%d ", *p);
    printf("\n");
}