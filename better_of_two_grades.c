//WAP to find the better of two grades.
#include<stdio.h>
#include<conio.h>

int findBetter(int g1,int g2){
    if (g1>g2){
        printf("A got better grades.\n");
        return g1;
    }
    else if(g1<g2){
        printf("B got better grades.\n");
        return g2;
    }
    else{
        printf("Both got same, probably cheated off each other.\n");
    }
}
int main(){
    int grade1,grade2;
    printf("Please enter the two grades: ");
    scanf("%d%d",&grade1,&grade2);
    findBetter(grade1,grade2);

    return 0;
}