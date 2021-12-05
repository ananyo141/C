// Implement exponent function with the help of 
// tail recursion

#include <stdio.h>

// Functions //
long exponent(int num, int exp);
long expAux(int num, int exp, long res);

int main() {
    int num1, num2;
    printf("Enter the number and exponent: ");
    scanf("%d%d", &num1, &num2);
    printf("%d ^ %d is %ld\n", num1, 
            num2, exponent(num1, num2));

    return 0;
}

long exponent(int num, int exp) {
    /* Wrapper for expAux */
    return expAux(num, exp, 1);
}

long expAux(int num, int exp, long res) {
    /* Find the exponent using auxillary
    parameter res */

    if (exp == 0)
        return res;
    return expAux(num, exp-1, res * num);
}

