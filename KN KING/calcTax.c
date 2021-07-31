// WAP to find the 5% tax on user input amount.
#include <stdio.h>

float calcTax(float principal){
    float tax = principal * (5 / (float)100) ;
    return principal+tax;
}

int main(){
    float pAmt;
    float totalAmt;
    printf("Enter the principal amount you want to calculate the tax on: ");
    scanf("%f",&pAmt);
    totalAmt=calcTax(pAmt);
    printf("The total amount you have to pay with tax is %.3f\n",totalAmt);
    return 0;
}
