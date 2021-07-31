// WAP to count number of vowels in given string.
// Precondition: The strings entered should be one word or no_space.
#include<stdio.h>
#include<conio.h>
#include<string.h>

//Used two new functions in the string.h library: strlen() and strchr()
//Also can use while(string[i] != '\0') to loop until the end of string.
int count_vowels(char string[]){
    int curr_count=0;
    char vowels[]="aeiouAEIOU";
    for(int i=0;i<strlen(string);i++){
        if (strchr(vowels,string[i]) != NULL){
            curr_count++;
        }
    }
    return curr_count;
}

int main(){
    char string[20];
    printf("Please enter the string: ");
    scanf("%s",string);
    int vowNum=count_vowels(string);
    printf("The number of vowels is %d in the given string.",vowNum);
    return 0;
}

