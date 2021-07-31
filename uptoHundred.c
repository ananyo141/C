// WAP to print any given number (less than 100) to 100.
#include<stdio.h>
#include<conio.h>

void uptoHundred(double num){
    for (num;num<=100;num++){
        printf("%f\n",num);
    }
}

// Had to use double instead of float, as the precision was getting blurry, new digits popped up due to memory allocation issues.
int main(){
    double number;
    printf("Enter the number(less than 100): ");
    scanf("%lf",&number);
    uptoHundred(number);
    return 0;
}