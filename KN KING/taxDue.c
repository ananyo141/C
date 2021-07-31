// WAP to find out the tax due.
#include<stdio.h>

float taxDueCalculator(float income){
    float tax;
    if (income<=750){
        tax = 0.01f * income;
    }
    else if (income<=2250){
        tax = 7.50f + 0.02f * (income-750);
    }
    else if (income<=3750){
        tax = 37.50f + 0.03f * (income-2250);
    }
    else if (income<=5250){
        tax = 82.50f + 0.04f * (income-3750);
    }
    else if (income <= 5250){
        tax = 142.50f + 0.05f * (income - 5250);
    }
    else{
        tax = 230.00f + 0.06f * (income - 7000);
    }
    return tax;
}

int main(){
    float income;
    printf("Enter your total income: ");
    scanf("%f",&income);
    float taxDue=taxDueCalculator(income);
    printf("Your total tax pending is $%.3f. Make sure to pay them if you don't want Income Tax Raid at your home.\n", taxDue);

    return 0;
}