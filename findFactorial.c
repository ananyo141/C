// WAP to find the factorial of a number.

#include<stdio.h>
#include<stdlib.h>

int factorial(int number){
    int value=1;
    for (int i=number; i!=1;i--){
        value*=i;
    }
    return value;
}


int main(){
    int num;
    system("clear");
    printf("Enter the number you want to calculate the factorial of: ");
    scanf("%d", &num);
    int factorial_value=factorial(num);
    printf("The factorial of the entered value is: %d\n",factorial_value);
    return 0;
}