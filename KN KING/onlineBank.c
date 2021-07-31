// Write a netbanking program with a command menu.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    char command[20];           
    float balance = 0;
    printf("\n****Online Netbanking****\n\n");
    printf("Commands: clear:Clears your balance, credit:Deposit Money, ");
    printf("debit:Withdraw Money,\nbalance:Display Current Balance, loan:Take a loan, exit:Exit the program\n");
    scanf("%s",command);

    // TODO: Use do-while to make the loop more compact.
    // TODO: Use a loop that changes the user input to lowercase to support any valid user input.

    // Main program loop
    while (strcmp(command,"exit") != 0){
        if ((balance < 0) && (strcmp(command,"balance") != 0)){
            printf("You have an outstanding loan of %.2f. Please repay first.\n", balance);
        }

        if (strcmp(command, "debit") == 0){
            if (balance < 0){
                printf("You have an outstanding loan of %.2f. Please repay first\n", balance);
                goto next;
            }
            float debitAmount;
            printf("Enter the amount you want to debit: ");
            scanf("%f",&debitAmount);
            if (debitAmount>balance){
                printf("Insufficient balance");
                goto next;  
            }
            balance -= debitAmount;
            printf("Amount Debited: %.2f",debitAmount);
            goto next;
        }
        else if (strcmp(command, "balance") == 0){
            printf("Current Account Balance: %.2f",balance);
            goto next;
        }
        else if (strcmp(command, "clear") == 0){
            balance = 0;
            goto next;
        }
        else if (strcmp(command, "credit") == 0){
            float creditAmount;
            printf("Enter the credit amount: ");
            scanf("%f",&creditAmount);
            balance += creditAmount;
            goto next;
        }
        // Add interest per cycle of loop 6%, don't debit further until loan is repaid
        else if(strcmp(command, "loan") == 0){
            float loanAmount;
            
            if (balance > 0){
                printf("You are eligible for %.2f loan according to your credit score\n", balance * 3);
                printf("Enter how much you want to take a loan(interest per withdraw is 6%%): ");
                scanf("%f", &loanAmount);
                if (loanAmount <= (balance * 3)){
                    char choice[5];
                    printf("Confirm your loan amount: %.2f\nYou won't be able to further debit until you repay your loan\n", loanAmount);
                    printf("Confirm(Y/N): ");
                    scanf("%s",choice);
                    if (strcmp(choice,"y") == 0 || strcmp(choice,"yes") == 0){
                        balance -= loanAmount;
                        printf("Your application for %.2f loan was processed successfully.", loanAmount);
                    }
                    else{
                        printf("You cancelled the loan");
                    }
                    goto next;
                }
                else{
                    printf("Requested amount is over your credit limit");
                    goto next;
                }
            }
            else{
                printf("You don't have sufficient balance to be eligible for a loan");
                goto next;
            }
        }
        else {
            printf("Invalid Input");
        }

        next:
        if (balance < 0){
            balance -= abs(balance) * 0.06f;
        }
        printf("\n------------------------------");
        printf("\nProcessing... Validating with Server...\n");
        sleep(1);
        printf("Commands: clear:Clears your balance, credit:Deposit Money, ");
        printf("debit:Withdraw Money,\nbalance:Display Current Balance, loan:Take a loan, exit:Exit the program\n");
        scanf("%s", command);
    }

    printf("Thanks for using our online portal. Visit your nearest branch for any discrepancies.\n");
    
    return 0;
}