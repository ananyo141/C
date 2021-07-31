// WAP to compare two dates and find which one comes first in a calendar.
#include<stdio.h>

struct date_type {
    int date;
    int month;
    int year;
}; typedef struct date_type date_t;

int main(){
    date_t currentDate, bestChoice;
    printf("Enter date 0/0/0 to terminate\n");
    printf("Enter the date, month and year you want to compare(dd/mm/yyyy): ");
    scanf("%d/%d/%d", &currentDate.date, &currentDate.month, &currentDate.year);

    currentDate.date %= 32; currentDate.month %= 13;        // prevent overflow
    bestChoice = currentDate;

    while (1) {
        printf("Enter the date, month and year you want to compare(dd/mm/yyyy): ");
        scanf("%d/%d/%d", &currentDate.date, &currentDate.month, &currentDate.year);
        currentDate.date %= 32; currentDate.month %= 13;

        if (currentDate.year == 0) {
            break;
        }
        if (currentDate.year < bestChoice.year) {
            bestChoice = currentDate; 
        }
        else if (currentDate.year == bestChoice.year){
            if (currentDate.month < bestChoice.month) {
                bestChoice = currentDate;
            }
            else if (currentDate.month == bestChoice.month){
                if (currentDate.date < bestChoice.date) {
                    bestChoice = currentDate;
                }
                else {
                    printf("Same date detected.\n");
                }
            }
        }
    }

    printf("The earliest date is %d/%d/%d\n",bestChoice.date,bestChoice.month,bestChoice.year);

    return 0;
}
