// Print the sizeof() int, short, long, float, double, long double
#include <stdio.h>

int main() {
    printf("The sizeof(int): %zu bytes\n", sizeof(int));
    printf("The sizeof(short): %zu bytes\n", sizeof(short));
    printf("The sizeof(long): %zu bytes\n", sizeof(long));
    printf("The sizeof(float): %zu bytes\n", sizeof(float));
    printf("The sizeof(double): %zu bytes\n", sizeof(double));
    printf("The sizeof(long double): %zu bytes\n", sizeof(long double));

    return 0;
}