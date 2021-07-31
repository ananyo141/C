//WAP to convert celcius to fahrenheit
#include<stdio.h>
#include<conio.h>

float cel_to_fah(float temp_c){
    return (9.0*temp_c/5)+32;
}


int main(){
    //Here I chose the temperature variable identifier same as the parameter identifier, as it was most apt.
    float temp_c;
    float temp_fah;
    printf("Please enter the temperature in celcius: ");
    scanf("%f",&temp_c);
    temp_fah=cel_to_fah(temp_c);
    printf("%f",temp_fah);
    return 0;
}