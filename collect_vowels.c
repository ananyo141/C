// WAP to find and return vowels from given string.
#include<stdio.h>
#include<string.h>

void collect_vowels(char string[60]){
    char curr_vowels[60];
    char vowels[]="aeiouAEIOU";
    int i=0;
    while (string[i] != '\0'){
        if (strchr(vowels,string[i]) != NULL){
            // Despite best efforts, the strcat is not used, as when accumulator goes out of stack frame
            // it gets overriden by gibberish. Consider improvisation upon further research.
            strcat(curr_vowels,&string[i]);
            printf("The vowel is %c\n",string[i]);
        }
        i++;
    }
    // This printf prints the values in the memory location that is kinda gibberish.
    // printf("The vowels in the string are %s",curr_vowels);
}

int main(){
    char str[60];
    printf("Please enter the string you want to find the vowels of: ");
    scanf("%s",str);
    collect_vowels(str);
    return 0;
}





