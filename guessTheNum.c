// WAP a guessing the number game, and give the player 5 chances.

#include <stdio.h>
int main(){
    int secretNum,guess;
    int guessesTaken = 0;
    int guessesLeft;

    printf("Select the mystery number you want someone to guess: ");
    scanf("%d",&secretNum);
    printf("Enter how many chances you want give the player: ");
    scanf("%d",&guessesLeft);
    int totalGuesses=guessesLeft;

    printf("Guess the secret number: ");
    scanf("%d",&guess);
    
    while((guess != secretNum)&&(guessesLeft>1)){
        guessesLeft--;
        printf("You guessed wrong!\nTry again(Guesses left: %d): ",guessesLeft);
        scanf("%d",&guess);
        guessesTaken++;
    }
    if (guess==secretNum){
        printf("You guessed it in %d tries!",guessesTaken);
    }
    else{
        printf("You just had to guess %d in %d guesses you LOSER! XD",secretNum,totalGuesses);
    }

    return 0;
}
