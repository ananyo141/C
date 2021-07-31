// Find the factorial of a number.
#include <stdio.h>

int main() {
    long double num;
    printf("Enter the number: ");
    scanf("%Lf", &num);
    for (int factorialVar = num-1; factorialVar > 1; factorialVar--) {
        num *= factorialVar;
    }
    printf("The factorial value is %Lg\n", num);
    
    return 0;
}