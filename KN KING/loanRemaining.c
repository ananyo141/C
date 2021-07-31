// WAP to find the remaining balance on a loan after given monthly payments(to be entered by the user)
#include<stdio.h>
#include<stdlib.h>

void loanBalance(float amount,int installments,float intRate,float monthlyPaym){
    float interest=((intRate / 12.0f) / 100.0f);
    float balance= ((interest) * amount + amount);
    int monthTracker=1;
    while ((installments!=0) && (balance>=monthlyPaym)){
        balance=balance-monthlyPaym;
        printf("The amount of balance to pay after %d installments: %.3f\n",monthTracker,balance);
        installments--;
        monthTracker++;
        balance=balance*interest+balance;
    }
    if (balance<monthlyPaym){
        printf("Mop up balance left to pay in last installment number %d is %.3f\n",monthTracker,balance);
    }
}


int main(){
    system("clear");
    float amt,intRate,monthlyPay;
    int installmentsDone;
    printf("Enter amount of loan: ");
    scanf("%f",&amt);
    printf("\nEnter interest rate: ");
    scanf("%f",&intRate);
    printf("Enter monthly payment: ");
    scanf("%f",&monthlyPay);
    printf("Enter the installments completed: ");
    scanf("%d",&installmentsDone);
    loanBalance(amt,installmentsDone,intRate,monthlyPay);

    return 0;
}