// WAP to find out if flight is on schedule,early or delayed. Time convention: 3:00-->3.0, 14:30-->14.5
// 0<=time<24
#include<stdio.h>
#include<conio.h>

void flight_report(float declared_time, float actual_time){
    if (actual_time<declared_time){
        printf("Arriving early.\n");
    }
    else if (actual_time==declared_time)
    {
        printf("On schedule.\n");
    } else
    {
        printf("Delayed\n");
    }
}
    
int main(){
    float dec_time,est_time;
    printf("Please enter declared time of flight: ");
    scanf("%f",&dec_time);
    printf("\nPlease enter the current estimated time of flight: ");
    scanf("%f",&est_time);
    flight_report(dec_time,est_time);
    return 0;
}