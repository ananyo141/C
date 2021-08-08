#include <stdio.h>
#include <stdlib.h>

int main() {
    int *a;
    a = malloc(sizeof(int) * 3);
    printf("Size of a = %zu\n", sizeof(a)); 
    a = realloc(a, sizeof(int) * 23);
    printf("Size of a = %zu\n", sizeof(a));

    return 0;
}