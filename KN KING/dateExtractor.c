// Extract the date from the command-line and show in a standard format.
#include <stdio.h>
#define DATE_LEN 50
#define DEBUG(x) printf(#x " = %d\n", x)

// 9/13/2010 or 9-13-2010 as September 13, 2010

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: dateExtractor <mm/dd/yyyy>\n");
        return 1;
    }
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August",
                      "September", "October", "November", "December"};
    char date_formatted[DATE_LEN];
    int day, month, year;
    if (sscanf(argv[1], "%d / %d / %d", &month, &day, &year) == 3) ;
    else if (sscanf(argv[1], "%d - %d - %d", &month, &day, &year) == 3) ;
    else {
        puts("Cannot extract date.\nAvailable formats: <mm/dd/yyyy> and <mm-dd-yyyy>");
        return 1;
    }

    printf("%s %d, %.4d\n", months[month - 1], day, year);

    return 0;
}
