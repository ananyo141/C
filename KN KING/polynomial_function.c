// Write a function that finds the value of the polynomial 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6
#include <stdio.h>
#include <math.h>

double polFunc(float x) {
    return 3 * (pow(x,5)) + 2 * (pow(x,4)) - 5 * (pow(x,3)) - pow(x,2) + 7 * x - 6;
}

int main() {
    float x;
    printf("Enter the value of x: ");
    scanf("%f",&x);
    printf("The value of the polynomial is %.2f\n", polFunc(x));

    return 0;
}