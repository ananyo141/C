// Print a calendar based on the starting day of the month.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Simply abstracted this as a function so that main program looks less cluttered
int dayToNum (char day[]){
    int num;
    // converts the day-string into lowercase for maximum compatibility
    for (int i=0; day[i]; i++){
        day[i] = tolower(day[i]);
    }
    if (strcmp(day,"sunday") == 0) {num = 1;}
    else if (strcmp(day, "monday") == 0) {num = 2;}
    else if (strcmp(day, "tuesday") == 0) {num = 3;}
    else if (strcmp(day, "wednesday") == 0) {num = 4;}
    else if (strcmp(day, "thursday") == 0) {num = 5;}
    else if (strcmp(day, "friday") == 0) {num = 6;}
    else if (strcmp(day, "saturday") == 0) {num = 7;}

    return num;
}

int main(){
    char startingDay[20];
    int numDays;
    printf("Provide the starting day of the month: ");
    scanf("%s", startingDay);
    printf("Enter how many days are in the month: ");
    scanf("%d", &numDays);
    int day = dayToNum(startingDay);
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");   // accounting for 5 character formatting for all

    // prepare leading blank dates
    for (int i = 1; i < day; i++){
        printf("     ");                // 5 characters
    }
    // print the calendar
    for (int i = 1; i <= numDays; i++, day++){
        printf("%5d",i);                // 5 characters
        if ((day) % 7 == 0)
            printf("\n");
    }
    printf("\n");
    
    return 0;
}