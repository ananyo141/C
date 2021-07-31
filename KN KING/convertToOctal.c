// WAP that reads an integer entered by the use and displays it in octal.//
/*The output should be displayed using five digits even if fewer digits are sufficient. To convert to 
octal, first divide by 8; remainder is first digit. Then divide original number by 8 and repeat to 
get to the  next-to-last digit.*/

#include <stdio.h>
#include <math.h>

int convertToOctal(int deciNum){
    int j=0; int digits=0;
    while(deciNum>8){
        digits += (fmod(deciNum, 8) * pow(10,j));     // can simply use % instead of fmod
        deciNum/=(float)8;          // if use %, delete the explicit conversion (float)
        j++;
    }
    return digits+(deciNum*pow(10,j));
}

int main(){
    int decimal;
    printf("Enter the decimal number you want to convert to octal: ");
    scanf("%d",&decimal);
    int octal=convertToOctal(decimal);
    printf("The octal number is: %d\n",octal);
    printf("The verified octal number is %o\n",decimal);

    return 0;
}
