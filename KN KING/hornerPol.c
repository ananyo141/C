// Use Horner's Rule to calculate evaluate the polynomial using ((((3x+2)x-5)x-1)x+7)x-6

#include<stdio.h>

float hornerPol(float x){
    return (((((3*x + 2)* x - 5)* x - 1) *x + 7) *x - 6);
}

int main(){
    float xVal;
    printf("Enter the value of x for which you want to evaluate Horner's Rule ((((3x+2)x-5)x-1)x+7)x-6: ");
    scanf("%f", &xVal);
    float result=hornerPol(xVal);
    printf("The processed result is %.2f\n",result);

    return 0;
}