                                // WAP to find broker's commission //
/*1. Ask the user to enter the number of shares and the price per share, instead of the value of the trade.
  2. Add statements that compute the commission charged by a rival broker($33 plus 3 cents per 
share for fewer than 2000 shares: $33 plus 2 cents per share for 2000 shares or more).
Display the rival's commission as well as the comission chaged by the original broker.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MIN_CHARGE 39  // dollars($)

// Make two functions each for broker 1 and broker 2. Use broker 1 for gross value and broker 2 for value per share.
// the currency is in dollars and cents
float broker1(float transactionValue){
    float commission;
    if (transactionValue < 2500){                 
        commission = 30 + 0.017f * transactionValue;
        return (commission < MIN_CHARGE ? MIN_CHARGE : commission);     // using ternary operator
    }
    else if (transactionValue < 6250){
        return 56 + 0.0066f * transactionValue;
    }
    else if (transactionValue < 20000){
        return 76 + 0.0034f * transactionValue;
    }
    else if (transactionValue < 50000){
        return 100 + 0.0022f * transactionValue;
    }
    else if (transactionValue < 500000){
        return 155 + 0.0011f * transactionValue;
    }
    else{
        return 255 + 0.0009f * transactionValue;
    }
}

float broker2(int dealShares){
    if (dealShares < 2000){
        return 33 + 0.03f * dealShares;
    }
    else{
        return 33 + 0.02f * dealShares;
    }
}


int main(){
    int shares; float pricePerShare, commission;
    char *brokerChoice;

    printf("Enter the number of shares: ");
    scanf("%d", &shares);
    printf("Enter the price per share: ");
    scanf("%f",&pricePerShare);
    printf("Do you want to go with broker 1 or broker 2? ");
    scanf("%s", brokerChoice);

    if (strcmp(brokerChoice,"broker1")==0){
        commission = broker1(shares * pricePerShare);
    }
    else if (strcmp(brokerChoice,"broker2")==0){
        commission=broker2(shares);
    }
    else{
        printf("You didn't go with any broker.\n");
        exit(0);
    }

    printf("The commission charged by %s is $%.2f.",brokerChoice,commission);
    printf("\nYou have to pay in total $%.3f\n",(shares * pricePerShare)+commission);

    printf("\nOptional Comparison:-\nCommission by broker1: $%f and total Payment $%f", \
    broker1(shares * pricePerShare),broker1(shares * pricePerShare)+(shares * pricePerShare));

    printf("\nCommission by broker2: $%f and total Payment $%f\n",broker2(shares),broker2(shares)+(shares * pricePerShare));
    return 0;
}