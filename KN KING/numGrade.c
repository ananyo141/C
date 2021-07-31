// Convert num grade into letter grade.

#include<stdio.h>

void numGradeConvert(float numGrade){
    int gradeRange = (int)numGrade / 10;
    switch(gradeRange){
        case 0: case 1: case 2: case 3: case 4: case 5:
        printf("F\n");
        break;

        case 6:
        printf("D\n");
        break;
        case 7:
        printf("C\n");
        break;
        case 8:
        printf("B\n");
        break;
        case 9: case 10:
        printf("A\n");
        break;

        default:
        printf("Invalid numerical grade input\n");
        break;
    }

}

int main(){
    float numberGrade;
    printf("Enter your number grade: ");
    scanf("%f",&numberGrade);
    numGradeConvert(numberGrade);

    return 0;
}