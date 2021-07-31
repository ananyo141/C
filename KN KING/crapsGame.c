/* A Game of Craps
Rules: 
On first roll of two die, the player wins if the sum is 7 or 11, loses if 2, 3 or 12.
Any other Roll is called 'Point'.
The game continues until rolls point again and wins or rolls 7 and loses. Others are ignored. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>

// function prototypes
int roll_dice(void);
bool play_game(void);

int main() {
    printf("Welcome to the Game of Craps\n");
    int result, gameCount = 0, wins = 0, loss = 0;
    char choice;
    srand((unsigned)time(NULL));
    do {
        result = play_game();
        if (result) {
            printf("You win!");
            wins++;
        }
        else {
            printf("You lose!");
            loss++;
        }
        gameCount++;

        printf("\nPlay Again?(Y/N): ");
        scanf(" %c", &choice);
        printf("\n");
    } while (tolower(choice) == 'y');

    // display the results
    printf("Wins: %d\tLosses: %d\n", wins, loss);
    printf("Win Percentage: %.2f\n", (wins /(float) gameCount) * 100);

    return 0;
}

int roll_dice(void) {
    int firstDice, secondDice;
    do {
        firstDice = rand() % 7;
        secondDice = rand() % 7;
    } while(!(firstDice && secondDice));    // so that no die has 0
    return firstDice + secondDice;
}

bool play_game(void) {
    int first_roll = roll_dice();
    printf("You rolled: %d\n", first_roll);
    sleep(1); // for dramatic effect

    if (first_roll == 7 || first_roll == 11)
        return true;
    else if (first_roll == 2 || first_roll == 2 || first_roll == 2)
        return false;
    else {
        printf("Your point is %d\n", first_roll);
        for(;;) {
            int roll = roll_dice();
            printf("You rolled: %d\n", roll);
            sleep(1); // for dramatic effect

            if (roll == 7)
                return false;
            else if (roll == first_roll) 
                return true;
        }
    }
}