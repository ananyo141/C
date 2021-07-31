// WAP to do mathematic calculations on fractions.
// The program structure is a bit convoluted and questionable, would try to improve in the future //
#include<stdio.h>

// Find the GCD of the two int numbers by the help of Euclid's Algorithm.
int findGCD(int num1, int num2){
    int remainder;
    while (num2 != 0){
        remainder = num1 % num2;
        num1 = num2;
        num2 = remainder;
    }

    return num1;
}

void fractionAdd(int num1,int num2,int denom1,int denom2){
    int result_denom = denom1 * denom2;
    int result_num = (result_denom / denom1) * num1 + (result_denom / denom2) * num2;
    int gcd = findGCD(result_num,result_denom);
    result_num /= gcd;
    result_denom /= gcd;
    if (result_denom < 0){
        result_num *= -1;
        result_denom *= -1;
    }
    printf("The sum of the fractions is: %d/%d\n", result_num, result_denom);
}

void fractionSub(int num1, int num2, int denom1, int denom2){
    int result_denom = denom1 * denom2;
    int result_num = (result_denom / denom1) * num1 - (result_denom / denom2) * num2;
    int gcd = findGCD(result_num, result_denom);
    result_num /= gcd;
    result_denom /= gcd;
    if (result_denom < 0){
        result_num *= -1;
        result_denom *= -1;
    }
    printf("The difference of the fractions is: %d/%d\n", result_num, result_denom);
}

void fractionMultip(int num1, int num2, int denom1, int denom2){
    int result_num = (num1*num2);
    int result_denom= (denom1*denom2);
    int gcd = findGCD(result_num, result_denom);
    result_num /= gcd;
    result_denom /= gcd;
    if (result_denom < 0){
        result_num *= -1;
        result_denom *= -1;
    }
    printf("The multiplication of the given fractions is: %d/%d\n",result_num,result_denom);
}

void fractionDiv(int num1, int num2, int denom1, int denom2){
    int result_num = (num1 * denom2);
    int result_denom = (num2 * denom1);
    int gcd = findGCD(result_num, result_denom);
    result_num /= gcd;
    result_denom /= gcd;
    if (result_denom < 0){
        result_num *= -1;
        result_denom *= -1;
    }
    printf("The division of the given fractions is: %d/%d\n", result_num, result_denom);
}

int main(){
    int num1, denom1, num2, denom2;
    char operator;
    printf("Enter the fractions with the operator: ");
    scanf("%d/%d %c %d/%d",&num1,&denom1,&operator, &num2,&denom2);

    if(operator=='+'){
        fractionAdd(num1,num2,denom1,denom2);
    }
    else if(operator=='-'){
        fractionSub(num1, num2, denom1, denom2);
    }
    else if (operator == '*'){
        fractionMultip(num1, num2, denom1, denom2);
    }
    else if (operator == '/'){
        fractionDiv(num1,num2,denom1,denom2);
    }
    else{
        printf("Unrecognized input\n");
    }

    return 0;
}
