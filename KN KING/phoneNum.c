// WAP that asks the user to enter phone number in form (xxx) xxx-xxx
// then display as xxx.xxx.xxx
#include<stdio.h>

int main(){
    int first, second, third;
    printf("Enter the phone number[(xxx) xxx-xxxx]: ");
    scanf("(%d) %d-%d",&first,&second,&third);
    printf("\nYou entered the number: %d.%d.%d\n",first,second,third);
    printf("\nIn other format: %d%d%d\n", first, second, third);

    return 0;
}