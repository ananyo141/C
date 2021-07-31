// WAP to convert Military to standard time (24-hr to 12-hr format)
#include<stdio.h>
#include<stdlib.h>

// Precondition: 0:00<=Time<24:00.
int main(){
    int milHours, mins;
    printf("Enter a 24-hour time: ");
    scanf("%d:%d",&milHours,&mins);
    milHours %= 24;

    // Condensed a whole lot of cascaded if-else statements into ternary operators.
    int stdHours = ((milHours > 12 || milHours == 0)? milHours - 12: milHours);
    printf("Equivalent 12-hour time: %d:%.2d",abs(stdHours),mins);
    printf((milHours < 12) ? "AM\n" : "PM\n");
    

    return 0;
}
    
     
