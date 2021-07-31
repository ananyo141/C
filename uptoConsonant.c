// WAP to keep printing until a consonant is encountered.
#include<stdio.h>
#include<conio.h>
#include<string.h>

void uptoConsonant(char string[20]){
    char vowels[]="aeiouAEIOU";
    for(int i=0;((i<strlen(string)) && (strchr(vowels,string[i]) != NULL)); i++){
        printf("%c\n",string[i]);
    }
}

int main(){
    char str[20];
    printf("Enter the string: ");
    scanf("%s",str);
    uptoConsonant(str);
    return 0;
}