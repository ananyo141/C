// Read and display the item, price and date of purchase from a file
#include <stdio.h>
#define DATE_MAX 30

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: displayReceipt <filename>\n");
        return 1;
    }
    FILE *readfile;
    if ((readfile = fopen(argv[1], "r")) == NULL) {
        printf("Unable to open %s\n", argv[1]);
        return 1;
    }
    // display header
    printf("%-15s%-20s%-20s\n", "Item", "Unit", "Purchase");
    printf("%-15s%-20s%-20s\n", "", "Price", "Date");
    unsigned item, year;
    double price;
    unsigned short date, month;
    char date_formatted[DATE_MAX];

    while(fscanf(readfile, "%u , %lf , %hu / %hu / %u", &item, &price, &month, &date, &year) == 5) {
        sprintf(date_formatted, "%d/%d/%d", month, date, year);
        printf("%-15u$%-19.2f%-20s\n", item, price, date_formatted);
    }
    fclose(readfile);

    return 0;
}
