#include <stdio.h>
#include <stdlib.h>

int *ptr;

int main()
{
    ptr = (int *)malloc(sizeof(int) * 2);
    int i;

    *ptr = 10;
    *(ptr + 1) = 20;

    ptr = (int *)realloc(ptr, sizeof(int) * 3);
    *(ptr + 2) = 30;
    for (i = 0; i < 3; i++)
        printf("%d \n", *(ptr + i));

    return 0;
}