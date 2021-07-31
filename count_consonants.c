// WAP to count consonants in a given string.
#include<stdio.h>
#include<conio.h>
#include<string.h>

int countConsonants(char string[20]){
    int curr_count=0;
    char vowels[]="aeiouAEIOU";
    for (int i=0;i<strlen(string);i++){
        if (strchr(vowels,string[i]) == NULL){
            curr_count++;
        }
    }
    return curr_count;
}

int main(){
    char str[20];
    printf("Enter the string you want to calculate the consonants: ");
    scanf("%s",str);
    int num_consonants=countConsonants(str);
    printf("The number of consonants in the given string is %d",num_consonants);
    return 0;
}