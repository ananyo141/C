//WAP to display if the student has passed, conditions: Theory grade>=80 and Practical grade>=50. Failing any means fail.
#include<stdio.h>
#include<conio.h>

void checkGrade(float th_g,float pr_g){
    if ((th_g>=80) && pr_g>=50){
        printf("You have passed!\n");
    }
    else {
        printf("You have failed. Be ready for some spanking at home.\n");
    }
}
    
int main(){
    float theory,practical;
    printf("Enter your theory grade: ");
    scanf("%f",&theory);
    printf("\nEnter your practical grade: ");
    scanf("%f",&practical);
    checkGrade(theory,practical);
    return 0;
}