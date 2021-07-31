/* WAP to analyze the ISBN to break down sequentially:
GSI PREFIX, GROUP IDENTIFIER, PUBLISHER CODE, ITEM NUMBER, CHECK DIGIT */
#include<stdio.h>

int main(){
    unsigned short gsiPre,grpID,pubCode,checkDigit;
    unsigned int itemNum;
    printf("Enter the ISBN number you want to analyze: ");
    scanf("%hd-%hd-%hd-%u-%hd",&gsiPre,&grpID,&pubCode,&itemNum,&checkDigit);
    printf("GSI PREFIX: %u\n",gsiPre);
    printf("GROUP IDENTIFIER: %u\n",grpID);
    printf("PUBLISHER CODE: %u\n",pubCode);
    printf("ITEM NUMBER: %u\n",itemNum);
    printf("CHECK DIGIT: %u\n",checkDigit);

    return 0;
}
