#include <stdio.h>
#include <stdlib.h>

int *ptr;
int total = 1;

void expand(int size) {
    printf("before = %p", ptr);
    total += size;
    ptr = realloc(ptr, sizeof(int) * (total));
    printf(", after = %p\n", ptr);
}

int main()
{
    ptr = malloc(sizeof(int));
    int filled = 0;

    for(;;) {
        ptr[filled++] = 3;

        for (int i = 0; i < filled; i++)
            printf("%d ", ptr[i]);
        printf("\n");
        expand(1);
    }

    return 0;
}
