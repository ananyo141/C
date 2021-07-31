// WAP that cubes an entered number.

#include<stdio.h>
#include<math.h>

// while compiling on linux, add ;gcc cube.c -lm' as the pow function definition is not natively included.
double cube(double number){
    return pow(number, 3);
}

int main(){
    double num;
    double numCube;
    printf("Enter the number you want to cube: ");
    scanf("%lf",&num);
    numCube=cube(num);
    printf("The cube of the entered number is %f\n",numCube);
    return 0;
}