// WAP to collect the consonants in a given string.
#include <stdio.h>
#include <conio.h>
#include <string.h>

void collectConsonants(char string[]){
    char vowels[]="aeiouAEIOU";
    for (int i=0;i<strlen(string);i++){
        if (strchr(vowels,string[i]) == NULL){
            printf("The consonant in the string is: %c\n",string[i]);
        }
    }
}

int main(){
    char str[20];
    printf("Enter the string you want to find the consonants: ");
    scanf("%s",str);
    collectConsonants(str);
    return 0;
}