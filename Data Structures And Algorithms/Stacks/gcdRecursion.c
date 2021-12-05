// Implement Euclid's GCD Algorithm using tail recursion

#include <stdio.h>

// Functions //
int gcd(int num1, int num2);

int main() {
    int num1, num2;
    printf("Enter the number1 and number2: ");
    scanf("%d%d", &num1, &num2);
    printf("The gcd of %d and %d is %d\n", num1, 
            num2, gcd(num1, num2));

    return 0;
}

int gcd(int m, int n) {
    if (n == 0)
        return m;
    int rem = m % n;
    m = n;
    n = rem;
    return gcd(m, n);
}

