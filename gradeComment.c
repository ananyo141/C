// WAP to comment on a grade using switch-case.
#include<stdio.h>
#include<stdlib.h>

void gradeComment(char grade){
    switch (grade)
    {
    case 'O':
        printf("Outstanding\n");
        break;
    case 'A':
        printf("Excellent\n");
        break;
    case 'C':
        printf("Satisfactory\n");
        break;
    default:
        printf("You didn't enter a valid grade\n");
    }
}

int main(){
    char grade;
    printf("Enter your grade: ");
    scanf("%c", &grade);
    system("clear");
    gradeComment(grade);
    return 0;
}
    