/********************************************
* Write the power function as a recursion   *
* Formula:                                  *
* For n-Even: x^n = (x^(n/2))^2             *
* For n-Odd: x^n = x * x^(n-1)              *
*********************************************/

#include <stdio.h>

long recPow (int x, int n) {
    if (n == 0)
        return 1;
    // for even
    if (n % 2 == 0) {
        long tempVal = recPow(x, n/2);
        return tempVal * tempVal;
    }
    // for odd
    else 
        return x * recPow(x, n - 1);
}

int main() {
    int x, n;
    printf("Enter the value of x: ");
    scanf("%d", &x);
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("The value of x^n is : %ld\n", recPow(x, n));

    return 0;
}