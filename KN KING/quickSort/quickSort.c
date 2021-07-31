// The quicksort function with it's helper function
#include "quickSort.h"

int split(int a[], int low, int high) {
    int part_element = a[low];

    for(;;) {
        while (low < high && a[high] >= part_element)
            high--;
        if (low >= high) break;
        a[low++] = a[high];

        while (low < high && a[low] <= part_element)
            low++;
        if (low >= high) break;
        a[high--] = a[low];
    }
    a[high] = part_element;
    return high;
}

void quickSort(int a[], int low, int high) {
    int middle;
    if (low >= high) return;
    middle = split(a, low, high);
    quickSort(a, low, middle - 1);
    quickSort(a, middle + 1, high);
}