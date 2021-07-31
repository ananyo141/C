// Print a table of squares upto N entered by the user.

#include<stdio.h>

int main(){
    int num;
    printf("Enter the number you want to print the square table of: ");
    scanf("%d",&num);
    int i = 1;
    while(i != num+1){
        printf("%d %10d\n",i,i*i);
        i++;
    }

    return 0;
}

