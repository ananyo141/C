// WAP to calculate the digits of entered number.

#include <stdio.h>
#include <stdlib.h>

int numDigits(int number){
    if (number == 0)
        return 1;
    
    int digits = 0;
    number = abs(number);
    while(number>9){
        number/=10;
        digits+=1;
    }

    return ((number>0) ? digits+1 : digits);      // clever use of ternary operator
}

int main(){
    int num;
    printf("Enter the number: ");
    scanf("%d",&num);
    int digits=numDigits(num);
    printf("The digits in the given number is %d.\n",digits);
    
    return 0;
}