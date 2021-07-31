// WAP to create a Madlibs game.

#include<stdio.h>
#include<stdlib.h>

int main(){
    char president[20];
    char food[20];
    char celeb[20];
    printf("Who is your favourite president?: ");
    scanf("%s",president);
    printf("What is your favourite food?: ");
    scanf("%s",food);
    printf("What is your favourite celebrity?: ");
    scanf("%s",celeb);
    system("clear");
    printf("%s is red,%s likes violet, I love %s.\n",food,president,celeb);
    return 0;
}


