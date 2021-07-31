//WAP to convert hours to minutes and seconds.
#include<stdio.h>
#include<conio.h>


float hoursToMin(float hours){
    return hours*60;
}
//The parameters match, as the identifier 'hours' is the most apt.
float hoursToSec(float hours){
    float mins=hoursToMin(hours);
    return mins*60;
}

int main(){
    float hrs;
    char choice[20];
    char selected1[20]="minutes";
    char selected2[20]="seconds";
    char selected3[20]="both";
    printf("Please enter the number of hours you to convert: ");
    scanf("%f",&hrs);
    printf("Please enter '%s' to convert minutes or '%s' to convert to seconds,or '%s' to do both.\n",selected1,selected2,selected3);
    scanf("%s",choice);
    if (*choice==*selected1)
    {
        float result=hoursToMin(hrs);
        printf("Your required value in minutes is %f\n",result);
    }
    //Apparently, *selected1 and *selected2 are same.!!? Debug whenever possible.
    //Edit: The array name is the memory location of the first element. So actually dereferencing the pointers of the names of string arrays 'to_min' and 'to_sec' gave the same value 't'.
    else if (*choice==*selected2)
    {
        float result=hoursToSec(hrs);
        printf("Your required value in seconds is %f\n",result);
        
    } 
    else if (*choice==*selected3)
    {
        float result1=hoursToMin(hrs);
        printf("Your required value in minutes is %f\n",result1);
        
        float result2=hoursToSec(hrs);
        printf("Your required value in seconds is %f\n",result2);
    }
    else
    {
        printf("Invalid Input.\n");
    }

    return 0;
}