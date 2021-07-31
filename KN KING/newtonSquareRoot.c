// Find the square root of a positive number using Newton's Algorithm.
#include <stdio.h>
#include <math.h>

int main() {
    double num, avg, y_val, x_div_y;
    printf("Enter the number you want to find the square root of using Newton's Algorithm: ");
    scanf("%lf", &num);
    printf("Enter guess number: ");
    scanf("%lf", &y_val);

    do {
        x_div_y = (num / y_val);
        avg = (y_val + x_div_y ) / 2;
        y_val = avg;
    } while (fabs( y_val - x_div_y) > 0.00001);

    printf("The square Root of %.2lf is %lf\n", num, x_div_y);


    return 0;
}