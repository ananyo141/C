//WAP to find the bigger of two slices of pizza of given base and height.

#include<stdio.h>
#include<conio.h>

float area(float base,float height){
    return (0.5*(base*height));
}

void getBigger(float b1, float h1, float b2,float h2){
    if (area(b1,h1)>area(b2,h2)){
        printf("Take the first slice.\n");
    }
    else if(area(b1,h1)<area(b2,h2)){
        printf("Take the second slice.\n");
    }
    else{
        printf("Both are the same, take the one with more toppings!\n");
    }


}
    

int main(){
    float base1,height1,base2,height2;
    printf("Please enter the base and height of each pizza accordingly separated by a whitespace or newline.\n");
    scanf("%f%f%f%f",&base1,&height1,&base2,&height2);
    getBigger(base1,height1,base2,height2);
    return 0;
}