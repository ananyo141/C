//WAP to display if person should take umbrella for rain or boots and coat for snow for subzero temp or nothing.
#include<stdio.h>
#include<conio.h>

void predictWeather(float temp,int humidity){
    int optimal_temp = 25;
    int critical_humidity = 95;
    if (temp==optimal_temp){
        if (humidity < critical_humidity){
            printf("Clear day, beautiful day indeed.\n");
        }
        else{
            printf("Expect rain. Take umbrella.\n");
        }
    }
    else if (temp>optimal_temp){
        if (humidity>=critical_humidity){
            printf("Expect rain. Take umbrella.\n");
        }
        else{
            printf("It is a hot day. Take umbrella anyway.\n");
        }
    }
    // C does not support triple comparisons, 0<temp<optimal_temp will throw an error in logic.
    else if (0<temp && temp<optimal_temp){
        if (humidity>=critical_humidity){
            printf("Expect rain, take umbrella.\n");
        }
        else{
            printf("Temperature is lower than optimal. Wear a woolen scarf.\n");
        }
    }
    else if(temp<=0){
        if(humidity>=critical_humidity){
            printf("Snowfall!Take your boots and gloves and make that ugly snowman!<3\n");
        }
        else{
            printf("Sub-zero temperatures. Advised to stay indoors in that cozy sofa chilling with Netflix!\n");
        }
    }
}

int main(){
    float temperature;
    int humidity;
    printf("Enter the expected temperature: ");
    scanf("%f",&temperature);
    printf("Enter the expected humidity: ");
    scanf("%d",&humidity);
    predictWeather(temperature,humidity);
    return 0;
}