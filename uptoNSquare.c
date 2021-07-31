// WAP to prompt user for a number n and print the number along with it's square upto n.

#include<stdio.h>
void uptoSquare(int num){
    int i=1;
    while(i!=num){
        printf("%d   %d\n",i,i*i);
        i++;
    }


    // for(int i=1; i!=num; i++){
    //     printf("%d %d",i,i*i);
    // }
}


int main(){
    int x;
    printf("Enter the number: ");
    scanf("%d",&x);
    uptoSquare(x);
    return 0;
}
