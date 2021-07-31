// Compare the interest on a given principle for a given time period
#include <stdio.h>
#define ARRAY_LEN ((int) (sizeof(principleInterest) / sizeof(principleInterest[0]) ))

int main() {
    float investment, interestRate;
    double principleInterest[5];
    int years;
    
    printf("Enter the amount you want to invest: ");
    scanf("%f", &investment);
    printf("Enter the rate to compare with next four higher rates: ");
    scanf("%f", &interestRate);
    printf("Enter how many years you want to invest: ");
    scanf("%d", &years);

    // initialize every element as investment
    for (int i = 0; i < 5; i++) 
        principleInterest[i] = investment;

    printf("Years  %6.2f%% %6.2f%% %6.2f%% %6.2f%% %6.2f%% \n", interestRate, interestRate + 1, interestRate + 2, interestRate + 3, interestRate + 4);
    for (int i = 1; i <= years; i++) {
        printf("%3d     ", i);
        int amountCount = 0;
        for (int j = interestRate; j < interestRate + 5; j++) {
            principleInterest[amountCount] *= (1 + (j/100.0f));
            printf("%6.2f  ",principleInterest[amountCount]);

            if (amountCount >= ARRAY_LEN)       // checks that the program doesn't go out of array boundary
                break;
            amountCount++;
        } 
        printf("\n");
    }

    return 0;
}