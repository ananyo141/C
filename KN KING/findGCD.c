// Find the GCD of two integers input by user.
#include <stdio.h>

// Find the GCD of the two int numbers by the help of Euclid's Algorithm.
int findGCD(int num1, int num2){
    int remainder;
    while (num2 != 0) {
        remainder = num1 % num2;
        num1 = num2;
        num2 = remainder;
    }

    return num1;
}

// This program is optimised for finding GCD's of integers or one digit floating points
int main(){
    float number1,number2;
    printf("Enter the two numbers you want to find GCD: ");
    scanf("%f%f",&number1,&number2);
    number1 *= 10;
    number2 *= 10;
    int int_gcd = findGCD((int)number1,(int)number2);
    float f_gcd = int_gcd / 10.0f;
    printf("The GCD of the entered numbers is: %.1f\n",f_gcd);

    return 0;
}