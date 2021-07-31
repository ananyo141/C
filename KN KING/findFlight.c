// WAP to find the flight nearest to the time entered by the user.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int hoursToMin(int hours, int mins){
    return (hours*60) + mins;
}

// Wanted to put all of them in an array and loop over to avoid the extensive labor of writing
// each one individually, but something like that is already one of my little bugs.
void findNearestFlight(int mins){
    if (mins < hoursToMin(8,00)){
        printf("The closest departure time is: 8:00AM, arriving at 10:16AM\n");
    }
    else if (mins < hoursToMin(9,43)){
        printf("The closest departure time is: 9:43AM, arriving at 11:52AM\n");
    }
    else if (mins < hoursToMin(11,19)){
        printf("The closest departure time is: 11:19AM, arriving at 1:31PM\n");
    }
    else if (mins < hoursToMin(12,47)){
        printf("The closest departure time is: 12:47PM, arriving at 3:00PM\n");
    }
    else if (mins < hoursToMin(12+2,00)){
        printf("The closest departure time is: 2:00PM, arriving at 4:08PM\n");
    }
    else if (mins < hoursToMin(12+3,45)){
        printf("The closest departure time is: 3:45PM, arriving at 5:55PM\n");
    }
    else if (mins < hoursToMin(12+7,00)){
        printf("The closest departure time is: 7:00PM, arriving at 9:20PM\n");
    }
    else if (mins < hoursToMin(12+9,45)){
        printf("The closest departure time is: 9:45PM, arriving at 11:58PM\n");
    }
    else{
        printf("The last flight has departed on 9:45PM. Sorry for the inconvenience.\n");
    }
    
}

int main(){
    int hours, mins, milHours;
    char time[2];
    printf("Enter your time in standard hours(hours:mins{AM/PM}): ");
    scanf("%d:%d%s",&hours,&mins,time);
    if (strcmp(time,"AM") == 0|| strcmp(time,"am") == 0){
        milHours = hours;
    }
    else if (strcmp(time, "PM") == 0 || strcmp(time, "pm") == 0){
        milHours = 12 + hours;
    }
    else{
        printf("Wrong input\n");
        exit(0);
    }
    milHours %= 24;
    int inMins = hoursToMin(milHours,mins);
    findNearestFlight(inMins);

    return 0;
}