// Enter the month, day and year (mm/dd/yy) and mention month, date and year.
#include <stdio.h>

int main() {
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", \
                      "September", "October", "November", "December"};
    int month, date, year;
    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d", &month);
    scanf("/%d", &date);
    scanf("/%d", &year);
    printf("You entered the date %s %d, %d\n", months[month - 1], date, year);

    return 0;
}