// Find the prime numbers between 1 to the user input number N.
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int main(){
    int inputNum;
    printf("Enter the number you want to find the prime numbers upto: ");
    scanf("%d", &inputNum);

    // If the user input is between 0 to 3 (included)
    if (inputNum<=3){
        printf("The prime numbers are: ");
        switch(inputNum){
            case 0: printf("Don't know if 0 is a prime number.\n");
                    break;
            case 1: printf("%d\n",1);
                    break;
            case 2: printf("%d %d",1,2);
                    break;
            case 3: printf("%d %d %d",1,2,3);
        }  
        printf("\n");
        exit(0);
    }

    // If the user input is greater than 4 (including)
    printf("The prime numbers are: %d %d% d",1,2,3);    // 1 to 3 are prime, start from 4
    for(int i = 4; i <= inputNum; i++){
        bool prime = true;
        for(int j = 2; j < i; j++){     // excluding 1 and the number itself(i)
            if ((i%j) == 0){
                prime = false;          // a validator switch
                break;
            }
        }
        if (prime)
            printf(" %d", i);
        else
            continue;
    }
    printf("\n");

    return 0;
}