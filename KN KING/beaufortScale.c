// WAP to write a beaufort scale.
#include <stdio.h>

void beaufortScale(float speed_in_knots){
    if (speed_in_knots<1){
        printf("Calm");
    }
    else if (speed_in_knots<=3){
        printf("Light Air");
    }
    else if (speed_in_knots<=27){
        printf("Breeze");
    }
    else if (speed_in_knots<=47){
        printf("Gale");
    }
    else if (speed_in_knots<=63){
        printf("Storm");
    }
    else {
        printf("Hurricane");
    }
    printf("\n");
}

int main(){
    float windSpeed;
    printf("What is the current wind speed(in knots)? ");
    scanf("%f", &windSpeed);
    beaufortScale(windSpeed);
    
    return 0;
}