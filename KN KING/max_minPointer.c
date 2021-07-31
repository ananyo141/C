// Write the function that returns the max and min elements of the array in pointers
#include <stdio.h>

void max_min(int *arr, const int num, int *max, int *min) {
    *max = *min = *arr;
    for (int *i = arr; i < arr + num; i++) {
        if (*i > *max) 
            *max = *i;
        if (*i < *min)
            *min = *i;
    }
}

int main() {
    int num, max, min;
    printf("How many numbers you want to store?: ");
    scanf("%d", &num);
    int array[num];

    printf("Enter the values: ");
    for (int *k = array; k < array + num; k++)
        scanf("%d", k);

    max_min(array, num, &max, &min);
    printf("The maximum element in the array is: %d\n", max);
    printf("The minimum element in the array is: %d\n", min);

    return 0;
}