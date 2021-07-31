// Create a datatype of a movie containing it's attributes like director, actors, actresses, etc.
#include<stdio.h>

struct movie_type {
    char *director; // If want to use an array[] type,
    char *cinematographer;
    int runtime;
    char *actor;
    char *actress;
}; typedef struct movie_type movie_data;

int main(){

    movie_data Arrival;
    Arrival.director="Denis Villeneuve";  // during assignment use strcpy() function from <string.h>
    Arrival.cinematographer="Bradford Young";
    Arrival.runtime=150;
    Arrival.actor="Jeremy Renner";
    Arrival.actress="Amy Adams";
    printf("The director of Arrival is %s, acted by %s and %s.",Arrival.director,Arrival.actor,Arrival.actress);

    return 0;
}
