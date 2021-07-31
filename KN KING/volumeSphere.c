// Find the volume of a sphere.
#include<stdio.h>
#include<math.h>

float volumeSphere(float radius){
    return 4/(float)3*3.14*pow(radius,3);
}

int main(){
    float radius;
    printf("Enter the radius of the sphere you want to compute: ");
    scanf("%f",&radius);
    float volume=volumeSphere(radius);
    printf("The required volume of the sphere is %.3f\n",volume);
    
    return 0;
}
