// Write a recursive factorial program that uses tail recursion
// with the help of auxillary parameter

#include <stdio.h>

// Functions //
long double factorial(int n);
long double factorialAux(int n, long res);

int main() {
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    printf("The factorial of %d is %.0llf\n", num, factorial(num));

    return 0;
}

long double factorial(int n) {
    /* Just a similar-syntax wrapper
    function for actual function */
    return factorialAux(n, 1);
}

long double factorialAux(int n, long res) {
    /* Find the factorial using auxillary parameter */
    if (n == 0)
        return res;
    return factorialAux(n - 1, res*n);
}

