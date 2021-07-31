// There are 955 shoes left in a Nike Retail outlet. WAP for the customer to find out if the no. of shoes needed is 
// available in the store, prompt if he wants to place, and deduct from total if he orders.
#include<stdio.h>
#include<conio.h>

/*IMPORTANT NOTE TO THE DEBUGGER:
Despite what the code may suggest, when executed, the program opts the user to enter the order_quantity and Y/N choice
at the same time (e.g, 433Y or 59N etc.) Request Debugging.*/
// EDIT: Somehow, scanning a string array instead of a single character to record the user choice solves the problem.

int checkAvailability(int order_quantity){
    int available_units=955;
    if (order_quantity<=available_units){
        printf("Your order is available, entered order=%d\n",order_quantity);
        char choice[20];
        printf("Place order? Y/N:\n");
        scanf("%s",choice);
        if ((*choice==*"Y") || (*choice==*"y")){
            available_units-=order_quantity;
            printf("Units Left: %d\n",available_units);
            printf("Thank you for your order!\nOrder details: %d shoes.",order_quantity);
            return order_quantity;
        }
        else if((*choice==*"N") || (*choice==*"n")){
            printf("You cancelled the order!\n");
        }
        else{
            printf("You didn't enter a valid choice. Order Cancelled. Please try again.");
        }
    }
    else{
        printf("Sorry, due to high demand stocks are limited. Please try again later!");
    }
}

int main(){
    int order;
    printf("Welcome to the Nike Official Retail store in Kolkata. Please enter your order quantity and let the system check the stocks for you!\n");
    scanf("%d",&order);
    int order_details=checkAvailability(order);
    return 0;
}