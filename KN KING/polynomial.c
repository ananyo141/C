// Find the value of polynomial 3x^5+2x^4-5x^3-x^2+7x-6 for user input value of x.

#include<stdio.h>
#include<math.h>

float polVal(float x){
    float result= (3*(pow(x,5))+2*(pow(x,4))-5*(pow(x,3))-(pow(x,2))+(7*x)-6);
    return result;
}

int main(){
    float xVal;
    printf("Enter the value of x you want to calculate the polynomial expression 3x^5+2x^4-5x^3-x^2+7x-6 for: ");
    scanf("%f",&xVal);
    float result=polVal(xVal);
    printf("The result is %.3f\n",result);

    return 0;
}
