// create an array with mixed data type
#include <stdio.h>
#define ARR_SIZE 1000

typedef struct number {
    enum {INT, DOUBLE} kind;
    union {
        int i;
        double d;
    } u; 
} Number;

void print_Number(Number n);

int main() {
    Number number_arr[ARR_SIZE];
    number_arr[0].kind = INT;
    number_arr[0].u.i = 10;

    number_arr[1].kind = DOUBLE;
    number_arr[1].u.d = 3.14;
    print_Number(number_arr[0]);
    print_Number(number_arr[1]);
    printf("\n");

    return 0;
}

void print_Number(Number n) {
    if (n.kind == INT)
        printf("%d ", n.u.i);
    else 
        printf("%g ", n.u.d);
}