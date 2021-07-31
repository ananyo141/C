// Find the nearest flight timings.
#include <stdio.h>
#include <stdlib.h>

int minutesSinceMidnight(int hours,int mins) {
    if (hours<=12){
    return (hours * 60) + mins;
    }
    else{
        return ((hours-12)*60)+mins;
    }
}

int getNearestFlight(int time){
    int timings[8][2]={{ 8, 0 }, { 9, 43 }, { 11, 19 }, { 12, 47 }, \
    { 12 + 2, 0 }, { 12 + 3, 45 }, { 12 + 7, 0 }, { 12 + 9, 45 }};
    int bestChoice = abs (time - minutesSinceMidnight(timings[0][0],timings[0][1]));
    for(int i=0; i<8; i++){
        if (abs(time - minutesSinceMidnight(timings[i][0],timings[i][1])) < bestChoice){
            bestChoice = abs (time - minutesSinceMidnight(timings[i][0],timings[i][1]));
        }
    }
    printf("%d",bestChoice);
    return bestChoice;          // bestChoice is the difference in mins
}


int main(){
    int hours, mins;
    printf("Enter the hours in military hours: ");
    scanf("%d:%d",&hours,&mins);
    int inMins = minutesSinceMidnight(hours,mins);
    int leastWaitingTime = getNearestFlight(inMins);
    int flightTime = inMins + leastWaitingTime;
    printf("%d",flightTime);

    // Convert to standard hours
    int stdHours = 0;
    int stdMins = 0;
    while (flightTime>=60){
        flightTime/=60;
        stdHours++;
    }
    if (flightTime>0){
        stdMins = flightTime % 60;
    }
    printf("The nearest flight is at %.2d:%.2d",stdHours,stdMins);
    
    return 0;
}