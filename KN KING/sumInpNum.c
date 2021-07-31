// Find the sum of input numbers upto 0.
#include<stdio.h>

int main(){
    int inpNum, sum = 0;
    printf("Enter the series of numbers: ");
    scanf("%d",&inpNum);        // find the sum without using array
    while(inpNum != 0){
        sum += inpNum;
        scanf("%d", &inpNum);       // as we don't know number of inputs and can't use
    }                               // multiple variables for this, overwriting is better option.
    printf("The total of the input is: %d\n",sum);

    return 0;
}
