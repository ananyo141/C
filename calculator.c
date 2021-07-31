// WAP to build a calculator.

#include<stdio.h>
#include<conio.h>
#include<math.h>

// Wanted to use switch/case, but doesn't support ANYTHING except int values.
double calculator(double op1,char opr[5],double op2){
    if (*opr == *"+")
    {
        return op1 + op2;
    }
    else if (*opr == *"-")
    {
        return op1 - op2;
    }
    else if (*opr == *"*")
    {
        return op1 * op2;
    }
    else if (*opr == *"/")
    {
        return op1 / op2;
    }
    else if (*opr == *"pow")
    {
        return pow(op1,op2);
    }
    else if (*opr == *"%"){
        return fmod(op1,op2);
    }
    else if (*opr == *"idiv"){
        return (int)op1/(int)op2;
    }
    else{
        printf("ERROR parsing command.");
    }
}

int main(){
    double operand1,operand2;
    char operator[5];
    printf("Enter first operand: ");
    scanf("%lf",&operand1);
    printf("\nEnter operation: ");
    scanf("%s",operator);
    printf("\nEnter second operand: ");
    scanf("%lf",&operand2);
    double result=calculator(operand1,operator,operand2);
    printf("The desired result is %f",result);
    return 0;
}


    