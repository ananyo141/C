// WAP to show how to pay an amount in smallest number of 1,10,20,50 and 100 rupees notes.

#include<stdio.h>

void showCurrencyDiv(int amount){
    if (amount>=100){
        int hundreds=amount/100;
        amount=amount-100*hundreds;
        printf("Hundreds required: %d\n",hundreds);
    }
    if (amount>=50){
        int fiftys=amount/50;
        amount-=(50*fiftys);
        printf("Fiftys required: %d\n",fiftys);
    }
    if (amount>=20){
        int twentys=amount/20;
        amount-=(20*twentys);
        printf("Twentys required: %d\n",twentys);
    }
    if (amount>=10){
        int tens= amount/10;
        amount-=(10*tens);
        printf("Tens required: %d\n",tens);
    }
    if (amount>=1){
        int ones=amount/1;
        amount-=(1*ones);
        printf("Ones required: %d\n",ones);
    }
}

int main(){
    int amt;
    printf("Enter the amount you want to get the currency division: ");
    scanf("%d",&amt);
    showCurrencyDiv(amt);
    return 0;
}