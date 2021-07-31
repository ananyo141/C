//WAP to input name, location, year from the user and print it as biodata.

#include<stdio.h>
#include<conio.h>

void bioData(char name[20],char location[20],int year){
    printf("%s lives in %s as of year %d.\n",name,location,year);
}

int main(){
    
    /* This code prints a newline because of fgets(), and the formatting looks awkward.
    char user_name[20], user_location[20];
    int user_year;
    printf("Enter your name: ");
    fgets(user_name,20,stdin);
    printf("Enter your location: ");
    fgets(user_location,20,stdin);
    printf("Enter the current year: ");
    scanf("%d",&user_year);
    bioData(user_name,user_location,user_year);
    */

    //As we are using scanf(), user can only enter one word, as scanf() gets upto the first whitespace.
    char user_name2[20], user_location2[20];
    int user_year2;
    printf("Enter your name: ");
    scanf("%s",user_name2);
    printf("Enter your location: ");
    scanf("%s", user_location2);
    printf("Enter the current year: ");
    scanf("%d",&user_year2);
    bioData(user_name2,user_location2,user_year2);
    
    
    return 0;
}