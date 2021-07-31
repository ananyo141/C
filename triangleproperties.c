// WAP to find out the area, perimeter, semi-perimeter of a given triangle.

#include<stdio.h>
#include<conio.h>

float area(float base, float height) {
    return (base*height)/2;
}

float perimeter(float s1,float s2,float s3){
    return s1+s2+s3;
}

float semiPerim(float s1,float s2,float s3){
    float perim=perimeter(s1,s2,s3);
    return perim/2;
}

int main(void){
    //Given base=5,height=3; s1,s2,s3 respectively 3,4,5.
    float areaoftriangle=area(5,3);
    float perimeteroftriangle=perimeter(3,4,5);
    float semiperimeter=semiPerim(3,4,5);
    printf("The calculated area,perimeter and semiperimeter of the triangle is resp. %f,%f,%f.\n",areaoftriangle,perimeteroftriangle,semiperimeter);
    return 0;
}
    