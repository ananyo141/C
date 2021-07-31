// Convert standard to military hours
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main() {
    int hour, min;
    bool isPM = false;
    printf("Enter the time in standard hours: ");
    scanf("%d:%d", &hour, &min);
    if (tolower(getchar()) == 'p') {
        if (hour != 12) {
        hour += 12;
        }
        isPM = true;        // isPM is true if 'pm'
    }
    
    hour %= 24;
    min %= 60;
    printf("The hours in military hours is: %d:%.2d hours\n", (hour == 12 && !isPM ? 0 : hour), min); // if hours is 12 and isPM is not true i.e, 'am'

    return 0;
}