// Print a month-reminder
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// macro def //
#define MAX_REM 50
#define MAX_CHAR 60
#define DEBUG(x) printf(#x " = %d\n", x)

// function prototypes //
int readline (char *sentence, int arr_size);

// driver function //
int main() {
    int i, j, day, numReminders = 0, time;
    char day_str[3], time_str[3], datetime[8], message[MAX_CHAR];
    char *reminders[MAX_REM];

    for (;;) {

        if (numReminders == MAX_REM) {
            printf("No space left");
            break;
        }

        printf("Enter the day, time and reminder: ");
        scanf ("%2d", &day);
        if (day == 0)
            break;
        scanf("%2d", &time);

        if (day < 0 || day > 31) { 
            printf("Invalid date entered\n");
            continue;
        }

        int msg_len = readline(message, MAX_CHAR);
        // convert day into str
        sprintf(day_str, "%2d", day);
        sprintf(time_str, "%2d", time);
        strcpy(datetime, day_str);
        strcat(datetime, " ");
        strcat(datetime, time_str);

        // find the position to insert the date
        for (i = 0; i < numReminders; i++)
            if (strcmp(datetime, reminders[i]) < 0)
                break;
        // make space to insert the correct date in the array
        for (j = numReminders; j > i; j--) 
            reminders[j] = reminders[j - 1];

        // allocate space for reminder
        reminders[i] = malloc(5 + msg_len + 1);
        if (reminders[i] == NULL) {
            printf("--- No Space Left ---\n");
            exit(EXIT_FAILURE);
        }

        // insert the reminder in position
        strcpy(reminders[i], datetime);
        strcat(datetime, " ");
        strcat(reminders[i], message);

        numReminders++;
    }

    // print the table
    printf("Day Time Reminders\n");
    for (int i = 0; i < numReminders; i++) 
        printf(" %s\n", reminders[i]);

    return 0;     
}

int readline (char *sentence, int arr_size) {
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < arr_size - 2)
            sentence[i++] = ch;
    sentence[i] = '\0';
    return i;
}