// WAP to compare two dates and find which one comes first in a calendar.
#include<stdio.h>
#include<stdlib.h>

int main(){
    int date1,date2,month1,month2,year1,year2;
    printf("Enter the first date you want to compare(dd/mm/yy): ");
    scanf("%d/%d/%d",&date1,&month1,&year1);
    printf("Enter the second date you want to compare(dd/mm/yy): ");
    scanf("%d/%d/%d", &date2, &month2, &year2);
    date1 %= 32; date2 %=32;
    month1 %= 13; month2 %= 13;
    
    if (date1 == date2 && month1 == month2 && year1 == year2){
        printf("Both are same dates DUMBASS! You don't have to test my intelligence!\n");
        exit(0);
    }
    
    {
    if (year1<year2){
        printf("%d/%d/%d comes before %d/%d/%d\n", date1, month1, year1, date2, month2, year2);
    }
    else {
        printf("%d/%d/%d comes before %d/%d/%d\n", date2, month2, year2, date1, month1, year1);
    }
    exit(0);
    }
    {
    if (month1<month2){
        printf("%d/%d/%d comes before %d/%d/%d\n", date1, month1, year1, date2, month2, year2);
    }
    else {
        printf("%d/%d/%d comes before %d/%d/%d\n", date2, month2, year2, date1, month1, year1);
    }
    exit(0);
    }
    {
    if (date1<date1){
        printf("%d/%d/%d comes before %d/%d/%d\n", date1, month1, year1, date2, month2, year2);
    }
    else {
        printf("%d/%d/%d comes before %d/%d/%d\n", date2, month2, year2, date1, month1, year1);
    }
    exit(0);
    }

    return 0;
}
