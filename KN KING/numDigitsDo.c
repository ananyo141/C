// Find the digits in the user input number with the help of do-while loop.
#include<stdio.h>

int main(){
    int number;
    printf("Enter the number: ");
    scanf("%d",&number);
    int digits = 0;
    do {
        digits += 1;
        number /= 10;
    } while (number > 0);
    printf("The digits in the given number is %d\n",digits);

    return 0;
}


