// Deal a random hand of card to the player
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_SUITS 4         // club, diamond, spade and heart
#define NUM_RANKS 13        // 2 to 10 and Jack, Queen, King and ACE

int main() {
    bool cardTracker[NUM_SUITS][NUM_RANKS] = {false};
    int num_cards, suit, rank;
    const char rank_code[] = {'2', '3', '4', '5', '6', '7', '8',
                             '9', 't', 'j', 'q', 'k', 'a'};
    const char suit_code[] = {'c', 'd', 'h', 's'};

    srand(time(0));     // initializes the random function

    printf("Enter the number of cards in hand: ");
    scanf("%d", &num_cards);
    printf("Your hand:");

    // loop that randomizes cards, and keeps track of them not to suggest them again
    while (num_cards > 0) {
        suit = rand() % NUM_SUITS;
        rank = rand() % NUM_RANKS;
        if (!cardTracker[suit][rank]) {
            printf("  %c%c", rank_code[rank], suit_code[suit]);
            cardTracker[suit][rank] = true;
            num_cards--;
        }
    }
    printf("\n");

    return 0;
}