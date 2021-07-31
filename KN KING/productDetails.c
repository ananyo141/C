// WAP to display the product information entered by the user.
// include item number, unit price, purchase date(mm/dd/yyyy) in a tabular format.

#include<stdio.h>

/* Can use this idea: first multiply first int to be added with as many 10's as there are in
the second int. Then add it to 2nd int. e.g.: concat(22,40)-->(22*100+40)  */

// Code snippet suggested by Stack Overflow // 
unsigned concatenate(unsigned x, unsigned y){
    unsigned pow = 10;
    while (y >= pow)
        pow *= 10;
    return x * pow + y;
}

struct item_details{
    unsigned int number;
    unsigned int price;
    unsigned long int purchaseDate;
}; typedef struct item_details item_t;

int main(){
    item_t item1;

    // for unsigned int %u, for unsigned char %hhu, add extra l for long. //
    unsigned char month,date,year;

    printf("Enter item number(num only), unit price(start with $), purchase date(mm/dd/yyyy) separated by space: ");
    scanf("%u $%u %hhu/%hhu/%hhu",&item1.number,&item1.price,&month,&date,&year);
    unsigned monthDate=concatenate(month,date);
    unsigned monthDateYear=concatenate(monthDate,year);
    item1.purchaseDate=monthDateYear;
    printf("Item\tUnit Price\tPurchase Date\n");

    // to get concatenate type effect direct printing %d%d%d month,date,year without any space prints the date //
    printf("%u\t$%u\t\t%lu or %u/%u/%u\n",item1.number,item1.price,item1.purchaseDate,month,date,year);

    return 0;
}