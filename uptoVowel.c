// WAP to print upto finding a vowel.
#include<stdio.h>
#include<conio.h>
#include<string.h>

void uptoVowel(char string[20]){
    char vowels[]="aeiouAEIOU";
    // This is perhaps the most complex for-loop condition written XD.
    for (int i = 0;((i < strlen(string)) && (strchr(vowels, string[i]) == NULL)); i++){
        printf("%c\n",string[i]);
    }
}

int main(){
    char str[20];
    printf("Enter the string: ");
    scanf("%s",str);
    uptoVowel(str);
    return 0;
}
   