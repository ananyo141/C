// WAP that spells out a number entered within range 100 using switch.
#include <stdio.h>
#include <stdlib.h>

void numberSpell(int number){
    int firstDigit = number / 10;
    int secondDigit = number % 10;
    switch(firstDigit){
        case 0:
            break;
        case 1:
            switch(secondDigit){
                case 1:
                    printf("Eleven\n");
                    exit(0);
                case 2:
                    printf("Twelve\n");
                    exit(0);              
                case 3:
                    printf("Thir");
                    break;
                case 4:
                    printf("Four");
                    break;
                case 5:
                    printf("Fif");
                    break;
                case 6:
                    printf("Six");
                    break;
                case 7:
                    printf("Seven");
                    break;
                case 8:
                    printf("Eigh");
                    break;
                case 9:
                    printf("Nine");
                    break;
                }
            printf("teen\n");
            exit(0);
        case 2:
            printf("Twenty");
            break;
        case 3:
            printf("Thirty");
            break;
        case 4:
            printf("Fourty");
            break;
        case 5:
            printf("Fifty");
            break;
        case 6:
            printf("Sixty");
            break;
        case 7:
            printf("Seventy");
            break;
        case 8:
            printf("Eighty");
            break;
        case 9:
            printf("Ninety");
            break;
    }
    printf("-");
    switch(secondDigit){
        case 1:
            printf("one");
            break;
        case 2:
            printf("two");
            break;
        case 3:
            printf("three");
            break;
        case 4:
            printf("four");
            break;
        case 5:
            printf("five");
            break;
        case 6:
            printf("six");
            break;
        case 7:
            printf("seven");
            break;
        case 8:
            printf("eight");
            break;
        case 9:
            printf("nine");
            break;
        }
    printf("\n");
}

int main(){
    int number;
    printf("Enter the number: ");
    scanf("%d", &number);
    numberSpell(number);

    return 0;
}